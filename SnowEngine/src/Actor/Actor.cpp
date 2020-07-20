    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Actor.cpp                   //
////////////////////////////////////////

#include "Actor.h"

// Definition of the constructor is in Layer.cpp.

// Definition of the destructor is in Layer.cpp.

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
			destination = nullptr;
			speed_ = snow::Vector2f(0.f, 0.f);
		}
		else
		{
			setPosition(newPos);
		}
	}

	// Goto was here. But I got rid of it!
	// goto R.I.P. 2020-2020
	std::lock_guard<std::recursive_mutex> lock(componentsMutex_);
	for (auto i = components_.begin(); i != components_.end(); i++)
	{
		if (*i != nullptr)
		{
			(*i)->tick(delta, window);
		}
		else
		{
			i = components_.remove(i);
			i--;
		}
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
	std::lock_guard<std::recursive_mutex> lock(componentsMutex_);
	for (auto i = components_.begin(); i != components_.end(); i++)
	{
		if (*i != nullptr)
		{
			(*i)->actorMove(position);
		}
		else
		{
			i = components_.remove(i);
			i--;
		}
	}
	this->position_ = position;
}

bool snow::Actor::attachComponent(snow::Component* component)
{
	std::lock_guard<std::recursive_mutex> lock(componentsMutex_);
	components_.add(component);
	return true;
}

bool snow::Actor::detachComponent(Component* component)
{
	std::lock_guard<std::recursive_mutex> lock(componentsMutex_);
	int id = components_.find(component);
	if (id >= 0)
	{
		components_.remove(id);
	}
	return id >= 0;
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

snow::Component::~Component()
{
	actor_->detachComponent(this);
}

snow::Vector2f snow::Component::getWorldPosition() const
{
	return actor_->getPosition() + position_;
}

snow::Actor* snow::Component::getActor()
{
	return actor_;
}