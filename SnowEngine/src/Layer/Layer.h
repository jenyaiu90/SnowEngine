    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Layer.h                     //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include "../Actor/Actor.h"
#include "../Component/Clickable/ClickableComponent.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The abstract class that is inherited by Level and Gui classes.
///	
///	The class of objects that can be attached to a window and contain actors.
////////////////////////////////////////////////////////////
class Layer
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The Layer`s destructor.
	///	
	///	The destructor of the Layer class. Removes all attached actors.
	////////////////////////////////////////////////////////////
	virtual ~Layer();

	////////////////////////////////////////////////////////////
	///	\brief This method is called every tick.
	///	
	///	A window calls this method every tick. It calls the tick() method of actors that are in
	///	the layer. You may override it but it is recommended to call parent`s method in your
	///	override:
	/// \code
	///		void tick(const int& delta) override
	///		{
	///			__super::tick(delta);
	///			// Do what you need
	///		}
	///	\endcode
	///	Note that it is not recommended to add any lengthly calculations to this method because it
	///	will affect perfomance.
	/// \param delta A duration of previous frame in milliseconds.
	///	\param window A window for drawing (an SFML type).
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta, sf::RenderWindow& window);

	////////////////////////////////////////////////////////////
	///	\brief Spawns an actor to the layer.
	///	
	///	Spawns a passed actor in the layer. Note that SnowEngine calls the actors` tick() method
	///	sequentially starting from a one that was added earlier. If you need to override this
	///	method, it is recommended to call parent`s method:
	///	\code
	///		bool spawnActor(Actor& actor) override
	///		{
	///			__super::spawnActor(actor);
	///			// Do what you need.
	///		}
	///	\endcode
	///	\warning This method should be called only by an actor. It isn`t recommended to use it in
	///	your code.
	///	\param actor An actor to spawn.
	///	\return <b>true</b> if the actor was successfully spawned.
	////////////////////////////////////////////////////////////
	virtual bool spawnActor(Actor* actor);

	////////////////////////////////////////////////////////////
	///	\brief Returns the list of clickable components of the layer.
	///	
	///	Allows to get an adderess of the linked list with clickable components. This method is used
	///	by the ClickableComponent class, it isn`t recommended to use it out if that class.
	///	\return The linked list of clickable components.
	////////////////////////////////////////////////////////////
	LinkedList<ClickableComponent*>& getClickables();

protected:

	LinkedList<ClickableComponent*> clickables_;

private:

	std::mutex actorsMutex_;
	LinkedList<Actor*> actors_;

};

}