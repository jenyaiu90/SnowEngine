    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Layer.cpp                   //
////////////////////////////////////////

#include "Layer.h"

snow::Layer::Layer() :
	zoomFactor_(1.f),
	isActive_(true),
	isClickable_(true)
{
}

snow::Layer::~Layer()
{
}

void snow::Layer::tick(const int& delta, sf::RenderWindow& window)
{
	if (isActive_)
	{
		std::lock_guard<std::mutex> lock(actorsMutex_);
		for (auto i = actors_.begin(); i != actors_.end(); i++)
		{
			if (*i != nullptr)
			{
				(*i)->tick(delta, window);
			}
			else
			{
				i = actors_.remove(i);
				i--;
			}
		}

		if (followed_ != nullptr)
		{
			view_.setCenter(followed_->getPosition());
		}
	}
}

void snow::Layer::onAttaching(snow::Vector2f size)
{
	windowSize_ = size;
	view_.setSize(static_cast<sf::Vector2f>(size * zoomFactor_));
	view_.setCenter(static_cast<sf::Vector2f>(size / 2));
}

bool snow::Layer::spawnActor(snow::Actor* actor)
{
	std::lock_guard<std::mutex> lock(actorsMutex_);
	return actors_.add(actor);
}

bool snow::Layer::detachActor(Actor* actor)
{
	actorsMutex_.lock();
	int id = actors_.find(actor);
	if (id >= 0)
	{
		actors_.remove(id);
	}
	actorsMutex_.unlock();
	return id >= 0;
}

float snow::Layer::zoom(float factor)
{
	setZoom(factor * zoomFactor_);
	return getZoom();
}

void snow::Layer::setZoom(float factor)
{
	zoomFactor_ = factor;
	view_.setSize(static_cast<sf::Vector2f>(windowSize_ * factor));
}

float snow::Layer::getZoom()
{
	return zoomFactor_;
}

snow::Vector2f snow::Layer::move(snow::Vector2f delta)
{
	view_.move(static_cast<sf::Vector2f>(delta));
	return getCenter();
}

void snow::Layer::setCenter(snow::Vector2f center)
{
	followed_ = nullptr;
	view_.setCenter(static_cast<sf::Vector2f>(center));
}

snow::Vector2f snow::Layer::getCenter()
{
	return view_.getCenter();
}

void snow::Layer::windowResize(snow::Vector2f size)
{
	windowSize_ = size;
	view_.setSize(static_cast<sf::Vector2f>(windowSize_ * zoomFactor_));
}

snow::LinkedList<snow::ClickableComponent*>& snow::Layer::getClickables()
{
	return clickables_;
}

void snow::Layer::follow(const Actor* actor)
{
	followed_ = actor;
}

bool snow::Layer::isActive() const
{
	return isActive_;
}

void snow::Layer::setActive(bool active)
{
	isActive_ = active;
}

bool snow::Layer::isClickable() const
{
	return isClickable_;
}

void snow::Layer::setClickable(bool clickable)
{
	isClickable_ = clickable;
}

/////////////
//  Actor  //
/////////////

snow::Actor::Actor(Layer* layer, Vector2f pos) :
	position_(pos),
	components_(),
	layer_(layer)
{
	layer->spawnActor(this);
}

snow::Actor::~Actor()
{
	layer_->detachActor(this);
}

snow::Layer* snow::Actor::getLayer()
{
	return layer_;
}

//////////////////////////
//  ClickableComponent  //
//////////////////////////

snow::ClickableComponent::ClickableComponent(snow::Actor* actor,
											 snow::Vector2f size, snow::Vector2f pos) :
	snow::Component(actor, pos),
	size_(size)
{
	actor->getLayer()->getClickables().add(this);
}