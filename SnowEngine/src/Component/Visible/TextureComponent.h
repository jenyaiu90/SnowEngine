    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: TextureComponent.h          //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief File for the TextureComponent class.
///	
///	This file contains the declaration of the TextureComponent class.
////////////////////////////////////////////////////////////

#pragma once

#include "../Component.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The component that draws a texture.
///	
///	This component is intended for displaying actor`s texture. If you need to create an animation,
///	you should use the AnimationComponent.
////////////////////////////////////////////////////////////
class TextureComponent : public Component
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constructor of the TextureComponent.
	///	
	///	This constructor attaches new component to an actor, sets its relative position and a file
	///	with a source texture.
	///	\param actor An actor that the component will be attached to.
	///	\param file A file with a source texture.
	///	\param pos A position of the component relative to a base actor.
	////////////////////////////////////////////////////////////
	TextureComponent(Actor* actor, const std::string& file, Vector2f pos=Vector2f());

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

private:

	std::string file_;

	sf::Texture* texture_;
	sf::Sprite* sprite_;

};

}