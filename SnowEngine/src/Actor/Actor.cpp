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

void snow::Actor::tick(const int& delta, sf::RenderWindow& window)
{
	if (isSpawned_ && components_.startIterate())
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

bool snow::Actor::attachComponent(snow::Component* component)
{
	components_.add(component);
	return true;
}

snow::Component::Component(snow::Actor* actor, snow::Vector2f pos) :
	position(pos)
{
	actor->attachComponent(this);
}