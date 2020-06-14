    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Component.h                 //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief File for the Component class.
///	
///	This file contains the declaration of the Component class.
////////////////////////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include "../Types/Vectors.h"
#include "../Types/List/LinkedList.h"

namespace snow
{

////////////////////////////////////////////////////////////
/// \brief The abstract Component class.
///	
///	You may create your custom component. Just create a class that is inherited from the Component
///	class or one of its inheritors (like TextComponent, AudioComponent etc.). A component can be
///	attached to an actor. Don`t attach one component to several objects, it can cause unpredictable
///	program behaviour.
////////////////////////////////////////////////////////////
class Component
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constructor that sets a relative position.
	///	
	///	This constructor sets a relative position of the component.
	///	\param pos A relative position. A default value is (0.0, 0.0).
	////////////////////////////////////////////////////////////
	Component(Vector2f pos=Vector2f());

	////////////////////////////////////////////////////////////
	/// \brief The method that is called every tick.
	///	
	///	This method is called every tick by an Actor that the component is attached to. It isn`t
	///	recommended to do any lengthy calculations in this method because it will affect
	///	perfomance. If you override this method, it is recommended to call a parent`s tick()
	///	method:
	///	\code
	///		void tick(const int& delta) override
	///		{
	///			__super::tick(delta);
	///			// Do what you need
	///		}
	///	\endcode
	///	\param delta A duration of previous frame in milliseconds.
	///	\param window A window for drawing (an SFML type).
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta, sf::RenderWindow& window) = 0;

protected:

	////////////////////////////////////////////////////////////
	///	\brief The relative position of the component.
	///	
	///	The position of the component. Note that it is position relative to the object that the
	///	component is attached to.
	////////////////////////////////////////////////////////////
	Vector2f position;

};

}