    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: TextureAnimation.h          //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The interfacr that is used for sprite animation.
///	
///	Classes that are inherited from this class are used for change a textures of AnimationComponent.
////////////////////////////////////////////////////////////
class TextureAnimation
{
public:
	
	////////////////////////////////////////////////////////////
	///	\brief Method that is calles every tick.
	///	
	///	This method counts the time and changes passed sprite.
	///	\param delta The duration of the previous tick in milliseconds.
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta) = 0;

	////////////////////////////////////////////////////////////
	///	\brief Method that resets the animation.
	///	
	///	Starts the animation from the begin.
	////////////////////////////////////////////////////////////
	virtual void reset() = 0;

	////////////////////////////////////////////////////////////
	///	\brief Sets a sprite to animate.
	///	
	///	This methos allows to set a sprite that will be animated. If the sprite isn`t set, the
	///	animation doesn`t work. If you use AnimationComponent, you shouldn`t set the sprite.
	////////////////////////////////////////////////////////////
	virtual void setSprite(sf::Sprite* sprite);

	////////////////////////////////////////////////////////////
	///	\brief Returns the pointer to the sprite.
	///	
	///	This method allows to get the pointer to the sprite that is animated by this
	///	TextureAnimation.
	////////////////////////////////////////////////////////////
	virtual sf::Sprite* getSprite();

protected:

	sf::Sprite* sprite_; ///< The sprite that will be animated.

};

}