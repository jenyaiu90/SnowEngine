    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: SoundComponent.cpp          //
////////////////////////////////////////

#include "SoundComponent.h"

snow::SoundComponent::SoundComponent(snow::Actor* actor, const std::string& file) :
	Component(actor),
	file_(file)
{
	buffer_.loadFromFile(SOUNDS_PATH + file_);
	sound_.setBuffer(buffer_);
}

void snow::SoundComponent::tick(const int& delta, sf::RenderWindow& window)
{
}

void snow::SoundComponent::actorMove(snow::Vector2f to)
{
}

void snow::SoundComponent::play()
{
	sound_.play();
}

void snow::SoundComponent::pause()
{
	sound_.pause();
}