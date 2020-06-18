    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Layer.cpp                   //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief The file for the Layer class definition.
///	
///	This file contains the difinition of the mathods of the Layer class.
////////////////////////////////////////////////////////////

#include "Layer.h"

void snow::Layer::tick(const int& delta, sf::RenderWindow& window)
{
	std::lock_guard<std::mutex> lock(actorsMutex_);
	if (actors_.startIterate())
	{
		do
		{
			if (actors_.getIterator() != nullptr)
			{
				actors_.getIterator()->tick(delta, window);
			}
		} while (actors_.iterateNext());
	}
}

bool snow::Layer::spawnActor(snow::Actor* actor)
{
	std::lock_guard<std::mutex> lock(actorsMutex_);
	return actors_.add(actor);
}

/////////////
//  Actor  //
/////////////

snow::Actor::Actor(Layer* layer, Vector2f pos) :
	position(pos),
	components_()
{
	layer->spawnActor(this);
}