    ////////////////////////////////////////
   //         After by SnegirSoft        //
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
	///	\brief A standart constructor of the TextureAnimation.
	///	
	///	This constructor creates a new TextureAnimation object and sets the sprite to it.
	///	\param sprite The sprite that will be animated.
	////////////////////////////////////////////////////////////
	TextureAnimation(sf::Sprite& sprite);
	
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

protected:

	sf::Sprite* sprite_; ///< The sprite that will be animated.

};

}