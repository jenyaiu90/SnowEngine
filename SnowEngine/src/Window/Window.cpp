    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Window.cpp                  //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief The file with the definition of the Window class.
///
///	In this file there is the definition of the methods of the Window class.
////////////////////////////////////////////////////////////

#include "Window.h"
#include "../Types/List/ArrayList.h"
#include <iostream>

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
	sf::Clock clock;
	while (window_->isOpen())
	{
		int delta = clock.restart().asMilliseconds();

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

		windowMutex_.lock();

		window_->clear();
		if (level_ != nullptr)
		{
			level_->tick(delta, *window_);
		}

		if (guis_.startIterate())
		{
			do
			{
				guis_.getIterator()->tick(delta, *window_);
			} while (guis_.iterateNext());
			guis_.stopIterate();
		}

		window_->display();

		windowMutex_.unlock();
	}
}