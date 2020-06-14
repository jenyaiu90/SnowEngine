    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Actor.h                     //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
/// \brief The file for the Actor class.
///	
///	This file contains the declaration of the Actor class.
////////////////////////////////////////////////////////////

#pragma once

#include "../Types/Vectors.h"
#include "../Types/List/LinkedList.h"
#include "../Component/Component.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The class of any displayable object.
///	
///	Any object that is in a window is an actor. Elements of GUI also are inherited from the Actor.
///	For create an object you should create a class that inherited from the Actor.
////////////////////////////////////////////////////////////
class Actor
{
public:

	////////////////////////////////////////////////////////////
	///	\brief This method is called every tick.
	///	
	///	A level or a GUI calls this method every tick. It calls the tick() method of actor`s
	///	component. You may override it but it is recommended to call parent`s method in your
	///	override:
	/// \code
	///		void tick(const int& delta) override;
	///		{
	///			__super::tick(delta);
	///			// Do what you need
	///		}
	///	\endcode
	///	It isn`t recommended to add any lengthly calculations in this method because it will affect
	///	perfomance.
	/// \param delta A duration of previous frame in milliseconds.
	///	\param window A window for drawing (an SFML type).
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta, sf::RenderWindow& window);

protected:

	////////////////////////////////////////////////////////////
	///	\brief The position of the actor.
	///	
	///	The world position of the actor.
	////////////////////////////////////////////////////////////
	Vector2f position;

	////////////////////////////////////////////////////////////
	///	\brief Attach a component to the actor.
	///	
	///	Attaches a passed component to the actor. It is recommended to attach components in the
	///	constructor of your custom actor:
	///	\code
	///		class ExampleActor : public snow::Actor
	///		{
	///		public:
	///			ExampleActor()
	///			{
	///				snow::TextComponent textComponent; // Example component
	///				attach(textComponent); // Attaching the component to the actor
	///			}
	///		};
	///	\endcode
	///	Note that SnowEngine calls the components` tick() method sequentially starting from a one
	///	that was added earlier.
	///	\param component A component to attaching.
	///	\return <b>true</b> if the component was successfully attached.
	////////////////////////////////////////////////////////////
	bool attach(Component& component);

private:

	LinkedList<Component*> components;
};

}