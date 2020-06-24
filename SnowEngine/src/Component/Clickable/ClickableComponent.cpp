    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: ClickableComponent.cpp      //
////////////////////////////////////////

#include "ClickableComponent.h"

// The definition of the constructor is in the Layer.cpp file.

void snow::ClickableComponent::tick(const int& delta, sf::RenderWindow& window)
{
}

void snow::ClickableComponent::actorMove(Vector2f to)
{
}

snow::Vector2f snow::ClickableComponent::getSize() const
{
	return size_;
}