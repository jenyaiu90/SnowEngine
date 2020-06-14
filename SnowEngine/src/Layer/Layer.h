    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Layer.h                     //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief The file for the Layer class.
///	
///	This file contains the declaration of the Layer class.
////////////////////////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include "../Actor/Actor.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The abstract class that is inherited by Level and Gui classes.
////////////////////////////////////////////////////////////
class Layer
{
public:

	////////////////////////////////////////////////////////////
	///	\brief This method is called every tick.
	///	
	///	A window calls this method every tick. It calls the tick() method of actors that are in
	///	the layer. You may override it but it is recommended to call parent`s method in your
	///	override:
	/// \code
	///		void tick(const int& delta) override;
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

protected:

	////////////////////////////////////////////////////////////
	///	\brief Spawns an actor to the layer.
	///	
	///	Spawns a passed actor in the layer. Note that SnowEngine calls the actors` tick() method
	///	sequentially starting from a one that was added earlier.
	///	\param actor An actor to spawn.
	///	\return <b>true</b> if the actor was successfully spawned.
	////////////////////////////////////////////////////////////
	bool spawn(Actor& actor);

private:

	LinkedList<Actor*> actors;

};

}