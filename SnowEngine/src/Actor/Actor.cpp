    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Actor.cpp                   //
////////////////////////////////////////

#include "Actor.h"

// Definition of the constructor is in Layer.cpp.

snow::Actor::~Actor()
{
	std::lock_guard<std::mutex> lock(componentsMutex_);
	if (components_.startIterate())
	{
		do
		{
			if (components_.getIterator() != nullptr)
			{
				delete components_.getIterator();
			}
		} while (components_.iterateNext());
		components_.stopIterate();
	}
}

void snow::Actor::tick(const int& delta, sf::RenderWindow& window)
{
	if (speed_ != snow::Vector2f(0.f, 0.f))
	{
		snow::Vector2f newPos = position_ + speed_ * delta;
		if (destination != nullptr &&
			(((destination->x - position_.x < 0) ^ (destination->x - newPos.x < 0)) ||
			((destination->y - position_.y < 0) ^ (destination->y - newPos.y < 0))))
		{
			setPosition(*destination);
			delete destination;
			speed_ = snow::Vector2f(0.f, 0.f);
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

// Definition of the getLayer() method is in Layer.cpp.

snow::Vector2f snow::Actor::getPosition() const
{
	return position_;
}

void snow::Actor::move(snow::Vector2f to, int time)
{
	if (time == 0)
	{
		setPosition(to);
	}
	else
	{
		speed_ = (to - position_) / time;
		if (destination != nullptr)
		{
			delete destination;
		}
		destination = new snow::Vector2f(to);
	}
}

void snow::Actor::setPosition(Vector2f position)
{
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
	this->position_ = position;
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
	position_(pos),
	actor_(actor)
{
	actor->attachComponent(this);
}

snow::Vector2f snow::Component::getWorldPosition() const
{
	return actor_->getPosition() + position_;
}

snow::Actor* snow::Component::getActor()
{
	return actor_;
}