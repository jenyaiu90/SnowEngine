    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Window.cpp                  //
////////////////////////////////////////

#include "Window.h"
#include <chrono>
#include <thread>

////////////
// public //
////////////

snow::Window::Window(const std::string& title, const Vector2i& resolution, bool isFullscreen) :
	title_(title),
	resolution_(resolution),
	isFullscreen_(isFullscreen)
{
	std::thread windowThread(&Window::startWindow_, this, title, resolution, isFullscreen);
	windowThread.detach();
}

snow::Window::~Window()
{
	windowMutex_.lock();
	if (window_ != nullptr && window_->isOpen())
	{
		window_->close();
	}
	windowMutex_.unlock();

	if (level_ != nullptr)
	{
		delete level_;
	}
	std::lock_guard<std::mutex> lock(guisMutex_);
	if (guis_.startIterate())
	{
		do
		{
			if (guis_.getIterator() != nullptr)
			{
				delete guis_.getIterator();
			}
		} while (guis_.iterateNext());
		guis_.stopIterate();
	}
	delete window_;
}

bool snow::Window::attach(Level& level, bool safeMode)
{
	if (level_ != nullptr)
	{
		if (safeMode)
		{
			return false;
		}
		else
		{
			delete level_;
		}
	}
	level.onAttaching(resolution_);
	level_ = &level;
	return true;
}

bool snow::Window::attach(Gui& gui)
{
	gui.onAttaching(resolution_);
	return guis_.add(&gui, *Gui::getPointerComparator());
}

sf::RenderWindow * snow::Window::getWindow()
{
	return window_;
}

snow::Input* snow::Window::getInput()
{
	return &input_;
}

///////////////
// protected //
///////////////

void snow::Window::startWindow_(const std::string& title, const Vector2i& resolution,
							   bool isFullscreen)
{
	if (isFullscreen)
	{
		window_ = new sf::RenderWindow(sf::VideoMode(resolution_.x, resolution_.y), 
									   title_, sf::Style::Fullscreen);
	}
	else
	{
		window_ = new sf::RenderWindow(sf::VideoMode(resolution_.x, resolution_.y), title_);
	}
	windowCycle_();
}

