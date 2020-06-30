    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: ClickableComponent.h        //
////////////////////////////////////////

#pragma once

#include "../Component.h"
#include "../../Window/Input.h"

namespace snow
{

class Window;

////////////////////////////////////////////////////////////
///	\brief The component that can respond to click.
///	
///	This component can be used for objects that must respond to click, for example, buttons. You
///	don`t need to create a new class that is inherited from this, but you can do it. Use
///	onMousePressed, onMouseReleased and onMouseHovered fields to set functions that will be calles.
///	For example:
///	\code
///		snow::ClickableComponent component(&actor, &window, Vector2f(100.f, 100.f));
///		component.onMousePressed = [](MouseButton button, Vector2f position)
///		{
///			// Do what you need
///		};
///		
///		// Or without lambda
///		
///		void f(MouseButton button, Vector2f position)
///		{
///			// Do what you need
///		}
///		// ...
///		snow::ClickableComponent component(&actor, &window, Vector2f(100.f, 100.f));
///		component.onMousePressed = f;
///	\endcode
////////////////////////////////////////////////////////////
class ClickableComponent : public Component
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constructor if the ClickableComponent.
	///	
	///	Creates a new clickable component with passed properties.
	///	\param actor The actor that the component will be attached to.
	///	\param size The clickable area size.
	///	\param pos The position of the component relative to the actor. The default value is
	///	(0.0, 0.0).
	////////////////////////////////////////////////////////////
	ClickableComponent(Actor* actor, Vector2f size, Vector2f pos=Vector2f());

	////////////////////////////////////////////////////////////
	///	\brief The method that is called every tick.
	///	
	///	This method does nothing. Absolutely. It is useless. But it is necessary.
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta, sf::RenderWindow& window) override;

	////////////////////////////////////////////////////////////
	///	\brief Is called when actor is moved.
	///	
	///	Does nothing.
	////////////////////////////////////////////////////////////
	virtual void actorMove(Vector2f to) override;

	////////////////////////////////////////////////////////////
	///	\brief Returns the component`s size.
	///	
	///	Allows to get the size of clickable area.
	///	\return The size.
	////////////////////////////////////////////////////////////
	Vector2f getSize() const;

	/// When the mouse button was pressed.
	std::function<void(MouseButton button, Vector2f position)> onMousePressed;

	///	When the mouse button was released.
	std::function<void(MouseButton button, Vector2f position)> onMouseReleased;

	// Maybe later...

	//	When the cursor was hovered over.
	// std::function<void(Vector2f position)> onMouseHovered;

	// When the cursor isn`t hovered over the component more.
	// std::function<void()> onMouseUnhovered;

protected:

	Vector2f size_; ///< The size of clickable area.

};

}