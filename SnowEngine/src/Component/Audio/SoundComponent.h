    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: SoundComponent.h            //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief The header file of SoundComponent class.
///	
///	In this file there is a declaration of SoundComponent class.
////////////////////////////////////////////////////////////

#pragma once

#include "../Component.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief A component that can play a sound.
///	
///	This component is used for playing a short sound. It uses sf::Sound SFML class that loads a
///	sound to sf::SoundBuffer. If you need to play a long sound (like music) in order to save a
///	memory you shoud use snow::MusicComponent.
////////////////////////////////////////////////////////////
class SoundComponent : public Component
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The default constructor.
	///	
	///	This constructor sets a relative position of component to default value (0.0, 0.0) and sets
	///	a file with sound. All sounds should be in "res/sounds/" folder. You can create another
	///	folders in it. SnowEngine supports WAV, FLAC and OGG formats. It doesn`t support MP3!
	///	\param actor An actor that the component will be attached to.
	///	\param file A relative path to file without "res/sounds/" For example, for
	///	"res/sounds/new/cow/cow-sound.wav" use next constructor:
	///	\code
	///		snow::SoundComponent("new/cow/cow-sound.wav");
	///	\endcode
	////////////////////////////////////////////////////////////
	SoundComponent(Actor* actor, const std::string& file);

	////////////////////////////////////////////////////////////
	///	\brief The method that is called every tick.
	///	
	///	This method does nothing. Absolutely. It is useless. But it is necessary.
	////////////////////////////////////////////////////////////
	void tick(const int& delta, sf::RenderWindow& window);

	////////////////////////////////////////////////////////////
	///	\brief Starts playing.
	///	
	///	Plays the sound.
	////////////////////////////////////////////////////////////
	void play();

	////////////////////////////////////////////////////////////
	///	\brief Pauses playing.
	///	
	///	Pauses the sound.
	////////////////////////////////////////////////////////////
	void pause();

private:

	std::string file_;

	sf::SoundBuffer buffer_;
	sf::Sound sound_;
};

}