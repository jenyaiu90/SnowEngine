    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: RectColisionComponent.h     //
////////////////////////////////////////

#pragma once

#include "CollisionComponent.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The rectangle collision component.
///	
///	The rectangle collision.
////////////////////////////////////////////////////////////
class RectCollisionComponent : public CollisionComponent
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The RectCollisionComponent`s constructor.
	///	
	///	Creates a new rectangle collision component.
	///	\param actor The actor that the component will be attached to.
	///	\param window The RenderWindow where the actor is (an SFML type, use Window::getWindow()).
	///	\param size The collision`s size.
	///	\param pos The collision`s position relative to the actor.
	////////////////////////////////////////////////////////////
	RectCollisionComponent(Actor* actor, sf::RenderWindow* window, Vector2f size,
							 Vector2f pos = Vector2f());

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
	///	\brief Returns the size of the collision.
	///	
	///	Allows to get the size of this collision component.
	///	\return The collision`s size.
	////////////////////////////////////////////////////////////
	Vector2f getSize() const;

protected:

	Vector2f size_;		///< The size of the collision
	
	Vector2i first_;	///< The coordinates of top-left segment with this collision.
	Vector2i last_;		///< The coordinates of down-right segment with this collision.

};

}
