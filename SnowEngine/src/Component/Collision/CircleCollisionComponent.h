    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: CircleColisionComponent.h   //
////////////////////////////////////////

#pragma once

#include "CollisionComponent.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The circle collision component.
///	
///	The circle collision.
////////////////////////////////////////////////////////////
class CircleCollisionComponent : public CollisionComponent
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The CircleCollisionComponent`s constructor.
	///	
	///	Creates a new circle collision component.
	///	\param actor The actor that the component will be attached to.
	///	\param window The RenderWindow where the actor is (an SFML type, use Window::getWindow()).
	///	\param radius The circle`s radius.
	///	\param pos The collision`s position relative to the actor.
	////////////////////////////////////////////////////////////
	CircleCollisionComponent(Actor* actor, sf::RenderWindow* window, float radius,
							 Vector2f pos = Vector2f());

	////////////////////////////////////////////////////////////
	///	\brief The CircleCollisionComponent`s destructor.
	///	
	///	The destructor of CircleCollisionComponent class. Removes the collision from a statis 
	///	collisions list.
	////////////////////////////////////////////////////////////
	virtual ~CircleCollisionComponent();

	////////////////////////////////////////////////////////////
	///	\brief Is called when the actor moves.
	///	
	///	This method must be called before the actor that the component is attached to is moved.
	///	\param to The new actor`s position.
	////////////////////////////////////////////////////////////
	virtual void actorMove(Vector2f to) override;

	////////////////////////////////////////////////////////////
	///	\brief Checks whether this component collides with passed one.
	///	
	///	Allows to check whether this component collides with passed one.
	///	\param collision The other component to check.
	///	\return <b>true</b> is components collide.
	////////////////////////////////////////////////////////////
	bool isCollide(const CollisionComponent* collision) const override;

	////////////////////////////////////////////////////////////
	///	\brief Returns the radius of the collision.
	///	
	///	Allows to get the radius of this collision component.
	///	\return The collision`s radius.
	////////////////////////////////////////////////////////////
	float getRadius() const;

protected:

	float radius_;		///< The size of the collision
	
	Vector2i first_;	///< The coordinates of top-left segment with this collision.
	Vector2i last_;		///< The coordinates of down-right segment with this collision.

};

}
