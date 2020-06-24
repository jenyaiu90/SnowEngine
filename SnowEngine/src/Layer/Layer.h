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
	///	\brief The constructor.
	///	
	///	The constructor of the Layer class.
	////////////////////////////////////////////////////////////
	Layer();

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
	///	\brief The layer is attached to a window.
	///	
	///	This method should be called when the layer is attached to a window.
	///	\param size The window`s size.
	////////////////////////////////////////////////////////////
	void onAttaching(Vector2f size);

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
	///	\brief Changes the layer`s scale.
	///	
	///	Allows to zoom the layer. It multiplies the current zoom factor to passed.
	///	\param factor The zoom factor. If >1, the objects will appear smaller, if <1 then they will
	///	appear bigger.
	///	\return The new zoom factor.
	////////////////////////////////////////////////////////////
	float zoom(float factor);

	////////////////////////////////////////////////////////////
	///	\brief Sets the layer`s zoom.
	///	
	///	Allows to set the layer`s zoom factor.
	///	/param factor The zoom factor. If 1, This layer will be displayed in 1:1 scale, if <1, the objects
	///	will appear smaller.
	////////////////////////////////////////////////////////////
	void setZoom(float factor);

	////////////////////////////////////////////////////////////
	///	\brief Returns the current zoom factor.
	///	
	///	Allows to get the current layer`s zoom factor.
	///	\return The current zoom factor.
	////////////////////////////////////////////////////////////
	float getZoom();

	////////////////////////////////////////////////////////////
	///	\brief Moves the camera.
	///	
	///	Moves the camera by a delta.
	///	\param delta The camera will be moved by this value.
	///	\return The new center`s position.
	////////////////////////////////////////////////////////////
	Vector2f move(Vector2f delta);

	////////////////////////////////////////////////////////////
	///	\brief Sets the center of the view.
	///	
	///	Allows to set the point that the camera will look to.
	///	\param center The center of the view.
	////////////////////////////////////////////////////////////
	void setCenter(Vector2f center);

	////////////////////////////////////////////////////////////
	///	\brief Returns the current center of the view.
	///	
	///	Allows to get the point that the camera is looking to.
	///	\return The current center of the view.
	////////////////////////////////////////////////////////////
	Vector2f getCenter();

	////////////////////////////////////////////////////////////
	///	\brief This method is called when the window is resized.
	///	
	///	Changes the scale of the layer. It isn`t recommended to call this method not from a window.
	///	\param size The new size of the window.
	////////////////////////////////////////////////////////////
	void windowResize(Vector2f size);

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
	Vector2f windowSize_;
	float zoomFactor_;
	sf::View view_;

private:

	std::mutex actorsMutex_;
	LinkedList<Actor*> actors_;

};

}