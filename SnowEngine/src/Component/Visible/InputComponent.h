    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: InputComponent.h            //
////////////////////////////////////////

#pragma once

#include "TextComponent.h"
#include "../Clickable/ClickableComponent.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The component that user can input text to.
///	
///	To this component user can input a text.
////////////////////////////////////////////////////////////
class InputComponent : public TextComponent
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constructor of the InputComponent class.
	///	
	///	This constructor creates a new text component.
	///	\param actor The actor that the component will be attached to.
	///	\param fontSize The font size.
	///	\param fontFile The relative path to the font file. All font files must be in
	///	"res/fonts/" folder. If you want to use the font from the "res/fonts/my/my_font.ttf", you
	///	should set the value "my/my_font.ttf" to this parameter.
	///	\param buttonSize The size of clickable area.
	///	\param pos The component\`s position relative to the actor. The default value if (0.0, 0.0).
	////////////////////////////////////////////////////////////
	InputComponent(Actor* actor, int fontSize, const std::string& fontFile,
				   Vector2f buttonSize, Vector2f pos = Vector2f());

	////////////////////////////////////////////////////////////
	///	\brief Deactivates an active InputComponent.
	///	
	///	If there is an active InputComponent, this method will deactivate it.
	////////////////////////////////////////////////////////////
	static void deactivate();

	////////////////////////////////////////////////////////////
	///	\brief Checks whether there is an active component.
	///	
	///	Allows to check whether there is an active InputComponent.
	///	\return <b>true</b> is there is an active component.
	////////////////////////////////////////////////////////////
	static bool thereIsActive();

	////////////////////////////////////////////////////////////
	///	\brief Input a character to the active component.
	///	
	///	If there is an active component, this function calls its input() method.
	///	\param c A character that will be added to the component\`s text. If <b>'\\b'</b>, the last
	///	character will be removed.
	////////////////////////////////////////////////////////////
	static void inputToActive(char c);

	////////////////////////////////////////////////////////////
	///	\brief Input a character.
	///	
	///	Adds passed character to the component\`s text.
	///	\param c A character to adding. If <b>'\\b'</b>, the last character will be removed.
	////////////////////////////////////////////////////////////
	virtual void input(char c);

	////////////////////////////////////////////////////////////
	///	\brief Sets the component as active.
	///	
	///	This method sets the component as active.
	////////////////////////////////////////////////////////////
	void setActive();

	////////////////////////////////////////////////////////////
	/// \brief Returns the displaying text.
	///	
	///	Allows to get the text that is set to the component.
	///	\return The component\`s text.
	////////////////////////////////////////////////////////////
	virtual std::string getText() const override;

	////////////////////////////////////////////////////////////
	///	\brief Sets the text for the comoponent.
	///	
	///	Allows to set the text that will being displayed.
	///	\param text The text that will be set for the component.
	////////////////////////////////////////////////////////////
	virtual void setText(const std::string& text) override;

protected:

	ClickableComponent clickable_;	///< The component\`s clickable component.

	static InputComponent* active_;	///< The current active InputComponent (may be nullptr).

};

}