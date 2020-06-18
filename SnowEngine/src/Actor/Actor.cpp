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
			((destination->x - position.x < 0 ^ destination->x - newPos.x < 0) ||
			(destination->y - position.y < 0 ^ destination->y - newPos.y < 0)))
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

	if (components_.startIterate())
	{
		do
		{
			if (components_.getIterator() != nullptr)
			{
				components_.getIterator()->tick(delta, window);
			}
			else
			{
				components_.remove(components_.getIteratorPosition());
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
	if (components_.startIterate())
	{
		do
		{
			if (components_.getIterator() != nullptr)
			{
				components_.getIterator()->actorMove(position);
			}
			else
			{
				components_.remove(components_.getIteratorPosition());
			}
		} while (components_.iterateNext());
		components_.stopIterate();
	}
}

bool snow::Actor::attachComponent(snow::Component* component)
{
	components_.add(component);
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