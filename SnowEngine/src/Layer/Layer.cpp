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
	if (actors.startIterate())
	{
		do
		{
			if (actors.getIterator() != nullptr)
			{
				actors.getIterator()->tick(delta, window);
			}
			else
			{
				actors.remove(actors.getIteratorPosition());
			}
		} while (actors.iterateNext());
	}
}

bool snow::Layer::spawn(snow::Actor& actor)
{
	return actors.add(&actor);
}