    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: TextureComponent.cpp        //
////////////////////////////////////////

#include "TextureComponent.h"

snow::TextureComponent::TextureComponent(snow::Actor* actor, const std::string& file,
										 snow::Vector2f pos) :
	VisibleComponent(actor, pos),
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

snow::TextureComponent::~TextureComponent()
{
	delete sprite_;
	delete texture_;
}

void snow::TextureComponent::tick(const int& delta, sf::RenderWindow& window)
{
	if (isEnabled_)
	{
//		snow::Vector2f nps = getWorldPosition();
//		sf::Vector2f np = static_cast<sf::Vector2f>(nps);
//		sprite_->setPosition(np);
		window.draw(*sprite_);
	}
}

void snow::TextureComponent::setTextureRect(snow::IntRect textureRect)
{
	sprite_->setTextureRect(textureRect);
}

snow::IntRect snow::TextureComponent::getTextureRect() const
{
	return sprite_->getTextureRect();
}

const snow::Color snow::TextureComponent::getColor() const
{
	return sprite_->getColor();
}

void snow::TextureComponent::setColor(const Color color)
{
	sprite_->setColor(color);
}

void snow::TextureComponent::setScale(snow::Vector2f newScale)
{
	sprite_->setScale(static_cast<sf::Vector2f>(newScale));
}

void snow::TextureComponent::setScale(float newScale)
{
	sprite_->setScale(sf::Vector2f(newScale, newScale));
}

snow::Vector2f snow::TextureComponent::getScale() const
{
	return sprite_->getScale();
}

snow::Vector2f snow::TextureComponent::scale(snow::Vector2f factor)
{
	sprite_->scale(static_cast<sf::Vector2f>(factor));
	return sprite_->getScale();
}

snow::Vector2f snow::TextureComponent::scale(float factor)
{
	sprite_->scale(sf::Vector2f(factor, factor));
	return sprite_->getScale();
}

void snow::TextureComponent::actorMove(snow::Vector2f to)
{
	sprite_->setPosition(static_cast<sf::Vector2f>(to + position));
}