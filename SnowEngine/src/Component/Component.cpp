    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Component.cpp               //
////////////////////////////////////////

#include "Component.h"

// I don`t know WHY I have to write this line but without it nothing works.
const sf::RenderStates sf::RenderStates::Default = sf::RenderStates();

const std::string snow::Component::SOUNDS_PATH = "res/sounds/";
const std::string snow::Component::MUSIC_PATH = "res/music/";
const std::string snow::Component::TEXTURES_PATH = "res/textures/";

// Definition of the constructor is in Actor.cpp.

snow::Component::~Component()
{
}

snow::Vector2f snow::Component::getRelativePosition() const
{
	return position;
}

// Definition of getWorldPosition() is in Actor.cpp.