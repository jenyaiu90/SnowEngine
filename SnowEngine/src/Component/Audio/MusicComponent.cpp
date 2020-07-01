    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: MusicComponent.cpp          //
////////////////////////////////////////

#include "MusicComponent.h"

snow::MusicComponent::MusicComponent(snow::Actor* actor, const std::string& file) :
	Component(actor),
	file_(file)
{
	music_.openFromFile(ResourceManager::MUSIC_PATH + file);
}

void snow::MusicComponent::tick(const int& delta, sf::RenderWindow& window)
{
}

void snow::MusicComponent::actorMove(snow::Vector2f to)
{
}

void snow::MusicComponent::play()
{
	music_.play();
}

void snow::MusicComponent::pause()
{
	music_.pause();
}