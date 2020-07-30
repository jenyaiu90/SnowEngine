    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: ColisionComponent.h         //
////////////////////////////////////////

#pragma once

#include <mutex>

#include "../Component.h"
#include "../../Types/List/Dictionaty.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The abstract class for all collision components.
///	
///	This abstract class should be used for all collision components. It has a static container with
///	all components.
////////////////////////////////////////////////////////////
class CollisionComponent : public Component
{
public:

	static const int SEGMENT_SIZE = 500; ///< The size of one collision segment in pixels.

	////////////////////////////////////////////////////////////
	///	\brief The constructor of the CollisionComponent.
	///	
	///	Sets the component`s fields. The default value is "default".
	///	\param actor The actor that the component will be attached to.
	///	\param window The sf::RenderWindow where the actor is (use snow::Window::getWindow()).
	///	\param type The type of the collision (for example "rectangle" for RectCollisionComponent
	///	or "circle" for CircleCollisionComponent).
	///	\param pos The component`s position relative to the actor. The default value is (0, 0).
	////////////////////////////////////////////////////////////
	CollisionComponent(Actor* actor, sf::RenderWindow* window,
					   const std::string& type, Vector2f pos=Vector2f());

	////////////////////////////////////////////////////////////
	///	\brief The constructor of the CollisionComponent.
	///	
	///	Sets the component`s fields.
	///	\param actor The actor that the component will be attached to.
	///	\param window The sf::RenderWindow where the actor is (use snow::Window::getWindow()).
	///	\param type The type of the collision (for example "rectangle" for RectCollisionComponent
	///	or "circle" for CircleCollisionComponent).
	///	\param kind The kind of the collision (for example, "character", "vehicle" or "wall").
	///	\param pos The component`s position relative to the actor. The default value is (0, 0).
	////////////////////////////////////////////////////////////
	CollisionComponent(Actor* actor, sf::RenderWindow* window, const std::string& type,
					   const std::string& kind, Vector2f pos=Vector2f());

	////////////////////////////////////////////////////////////
	///	\brief The CollisionComponent`s destructor.
	///	
	///	The destructor of CollisionComponent class. Should be overrided.
	////////////////////////////////////////////////////////////
	virtual ~CollisionComponent() = 0;

	////////////////////////////////////////////////////////////
	///	\brief The method that is called every tick.
	///	
	///	This method does nothing. Absolutely. It is useless. But it is necessary.
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta, sf::RenderWindow& window) override;

	////////////////////////////////////////////////////////////
	///	\brief Checks whether this component collides with passed one.
	///	
	///	Allows to check whether this component collides with passed one. If you want to create your
	///	class inherited from CollisionComponent, often in this method you should to check collision
	///	component type:
	///	\code
	///		bool isCollide(CollisionComponent* collision) const override
	///		{
	///			if (collision->getType() == "rectangle")
	///			{
	///				// Do for rectangle
	///			}
	///			else if (collision->getType() == "circle")
	///			{
	///				// Do for circle
	///			}
	///			// Etc.
	///		}
	///	\endcode
	///	\param collision The other component to check.
	///	\return <b>true</b> is components collide.
	////////////////////////////////////////////////////////////
	virtual bool isCollide(const CollisionComponent* collision) const = 0;

	////////////////////////////////////////////////////////////
	///	\brief Checks whether this component collides with other one.
	///	
	///	Calls method isCollide with every nearby collision components.
	///	\return The array list with all components that collide with this.
	////////////////////////////////////////////////////////////
	virtual ArrayList<CollisionComponent*> checkCollision();

	////////////////////////////////////////////////////////////
	///	\brief Checks whether this component collides with other one based on its kind.
	///	
	///	Calls method isCollide with every nearby collision components that has a passed kind.
	///	\param kind The kind of collisions that must be checked.
	///	\return The array list with all components that collide with this.
	////////////////////////////////////////////////////////////
	virtual ArrayList<CollisionComponent*> checkCollision(const std::string& kind);

	////////////////////////////////////////////////////////////
	///	\brief Checks whether this component collides with other one based on its kind.
	///	
	///	Calls method isCollide with every nearby collision components that has a passed kind.
	///	\param kinds The array of kinds of collisions that must be changed.
	///	\return The array list with all components that collide with this.
	////////////////////////////////////////////////////////////
	virtual ArrayList<CollisionComponent*> checkCollision(const ArrayList<std::string>& kinds);

	////////////////////////////////////////////////////////////
	///	\brief Returns the type of the collision component
	///	
	///	Allows to get the type of this collision component (for example, "rectangle" for
	///	RectCollisionComponent or "circle" for CircleCollisionComponent).
	///	\return The type.
	////////////////////////////////////////////////////////////
	virtual const std::string& getType() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the kind of the collision component
	///	
	///	Allows to get the kind of this collision component (for example, "character", "vehicle" or
	///	"wall").
	///	\return The kind.
	////////////////////////////////////////////////////////////
	const std::string& getKind() const;

protected:

	std::string type_; ///< Generally sets the collision`s form.
	std::string kind_; ///< For example, "character", "vehicle" or "wall".

	static std::mutex collisionsMutex_; ///< The mutex for collisions_.
	static Dictionary<sf::RenderWindow*, Dictionary<Vector2i, ArrayList<CollisionComponent*>>>
		collisions_; ///< The dictionary of all collision components.
					 //   ...The scary dictionary...

	sf::RenderWindow* window_; ///< The window with that component (an SFML type)

	ArrayList<Vector2i> segments_; ///< The list of segments that contain the collision component.

	void removeFromSegment_(int x, int y, int windowId);	///< Removes the component from the list.
	void addToSegment_(int x, int y, int windowId);			///< Adds the component to the list.

};

}