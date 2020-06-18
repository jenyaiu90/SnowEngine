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
#include <SFML/Audio.hpp>
#include <string>
#include "../Types/Vectors.h"
#include "../Types/List/LinkedList.h"

namespace snow
{

class Actor;

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

	static const std::string SOUNDS_PATH;	///< Path to sounds folder.
	static const std::string MUSIC_PATH;	///< Path to music folder.
	static const std::string TEXTURES_PATH;	///< Path to textures folder.

	////////////////////////////////////////////////////////////
	///	\brief The constructor that sets a relative position and attaches the component to actor.
	///	
	///	This constructor sets a relative position of the component and attached
	///	\param pos A relative position. A default value is (0.0, 0.0).
	////////////////////////////////////////////////////////////
	Component(Actor* actor, Vector2f pos=Vector2f());

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

	////////////////////////////////////////////////////////////
	///	\brief Returns component`s relative position.
	///	
	///	This method allows you to get component`s position relative to the base actor.
	///	\return The relative position as snow::Vector2f.
	////////////////////////////////////////////////////////////
	Vector2f getRelativePosition();

	////////////////////////////////////////////////////////////
	///	\brief Returns component`s world position.
	///	
	///	This method lets you to get component`s world position.
	///	\return The world position as snow::Vector2f.
	////////////////////////////////////////////////////////////
	Vector2f getWorldPosition();

protected:

	////////////////////////////////////////////////////////////
	///	\brief The relative position of the component.
	///	
	///	The position of the component. Note that it is position relative to the object that the
	///	component is attached to.
	////////////////////////////////////////////////////////////
	Vector2f position;

private:

	Actor* actor_;

};

}