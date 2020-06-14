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
	if (components.startIterate())
	{
		do
		{
			if (components.getIterator() != nullptr)
			{
				components.getIterator()->tick(delta, window);
			}
			else
			{
				components.remove(components.getIteratorPosition());
			}
		} while (components.iterateNext());
		components.stopIterate();
	}
}

bool snow::Actor::attach(snow::Component& component)
{
	components.add(&component);
	return true;
}