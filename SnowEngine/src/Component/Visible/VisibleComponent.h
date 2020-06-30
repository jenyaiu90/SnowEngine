    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: VisibleComponent.h          //
////////////////////////////////////////

#pragma once

#include "../Component.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The abstract class for all visible components.
///	
///	All components that are displayed in the window should be inherited from this abstract class.
////////////////////////////////////////////////////////////
class VisibleComponent : public Component
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constructor that sets a relative position and attaches the component to actor.
	///	
	///	This constructor sets a relative position of the component and attaches it to an actor.
	///	\param actor The actor that the component will be attached to.
	///	\param pos A relative position. A default value is (0.0, 0.0).
	////////////////////////////////////////////////////////////
	VisibleComponent(Actor* actor, Vector2f pos = Vector2f());

	////////////////////////////////////////////////////////////
	/// \brief Returns the component`s color.
	///	
	///	Allows to get the color of the component.
	///	\return The component`s color.
	////////////////////////////////////////////////////////////
	virtual const Color getColor() const = 0;

	////////////////////////////////////////////////////////////
	///	\brief Sets the color for the comoponent.
	///	
	///	Allows to set the component`s color.
	///	\param text The color that will be set for the component.
	////////////////////////////////////////////////////////////
	virtual void setColor(const Color color) = 0;
	
	////////////////////////////////////////////////////////////
	/// \brief Returns isEnabled field value.
	///	
	///	Allows to check whether the component is enabled.
	///	\return <b>true</b> if the component is enabled.
	////////////////////////////////////////////////////////////
	bool isEnabled() const;

	////////////////////////////////////////////////////////////
	///	\brief Enables or disables the component.
	///	
	///	Set the component`s status: enable or disable.
	///	\param enable If <b>true</b>, the component will be enabled.
	////////////////////////////////////////////////////////////
	virtual void setEnable(const bool enable);

protected:

	bool isEnabled_; ///< Is the component enabled.

};

}