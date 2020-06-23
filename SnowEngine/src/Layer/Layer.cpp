    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Layer.cpp                   //
////////////////////////////////////////

#include "Layer.h"

snow::Layer::~Layer()
{
	if (actors_.startIterate())
	{
		do
		{
			if (actors_.getIterator() != nullptr)
			{
				delete actors_.getIterator();
			}
		} while (actors_.iterateNext());
	}
}

void snow::Layer::tick(const int& delta, sf::RenderWindow& window)
{
	std::lock_guard<std::mutex> lock(actorsMutex_);
	if (actors_.startIterate())
	{
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
}

bool snow::Layer::spawnActor(snow::Actor* actor)
{
	std::lock_guard<std::mutex> lock(actorsMutex_);
	return actors_.add(actor);
}

snow::LinkedList<snow::ClickableComponent*>& snow::Layer::getClickables()
{
	return clickables_;
}

/////////////
//  Actor  //
/////////////

snow::Actor::Actor(Layer* layer, Vector2f pos) :
	position(pos),
	components_(),
	layer_(layer)
{
	layer->spawnActor(this);
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