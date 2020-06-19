    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Actor.cpp                   //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
/// \brief The file for the Actor class.
///	
///	This file contains the definition of the methods of the Actor class.
////////////////////////////////////////////////////////////

#include "Actor.h"

// Definition of the constructor is in Layer.cpp.

void snow::Actor::tick(const int& delta, sf::RenderWindow& window)
{
	if (speed != snow::Vector2f(0.f, 0.f))
	{
		snow::Vector2f newPos = position + speed * delta;
		if (destination != nullptr &&
			(((destination->x - position.x < 0) ^ (destination->x - newPos.x < 0)) ||
			((destination->y - position.y < 0) ^ (destination->y - newPos.y < 0))))
		{
			setPosition(*destination);
			delete destination;
			speed = snow::Vector2f(0.f, 0.f);
		}
		else
		{
			setPosition(newPos);
		}
	}

	std::lock_guard<std::mutex> lock(componentsMutex_);
	if (components_.startIterate())
	{
	try_again:; // Yes, I know that goto is bad :-/
		do
		{
			if (components_.getIterator() != nullptr)
			{
				components_.getIterator()->tick(delta, window);
			}
			else
			{
				if (components_.getIteratorPosition() == 0)
				{
					components_.removeIterator();
					if (components_.startIterate())
					{
						// If the first element was removed, the loop starts again
						goto try_again; // I think here goto isn`t so bad
					}
					else
					{
						break;
					}
				}
				else
				{
					components_.removeIterator();
				}
			}
		} while (components_.iterateNext());
		components_.stopIterate();
	}
}

snow::Vector2f snow::Actor::getPosition()
{
	return position;
}

void snow::Actor::move(snow::Vector2f to, int time)
{
	if (time == 0)
	{
		setPosition(to);
	}
	else
	{
		speed = (to - position) / time;
		if (destination != nullptr)
		{
			delete destination;
		}
		destination = new snow::Vector2f(to);
	}
}

void snow::Actor::setPosition(Vector2f position)
{
	this->position = position;
	std::lock_guard<std::mutex> lock(componentsMutex_);
	if (components_.startIterate())
	{
	try_again:; // Yes, I used goto
		do
		{
			if (components_.getIterator() != nullptr)
			{
				components_.getIterator()->actorMove(position);
			}
			else
			{
				if (components_.getIteratorPosition() == 0)
				{
					components_.removeIterator();
					if (components_.startIterate())
					{
						// If the first element was removed, the loop starts again
						goto try_again; // This goto goes to the start of the loop
					}
					else
					{
						break;
					}
				}
				else
				{
					components_.removeIterator();
				}
			}
		} while (components_.iterateNext());
		components_.stopIterate();
	}
}

bool snow::Actor::attachComponent(snow::Component* component)
{
	componentsMutex_.lock();
	components_.add(component);
	componentsMutex_.unlock();
	return true;
}

/////////////////
//  Component  //
/////////////////

snow::Component::Component(snow::Actor* actor, snow::Vector2f pos) :
	position(pos)
{
	actor->attachComponent(this);
	actor_ = actor;
}

snow::Vector2f snow::Component::getWorldPosition()
{
	return actor_->getPosition() + position;
}