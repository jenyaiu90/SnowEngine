    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Level.h                     //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief File for the declaration of the class Level.
///	
///	This file contains the declaration of the class Level.
////////////////////////////////////////////////////////////

#pragma once

#include "../Layer.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The level class, can be used as a base class for custom levels.
///	
///	Level is a scene that contains static or moving objects. Those objects can be attached for only
///	one level. If you need a level with other behavior, you may create a custom level: a new class
///	that is inherited from Level class.
////////////////////////////////////////////////////////////
class Level : public ILayer
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The method for displaying the GUI.
	///	
	///	Draws the GUI on the passed window.
	///	\param window The window for drawing (uses an SMFL window).
	////////////////////////////////////////////////////////////
	void draw(sf::RenderWindow& window) override;
};

}