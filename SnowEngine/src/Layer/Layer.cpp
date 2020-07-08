    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Layer.cpp                   //
////////////////////////////////////////

#include "Layer.h"

snow::Layer::Layer() :
	zoomFactor_(1.f)
{
}

snow::Layer::~Layer()
{
}

void snow::Layer::tick(const int& delta, sf::RenderWindow& window)
{
	std::lock_guard<std::mutex> lock(actorsMutex_);
	if (actors_.startIterate())
	{
		window.setView(view_);
	try_again:; // Don`t do like me, don`t use goto!
		do
		{
			if (actors_.getIterator() != nullptr)
			{
				actors_.getIterator()->tick(delta, window);
			}
			else
			{
				if (actors_.getIteratorPosition() == 0)
				{
					actors_.removeIterator();
					if (actors_.startIterate())
					{
						// If the first element was removed, the loop starts again
						goto try_again; // Do you know that goto is bad? Don`t use it
					}
					else
					{
						break;
					}
				}
				else
				{
					actors_.removeIterator();
				}
			}
		} while (actors_.iterateNext());
	}

	if (followed_ != nullptr)
	{
		view_.setCenter(followed_->getPosition());
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