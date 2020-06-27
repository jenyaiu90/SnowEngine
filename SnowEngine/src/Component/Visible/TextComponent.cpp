    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: TextComponent.cpp           //
////////////////////////////////////////

#include "TextComponent.h"

snow::TextComponent::TextComponent(Actor* actor, std::string text, int size,
								   const std::string& fontFile, Vector2f pos) :
	Component(actor, pos)
{
	font_.loadFromFile(FONTS_PATH + fontFile);
	text_ = new sf::Text(sf::String(text), font_, size);
	text_->setPosition(static_cast<sf::Vector2f>(getWorldPosition()));
}

snow::TextComponent::~TextComponent()
{
	delete text_;
}

const std::string& snow::TextComponent::getText() const
{
	return text_->getString();
}

void snow::TextComponent::setText(const std::string& text)
{
	text_->setString(text);
}

void snow::TextComponent::setFont(const std::string& fontFile)
{
	font_.loadFromFile(FONTS_PATH + fontFile);
}

void snow::TextComponent::tick(const int& delta, sf::RenderWindow& window)
{
	window.draw(*text_);
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