    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: TextComponent.cpp           //
////////////////////////////////////////

#include "TextComponent.h"

snow::TextComponent::TextComponent(Actor* actor, std::string text, int size,
								   const std::string& fontFile, Vector2f pos) :
	VisibleComponent(actor, pos),
	fileName_(fontFile)
{
	text_ = new sf::Text(sf::String(text), *ResourceManager::getFont(fontFile), size);
	text_->setPosition(static_cast<sf::Vector2f>(getWorldPosition()));
}

snow::TextComponent::~TextComponent()
{
	delete text_;
	ResourceManager::removeFont(fileName_);
}

std::string snow::TextComponent::getText() const
{
	return text_->getString();
}

void snow::TextComponent::setText(const std::string& text)
{
	text_->setString(text);
}

void snow::TextComponent::setFont(const std::string& fontFile)
{
	ResourceManager::removeFont(fileName_);
	text_->setFont(*ResourceManager::getFont(fontFile));
	fileName_ = fontFile;
}

void snow::TextComponent::tick(const int& delta, sf::RenderWindow& window)
{
	if (isEnabled_)
	{
		window.draw(*text_);
	}
}

void snow::TextComponent::actorMove(Vector2f to)
{
	text_->setPosition(static_cast<sf::Vector2f>(to + getRelativePosition()));
}

const snow::Color snow::TextComponent::getColor() const
{
	return text_->getFillColor();
}

void snow::TextComponent::setColor(const Color color)
{
	text_->setFillColor(color);
}

const int snow::TextComponent::getSize() const
{
	return text_->getCharacterSize();
}

void snow::TextComponent::setSize(const int size)
{
	text_->setCharacterSize(size);
}