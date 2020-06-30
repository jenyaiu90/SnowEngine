    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: TextComponent.h             //
////////////////////////////////////////

#pragma once

#include "VisibleComponent.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The component that is displayed as text.
///	
///	This component displays the text. You also should set the font for it.
////////////////////////////////////////////////////////////
class TextComponent : public VisibleComponent
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constructor of the TextComponent class.
	///	
	///	This constructor creates a new text component.
	///	\param actor The actor that the component will be attached to.
	///	\param text The text that will being bisplayed.
	///	\param size The text size.
	///	\param fontFile The relative path to the font file. All font files must be in
	///	"res/fonts/" folder. If you want to use the font from the "res/fonts/my/my_font.ttf", you
	///	should set the value "my/my_font.ttf" to this parameter.
	///	/param pos The component`s position relative to the actor. The default value if (0.0, 0.0).
	////////////////////////////////////////////////////////////
	TextComponent(Actor* actor, std::string text, int size,
				  const std::string& fontFile, Vector2f pos = Vector2f());
	
	////////////////////////////////////////////////////////////
	///	\brief The TextComponent`s destructor.
	///	
	///	Removes the values of the component`s fields.
	////////////////////////////////////////////////////////////
	~TextComponent();

	////////////////////////////////////////////////////////////
	/// \brief This method is called every tick.
	///	
	///	This method draws the text on the window. It is called every tick.
	///	\param delta The duration of the previous frame.
	///	\param window The sf::RenderWindow for drawing (an SFML type).
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta, sf::RenderWindow& window) override;

	////////////////////////////////////////////////////////////
	///	\brief This method is called whenever the actor changes its position.
	///	
	///	This method is called by the actor that the component is attached to whenever it is moved.
	///	\param to The new actor`s position.
	////////////////////////////////////////////////////////////
	virtual void actorMove(Vector2f to) override;

	////////////////////////////////////////////////////////////
	/// \brief Returns the displaying text.
	///	
	///	Allows to get the text that is set to the component.
	///	\return The component`s text.
	////////////////////////////////////////////////////////////
	virtual std::string getText() const;

	////////////////////////////////////////////////////////////
	///	\brief Sets the text for the comoponent.
	///	
	///	Allows to set the text that will being displayed.
	///	\param text The text that will be set for the component.
	////////////////////////////////////////////////////////////
	virtual void setText(const std::string& text);

	////////////////////////////////////////////////////////////
	///	\brief Sets the font for the comoponent`s text.
	///	
	///	Allows to set the font for the text.
	///	\param text The path to the file with the font. That file must be in "res/fonts/" folder.
	///	For example, if you want to set the font from the file "res/fonts/my/my_font.ttf", you
	///	should use setFont("my/my_font.ttf").
	////////////////////////////////////////////////////////////
	void setFont(const std::string& fontFile);

	////////////////////////////////////////////////////////////
	/// \brief Returns the text`s color.
	///	
	///	Allows to get the color of the text that is set to the component.
	///	\return The text`s color.
	////////////////////////////////////////////////////////////
	const Color getColor() const override;

	////////////////////////////////////////////////////////////
	///	\brief Sets the color for the text of the comoponent.
	///	
	///	Allows to set the text`s color.
	///	\param text The color that will be set for the component`s text.
	////////////////////////////////////////////////////////////
	void setColor(const Color color) override;

	////////////////////////////////////////////////////////////
	/// \brief Returns the text`s size.
	///	
	///	Allows to get the size of the text that is set to the component.
	///	\return The text`s size.
	////////////////////////////////////////////////////////////
	const int getSize() const;

	////////////////////////////////////////////////////////////
	///	\brief Sets the size for the text of the comoponent.
	///	
	///	Allows to set the text`s size.
	///	\param text The size that will be set for the component`s text.
	////////////////////////////////////////////////////////////
	void setSize(const int size);

protected:

	sf::Font font_;		///< The font (an SFML type).
	sf::Text* text_;	///< The displaying text (an SFML type).

};

}