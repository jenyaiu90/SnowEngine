    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: TextureComponent.h          //
////////////////////////////////////////

#pragma once

#include "VisibleComponent.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The component that draws a texture.
///	
///	This component is intended for displaying actor`s texture. If you need to create an animation,
///	you should use the AnimationComponent.
////////////////////////////////////////////////////////////
class TextureComponent : public VisibleComponent
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constructor of the TextureComponent.
	///	
	///	This constructor attaches new component to an actor, sets its relative position and a file
	///	with a source texture. It doesn`t set the texture rect.
	///	\param actor An actor that the component will be attached to.
	///	\param file A file with a source texture.
	///	\param pos A position of the component relative to a base actor. The default value
	///	is (0, 0).
	////////////////////////////////////////////////////////////
	TextureComponent(Actor* actor, const std::string& file, Vector2f pos=Vector2f());

	////////////////////////////////////////////////////////////
	///	\brief The constructor of the TextureComponent.
	///	
	///	This constructor attaches new component to an actor, sets its relative position, a file
	///	with a source texture and the texture rect.
	///	\param actor An actor that the component will be attached to.
	///	\param file A file with a source texture.
	///	\param textureRect A rectangle for texture.
	///	\param pos A position of the component relative to a base actor. The default value
	///	is (0, 0).
	////////////////////////////////////////////////////////////
	TextureComponent(Actor* actor, const std::string& file,
					 IntRect textureRect, Vector2f pos=Vector2f());

	////////////////////////////////////////////////////////////
	///	\brief The TextureComponent`s destructor.
	///	
	///	The destructor of the TextureComponent.
	////////////////////////////////////////////////////////////
	virtual ~TextureComponent();

	////////////////////////////////////////////////////////////
	///	\brief Method that is called every tick.
	///	
	///	This method draws the texture and is called every tick. If you need to override it, you
	///	should call a parent`s method:
	///	\code
	///		void tick(const int& delta, sf::RenderWindow& window) override
	///		{
	///			// Do what you need
	///			__super::tick(delta, window);
	///		}
	///	\endcode
	///	It isn`t recommended to do any lengthly calculations in this method because it will affect
	///	perfomance.
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta, sf::RenderWindow& window) override;

	////////////////////////////////////////////////////////////
	///	\brief Sets the rect for the texture.
	///	
	///	Allows to crop the texture with passed rectangle.
	///	\param textureRect The rectangle to cropping.
	////////////////////////////////////////////////////////////
	virtual void setTextureRect(IntRect textureRect);

	////////////////////////////////////////////////////////////
	///	\brief Returns the texture rectangle.
	///	Allows to get the rectangle that the texture was cropped with.
	///	\return The texture rectangle.
	////////////////////////////////////////////////////////////
	virtual IntRect getTextureRect() const;

	////////////////////////////////////////////////////////////
	/// \brief Returns the component`s color.
	///	
	///	Allows to get the color of the component.
	///	\return The component`s color.
	////////////////////////////////////////////////////////////
	virtual const Color getColor() const override;

	////////////////////////////////////////////////////////////
	///	\brief Sets the color for the comoponent.
	///	
	///	Allows to set the component`s color.
	///	\param text The color that will be set for the component.
	////////////////////////////////////////////////////////////
	virtual void setColor(const Color color) override;

	////////////////////////////////////////////////////////////
	///	\brief Sets a new scale for the texture.
	///	
	///	Allows to set a scale for the texture. The default scale is (1, 1). If you want to increase
	///	the texture twice, you shoud set the scale (2, 2).
	///	\param newScale The new texture`s scale.
	////////////////////////////////////////////////////////////
	virtual void setScale(Vector2f newScale);

	////////////////////////////////////////////////////////////
	///	\brief Sets a new scale for the texture.
	///	
	///	Allows to set a scale for the texture. The default scale is 1. If you want to increase
	///	the texture twice, you shoud set the scale 2. This method is equal to setScale(Vector2f) if
	///	x = y.
	///	\param newScale The new texture`s scale.
	////////////////////////////////////////////////////////////
	virtual void setScale(float newScale);

	////////////////////////////////////////////////////////////
	///	\brief Returns the texture`s scale.
	///	
	///	Allows to get the texture`s scale.
	///	\return The texture`s scale.
	////////////////////////////////////////////////////////////
	virtual Vector2f getScale() const;

	////////////////////////////////////////////////////////////
	///	\brief Scales the texture.
	///	
	///	Multiplies the curret scale to a passed factor and sets result value as a new scale.
	///	\code
	///		snow::Vector2f factor(x, y);
	///		
	///		snow::Vector2f vector = component.scale(factor);
	///		// Is equal to:
	///		snow::Vector2f newFactor = component.getScale();
	///		newFactor.x *= factor.x;
	///		newFactor.y *= factor.y;
	///		component.setScale(newFactor);
	///		snow::Vector2f vector = component.getScale();
	///	\endcode
	///	\param factor The multiplier.
	///	\return The new scale of the texture.
	////////////////////////////////////////////////////////////
	virtual Vector2f scale(Vector2f factor);

	////////////////////////////////////////////////////////////
	///	\brief Scales the texture.
	///	
	///	Multiplies the curret scale to a passed factor and sets result value as a new scale. This
	///	method is equal to scale(Vector2f) if x = y.
	///	\code
	///		float factor = x;
	///		
	///		snow::Vector2f vector = component.scale(factor);
	///		// Is equal to:
	///		snow::Vector2f newFactor = component.getScale();
	///		newFactor *= factor;
	///		component.setScale(newFactor);
	///		snow::Vector2f vector = component.getScale();
	///	\endcode
	///	\param factor The multiplier.
	///	\return The new scale of the texture.
	////////////////////////////////////////////////////////////
	virtual Vector2f scale(float factor);

	////////////////////////////////////////////////////////////
	///	\brief When actor moves.
	///	
	///	This method should be called when actor that the component is attached to is moved. It
	///	changes the position of the sprite.
	///	\param to The point that the actor was moved to.
	////////////////////////////////////////////////////////////
	virtual void actorMove(Vector2f to) override;

protected:

	sf::Sprite* sprite_;	///< The displaying sprite.

private:

	sf::Texture* texture_;	///< The texture (an SFML type).

};

}