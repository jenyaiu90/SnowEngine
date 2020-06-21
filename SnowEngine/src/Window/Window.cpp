    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Window.cpp                  //
////////////////////////////////////////

#include "Window.h"
#include "../Types/List/ArrayList.h"
#include <iostream>
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
	std::thread windowThread(&snow::Window::startWindow, this, title, resolution, isFullscreen);
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
	level_ = &level;
	return true;
}

bool snow::Window::attach(Gui& gui)
{
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

void snow::Window::startWindow(const std::string& title, const Vector2i& resolution,
							   bool isFullscreen)
{
	window_ = new sf::RenderWindow(sf::VideoMode(resolution_.x, resolution_.y), title_);
	levelView_ = window_->getView();
	guisView_ = window_->getView();
	windowCycle();
}

void snow::Window::windowCycle()
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
				levelView_.setSize(sf::Vector2f(event.size.width, event.size.height));
				guisView_.setSize(sf::Vector2f(event.size.width, event.size.height));
				break;
			}
			case sf::Event::EventType::KeyPressed:
			{
				if (input_.keyPressed != nullptr)
				{
					input_.keyPressed(event.key);
				}
				break;
			}
			case sf::Event::EventType::KeyReleased:
			{
				if (input_.keyReleased != nullptr)
				{
					input_.keyReleased(event.key);
				}
				break;
			}
			case sf::Event::EventType::MouseButtonPressed:
			{
				if (input_.mouseButtonPressed != nullptr)
				{
					input_.mouseButtonPressed(event.mouseButton.button,
											  Vector2f(event.mouseButton.x, event.mouseButton.y));
				}
				break;
			}
			case sf::Event::EventType::MouseButtonReleased:
			{
				if (input_.mouseButtonReleased != nullptr)
				{
					input_.mouseButtonReleased(event.mouseButton.button,
											  Vector2f(event.mouseButton.x, event.mouseButton.y));
				}
				break;
			}
			case sf::Event::EventType::MouseWheelScrolled:
			{
				if (input_.mouseWheelScrolled != nullptr)
				{
					input_.mouseWheelScrolled(event.mouseWheel.delta,
											  Vector2f(event.mouseWheel.x, event.mouseWheel.y));
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

		std::lock_guard<std::mutex> lock(windowMutex_);

		window_->clear();
		if (level_ != nullptr)
		{
			window_->setView(levelView_);
			level_->tick(delta, *window_);
			levelView_.move(-0.001, 0);
		}

		//guisMutex_ zone
		{
			std::lock_guard<std::mutex> lock(guisMutex_);
			if (guis_.startIterate())
			{
				window_->setView(guisView_);
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