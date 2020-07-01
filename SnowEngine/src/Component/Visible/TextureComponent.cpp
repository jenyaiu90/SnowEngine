    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: TextureComponent.cpp        //
////////////////////////////////////////

#include "TextureComponent.h"

snow::TextureComponent::TextureComponent(snow::Actor* actor, const std::string& file,
										 snow::Vector2f pos) :
	VisibleComponent(actor, pos),
	sprite_(new sf::Sprite),
	fileName_(file)
{
	sprite_->setTexture(*ResourceManager::getTexture(file));
	sprite_->setPosition(static_cast<sf::Vector2f>(position_));
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
	ResourceManager::removeTexture(fileName_);
}

void snow::TextureComponent::tick(const int& delta, sf::RenderWindow& window)
{
	if (isEnabled_)
	{
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
	sprite_->setPosition(static_cast<sf::Vector2f>(to + position_));
}