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

void snow::ClickableComponent::event(Event event, MouseButton button, Vector2f position)
{
	switch (event)
	{
	case MOUSE_PRESSED:
	{
		if (onMousePressed != nullptr)
		{
			onMousePressed(button, position);
		}
		break;
	}
	case MOUSE_RELEASED:
	{
		if (onMouseReleased != nullptr)
		{
			onMouseReleased(button, position);
		}
		break;
	}
	}
}