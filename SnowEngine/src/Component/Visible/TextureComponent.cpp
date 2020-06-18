    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: TextureComponent.cpp        //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
/// \brief The file for the TextureComponent class.
///	
///	This file contains the definition of the methods of the TextureComponent class.
////////////////////////////////////////////////////////////

#include "TextureComponent.h"

snow::TextureComponent::TextureComponent(snow::Actor* actor, const std::string& file,
										 snow::Vector2f pos) :
	Component(actor, pos),
	file_(file),
	texture_(new sf::Texture),
	sprite_(new sf::Sprite)
{
	texture_->loadFromFile(TEXTURES_PATH + file);
	sprite_->setTexture(*texture_);
	sprite_->setPosition(static_cast<sf::Vector2f>(position));
}

snow::TextureComponent::TextureComponent(snow::Actor* actor, const std::string & file,
										 snow::IntRect textureRect, snow::Vector2f pos) :
	TextureComponent(actor, file, pos)
{
	sprite_->setTextureRect(textureRect);
}

void snow::TextureComponent::tick(const int& delta, sf::RenderWindow& window)
{
	snow::Vector2f nps = getWorldPosition();
	sf::Vector2f np = static_cast<sf::Vector2f>(nps);
	sprite_->setPosition(np);
	window.draw(*sprite_);
}
void snow::TextureComponent::actorMove(snow::Vector2f to)
{
	sprite_->setPosition(to + static_cast<sf::Vector2f>(position));
}