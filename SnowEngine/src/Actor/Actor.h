    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Actor.h                     //
////////////////////////////////////////

#pragma once

#include <mutex>

#include "../Component/Component.h"

namespace snow
{

class Layer;

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
	///	\brief The constructor that sets a world position and spawns the actor.
	///	
	///	This constructor sets a world position of the actor.
	///	\param layer A layer where the actor will be spawned.
	///	\param pos A world position. A default value is (0.0, 0.0).
	////////////////////////////////////////////////////////////
	Actor(Layer* layer, Vector2f pos=Vector2f());

	////////////////////////////////////////////////////////////
	///	\brief The Actor`s destructor.
	///	
	///	The destructor of class Actor. Is virtual. Doesn`t delete any attached component. Detaches
	///	the actor from the layer.
	////////////////////////////////////////////////////////////
	virtual ~Actor();

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

	////////////////////////////////////////////////////////////
	///	\brief Returns the layer that the actor is attached to.
	///	
	///	Allows to get the pointer to the layer.
	///	\return The pointer to the layer that the actor is attached to.
	////////////////////////////////////////////////////////////
	Layer* getLayer();

	////////////////////////////////////////////////////////////
	///	\brief Allows to get the world position.
	///	
	///	This method lets you to get actor`s position.
	///	\return The world position as snow::Vector2f.
	////////////////////////////////////////////////////////////
	Vector2f getPosition() const;

	////////////////////////////////////////////////////////////
	///	\brief Changes the actor`s position.
	///	
	///	This method lets you to change the actor`s position. Calls components` actorMove() method.
	///	\position The new actor`s position.
	////////////////////////////////////////////////////////////
	virtual void setPosition(Vector2f position);

	////////////////////////////////////////////////////////////
	///	\brief Moves the actor.
	///	
	///	Allows to move the actor. Can do it with an animation.
	///	\param to Sets a position that the actor will be moved to.
	///	\param time The time it takes to move the actor in milliseconds. If 0, it will move
	///	without an animation.
	////////////////////////////////////////////////////////////
	virtual void move(Vector2f to, int time=0);

	////////////////////////////////////////////////////////////
	///	\brief Attach a component to the actor.
	///	
	///	Attaches a passed component to the actor. This method should be called only from component.
	///	It isn`t recommended to use it in your code. Note that SnowEngine calls the components`
	///	tick() method sequentially starting from a one that was added earlier.
	///	\param component A component to attaching.
	///	\return <b>true</b> if the component was successfully attached.
	////////////////////////////////////////////////////////////
	bool attachComponent(Component* component);

	////////////////////////////////////////////////////////////
	///	\brief Detach a component from the actor.
	///	
	///	Detaches a passed component from the actor if the component has been attached to it. This
	///	method should be called only from component. It isn`t recommended to use it in your code.
	///	\param component A component to detach.
	///	\return <b>true</b> if the component was successfully detached.
	////////////////////////////////////////////////////////////
	bool detachComponent(Component* component);

protected:

	Vector2f position_;	///< The actor`s world position.
	Vector2f speed_;		///< The actor`s speed in px/ms.

	/// The point that the actor moves to. If nullptr, the actor doesn`t have a destination.
	Vector2f* destination;

private:
	
	std::recursive_mutex componentsMutex_;	///< The mutex for components_ list.
	LinkedList<Component*> components_;		///< The list of actor`s component.
	Layer* layer_;							///< The layer that the actor is attached to.

};

}