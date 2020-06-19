    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: TextureAnimation.cpp        //
////////////////////////////////////////

#include "TextureAnimation.h"

void snow::TextureAnimation::setSprite(sf::Sprite* sprite)
{
	sprite_ = sprite;
	reset();
}

sf::Sprite* snow::TextureAnimation::getSprite()
{
	return sprite_;
}