void snow::Window::windowCycle_()
{
	auto first_time = std::chrono::system_clock::now();
	auto second_time = first_time;
	while (window_->isOpen())
	{
		second_time = std::chrono::system_clock::now();
		int delta = static_cast<int>((second_time - first_time).count()) / 10000;
		first_time = second_time;

		sf::Event event;
		while (window_->pollEvent(event))
		{
			if (event.type == sf::Event::TextEntered && InputComponent::thereIsActive())
			{
				if (event.text.unicode < 128)
				{
					InputComponent::inputToActive(static_cast<char>(event.text.unicode));
				}
			}
			else
			{
				switch (event.type)
				{
				case sf::Event::Closed:
				{
					windowMutex_.lock();
					if (window_->isOpen())
					{
						window_->close();
					}
					windowMutex_.unlock();
					break;
				}
				case sf::Event::EventType::Resized:
				{
					resolution_ = Vector2i(event.size.width, event.size.height);

					if (level_ != nullptr)
					{
						level_->windowResize(static_cast<Vector2f>(resolution_));
					}

					// guisMutex_ zone
					{
						std::lock_guard<std::mutex> lock(guisMutex_);
						if (guis_.startIterate())
						{
							do
							{
								if (guis_.getIterator() != nullptr)
								{
									guis_.getIterator()->windowResize(
										static_cast<Vector2f>(resolution_));
								}
							} while (guis_.iterateNext());
						}
					}

					break;
				}
				case sf::Event::EventType::KeyPressed:
				{
					if (InputComponent::thereIsActive())
					{
						/*if (event.key.code == sf::Keyboard::BackSpace)
						{
							InputComponent::inputToActive('\b');
						}*/
					}
					else
					{
						if (input_.keyPressed != nullptr)
						{
							input_.keyPressed(event.key);
						}
					}
					break;
				}
				case sf::Event::EventType::KeyReleased:
				{
					if (!InputComponent::thereIsActive &&
						input_.keyReleased != nullptr)
					{
						input_.keyReleased(event.key);
					}
					break;
				}
				case sf::Event::EventType::MouseButtonPressed:
				{
					InputComponent::deactivate();
					Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
					bool clicked = false;

					// guisMutex_ zone
					{
						std::lock_guard<std::mutex> lock(guisMutex_);
						if (guis_.startIterate())
						{
							do
							{
								if (guis_.getIterator() != nullptr &&
									guis_.getIterator()->getClickables().startIterate())
								{
									Vector2f layerMousePosition(
										mousePosition.x + guis_.getIterator()->getCenter().x -
										0.5f * guis_.getIterator()->getZoom() * resolution_.x,
										mousePosition.y + guis_.getIterator()->getCenter().y -
										0.5f * guis_.getIterator()->getZoom() * resolution_.y);
									do
									{
										ClickableComponent* clickable = guis_.getIterator()->
											getClickables().getIterator();
										if (clickable->onMousePressed != nullptr				&&
											clickable != nullptr								&&
											layerMousePosition.x >=
												clickable->getWorldPosition().x					&&
											layerMousePosition.x <=
												clickable->getWorldPosition().x				+
												clickable->getSize().x							&&
											layerMousePosition.y >=
												clickable->getWorldPosition().y					&&
											layerMousePosition.y <=
												clickable->getWorldPosition().y				+
												clickable->getSize().y)
										{
											clickable->onMousePressed(event.mouseButton.button,
																	  mousePosition);
											clicked = true;
											break;
										}
									} while (guis_.getIterator()->getClickables().iterateNext());
									guis_.getIterator()->getClickables().stopIterate();
								}
							} while (guis_.iterateNext() && !clicked);
							guis_.stopIterate();
						}
					}

					if (!clicked && level_ != nullptr && level_->getClickables().startIterate())
					{
						Vector2f layerMousePosition(
							mousePosition.x + level_->getCenter().x -
							0.5f * level_->getZoom() * resolution_.x,
							mousePosition.y + level_->getCenter().y -
							0.5f * level_->getZoom() * resolution_.y);
						do
						{
							ClickableComponent* clickable = level_->getClickables().getIterator();
							if (clickable->onMousePressed != nullptr					&&
								clickable != nullptr									&&
								layerMousePosition.x >= clickable->getWorldPosition().x &&
								layerMousePosition.x <= clickable->getWorldPosition().x +
								clickable->getSize().x				&&
								layerMousePosition.y >= clickable->getWorldPosition().y &&
								layerMousePosition.y <= clickable->getWorldPosition().y +
								clickable->getSize().y)
							{
								clickable->onMousePressed(event.mouseButton.button, mousePosition);
								clicked = true;
								break;
							}
						} while (level_->getClickables().iterateNext());
						level_->getClickables().stopIterate();
					}

					if (input_.mouseButtonPressed != nullptr)
					{
						input_.mouseButtonPressed(event.mouseButton.button,
												  Vector2f());
					}
					break;
				}
				case sf::Event::EventType::MouseButtonReleased:
				{
					Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
					bool clicked = false;
					// guisMutex_ zone
					{
						std::lock_guard<std::mutex> lock(guisMutex_);
						if (guis_.startIterate())
						{
							do
							{
								if (guis_.getIterator() != nullptr &&
									guis_.getIterator()->getClickables().startIterate())
								{
									Vector2f layerMousePosition(
										mousePosition.x + guis_.getIterator()->getCenter().x -
										0.5f * guis_.getIterator()->getZoom() * resolution_.x,
										mousePosition.y + guis_.getIterator()->getCenter().y -
										0.5f * guis_.getIterator()->getZoom() * resolution_.y);
									do
									{
										ClickableComponent* clickable = guis_.getIterator()->
											getClickables().getIterator();
										if (clickable->onMouseReleased != nullptr				&&
											clickable != nullptr						 		&&
											layerMousePosition.x >=
												clickable->getWorldPosition().x					&&
											layerMousePosition.x <=
												clickable->getWorldPosition().x				+
												clickable->getSize().x							&&
											layerMousePosition.y >=
												clickable->getWorldPosition().y					&&
											layerMousePosition.y <=
												clickable->getWorldPosition().y				+
												clickable->getSize().y)
										{
											clickable->onMouseReleased(event.mouseButton.button,
																	   mousePosition);
											clicked = true;
											break;
										}
									} while (guis_.getIterator()->getClickables().iterateNext());
									guis_.getIterator()->getClickables().stopIterate();
								}
							} while (guis_.iterateNext() && !clicked);
							guis_.stopIterate();
						}
					}

					if (!clicked && level_ != nullptr && level_->getClickables().startIterate())
					{
						Vector2f layerMousePosition(
							mousePosition.x + level_->getCenter().x -
							0.5f * level_->getZoom() * resolution_.x,
							mousePosition.y + level_->getCenter().y -
							0.5f * level_->getZoom() * resolution_.y);
						do
						{
							ClickableComponent* clickable = level_->getClickables().getIterator();
							if (clickable->onMouseReleased != nullptr					&&
								clickable != nullptr									&&
								layerMousePosition.x >= clickable->getWorldPosition().x &&
								layerMousePosition.x <= clickable->getWorldPosition().x +
								clickable->getSize().x									&&
								layerMousePosition.y >= clickable->getWorldPosition().y &&
								layerMousePosition.y <= clickable->getWorldPosition().y +
								clickable->getSize().y)
							{
								clickable->onMouseReleased(event.mouseButton.button,
														   mousePosition);
								clicked = true;
								break;
							}
						} while (level_->getClickables().iterateNext());
						level_->getClickables().stopIterate();
					}

					if (input_.mouseButtonReleased != nullptr)
					{
						input_.mouseButtonReleased(event.mouseButton.button,
												   Vector2f(event.mouseButton.x,
															event.mouseButton.y));
					}
					break;
				}
				case sf::Event::EventType::MouseWheelScrolled:
				{
					if (input_.mouseWheelScrolled != nullptr)
					{
						input_.mouseWheelScrolled(event.mouseWheel.delta,
												  Vector2f(event.mouseWheel.x,
														   event.mouseWheel.y));
					}
					break;
				}
				case sf::Event::EventType::MouseMoved:
				{
					if (input_.mouseMoved != nullptr)
					{
						input_.mouseMoved(Vector2f(event.mouseMove.x, event.mouseMove.y));
					}
					break;
				}
				}
			}
		}

		std::lock_guard<std::mutex> lock(windowMutex_);

		window_->clear();
		if (level_ != nullptr)
		{
			level_->tick(delta, *window_);
		}

		//guisMutex_ zone
		{
			std::lock_guard<std::mutex> lock(guisMutex_);
			if (guis_.startIterate())
			{
			try_again:; // I know that goto is bad, but here...
				do
				{
					if (guis_.getIterator() != nullptr)
					{
						guis_.getIterator()->tick(delta, *window_);
					}
					else
					{
						if (guis_.getIteratorPosition() == 0)
						{
							guis_.removeIterator();
							if (guis_.startIterate())
							{
								// If the first element was removed, the loop starts again
								goto try_again; // Don`t hit me!
							}
							else
							{
								break;
							}
						}
						else
						{
							guis_.removeIterator();
						}
					}
				} while (guis_.iterateNext());
				guis_.stopIterate();
			}
		}

		window_->display();
	}
}