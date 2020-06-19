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

	delete level_;
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

///////////////
// protected //
///////////////

void snow::Window::startWindow(const std::string& title, const Vector2i& resolution,
							   bool isFullscreen)
{
	window_ = new sf::RenderWindow(sf::VideoMode(resolution_.x, resolution_.y), title_);
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
			if (event.type == sf::Event::Closed)
			{
				windowMutex_.lock();
				if (window_->isOpen())
				{
					window_->close();
				}
				windowMutex_.unlock();
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