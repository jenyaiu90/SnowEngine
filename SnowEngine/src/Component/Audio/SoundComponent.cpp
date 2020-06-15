    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: SoundComponent.cpp          //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief The source file of the SoundComponent class.
///	
///	This file contains the definitions of the methods of the SoundComponent class.
////////////////////////////////////////////////////////////

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

void snow::SoundComponent::play()
{
	sound_.play();
}

void snow::SoundComponent::pause()
{
	sound_.pause();
}