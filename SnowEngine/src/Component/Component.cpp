    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Component.cpp               //
////////////////////////////////////////

#include "Component.h"

// I don`t know WHY I have to write this line but without it nothing works.
const sf::RenderStates sf::RenderStates::Default = sf::RenderStates();

// Definition of the constructor is in Actor.cpp.

snow::Component::~Component()
{
}

// Definition of the getActor() method is in Actor.cpp.

// Definition of the getWorldPosition() method is in Actor.cpp.

snow::Vector2f snow::Component::getRelativePosition() const
{
	return position_;
}

// Definition of getWorldPosition() is in Actor.cpp.