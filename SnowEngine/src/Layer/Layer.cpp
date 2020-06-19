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

/////////////
//  Actor  //
/////////////

snow::Actor::Actor(Layer* layer, Vector2f pos) :
	position(pos),
	components_()
{
	layer->spawnActor(this);
}