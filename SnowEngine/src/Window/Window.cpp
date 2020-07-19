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

sf::RenderWindow* snow::Window::getWindow()
{
	return window_;
}

snow::Input* snow::Window::getInput()
{
	return &input_;
}

void snow::Window::join()
{
	while (window_->isOpen());
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
					return;
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
						for (auto i = guis_.begin(); i != guis_.end(); i++)
						{
							if (*i != nullptr)
							{
								(*i)->windowResize(static_cast<Vector2f>(resolution_));
							}
							else
							{
								i = guis_.remove(i);
							}
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
					if (!InputComponent::thereIsActive() &&
						input_.keyReleased != nullptr)
					{
						input_.keyReleased(event.key);
					}
					break;
				}
				case sf::Event::EventType::MouseButtonPressed:
				case sf::Event::EventType::MouseButtonReleased:
				{
					ClickableComponent::Event clickableEvent;
					std::function<void(MouseButton button, Vector2f position)> post;
					switch (event.type)
					{
					case sf::Event::EventType::MouseButtonPressed:
					{
						clickableEvent = ClickableComponent::MOUSE_PRESSED;
						InputComponent::deactivate();
						post = input_.mouseButtonPressed;
						break;
					}
					case sf::Event::EventType::MouseButtonReleased:
					{
						clickableEvent = ClickableComponent::MOUSE_RELEASED;
						post = input_.mouseButtonReleased;
						break;
					}
					}
					Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
					bool clicked = false;

					// guisMutex_ zone
					{
						std::lock_guard<std::mutex> lock(guisMutex_);
						for (auto i = guis_.begin(); i != guis_.end(); i++)
						{
							if (*i != nullptr)
							{
								Vector2f layerMousePosition(mousePosition.x + (*i)->getCenter().x -
															0.5f * (*i)->getZoom() * resolution_.x,

															mousePosition.y + (*i)->getCenter().y -
															0.5f * (*i)->getZoom() * resolution_.y);
								for (auto j = (*i)->getClickables().begin();
									 j != (*i)->getClickables().end(); j++)
								{
									if (*j != nullptr										&&
										layerMousePosition.x >= (*j)->getWorldPosition().x	&&
										layerMousePosition.x <= (*j)->getWorldPosition().x +
																(*j)->getSize().x			&&
										layerMousePosition.y >= (*j)->getWorldPosition().y	&&
										layerMousePosition.y <= (*j)->getWorldPosition().y +
																(*j)->getSize().y)
									{
										(*j)->event(clickableEvent,
													event.mouseButton.button,
													mousePosition);
										clicked = true;
										break;
									}
								}
							}
						}
					}

					if (!clicked && level_ != nullptr)
					{
						Vector2f layerMousePosition(mousePosition.x + level_->getCenter().x -
													0.5f * level_->getZoom() * resolution_.x,

													mousePosition.y + level_->getCenter().y -
													0.5f * level_->getZoom() * resolution_.y);
								for (auto j = level_->getClickables().begin();
									 j != level_->getClickables().end(); j++)
								{
									if (*j != nullptr										&&
										layerMousePosition.x >= (*j)->getWorldPosition().x	&&
										layerMousePosition.x <= (*j)->getWorldPosition().x +
																(*j)->getSize().x			&&
										layerMousePosition.y >= (*j)->getWorldPosition().y	&&
										layerMousePosition.y <= (*j)->getWorldPosition().y +
																(*j)->getSize().y)
									{
										(*j)->event(clickableEvent,
													event.mouseButton.button,
													mousePosition);
										clicked = true;
										break;
									}
								}
					}

					if (post != nullptr)
					{
						post(event.mouseButton.button, Vector2f());
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
			for (auto i = guis_.begin(); i != guis_.end(); i++)
			{
				if (*i != nullptr)
				{
					(*i)->tick(delta, *window_);
				}
				else
				{
					i = guis_.remove(i);
					i--;
				}
			}
		}

		window_->display();
	}
}