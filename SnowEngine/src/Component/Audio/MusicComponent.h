    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: MisicComponent.h            //
////////////////////////////////////////

#pragma once

#include "../Component.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief A component that can play a music.
///	
///	This component is used for playing a long sound like music. It uses sf::Music SFML class that
///	loads a sound data from file at run time. If you need to play a short sound you shoud use
///	snow::SoundComponent.
////////////////////////////////////////////////////////////
class MusicComponent : public Component
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The default constructor.
	///	
	///	This constructor sets a relative position of component to default value (0.0, 0.0) and sets
	///	a file with music. All music should be in "res/music/" folder. You can create another
	///	folders in it. SnowEngine supports WAV, FLAC and OGG formats. It doesn`t support MP3!
	///	\param actor An actor that the component will be attached to.
	///	\param file A relative path to file without "res/music/" For example, for
	///	"res/music/menu/main/main-menu-music.wav" use next constructor:
	///	\code
	///		snow::MusicComponent("menu/main/main-menu-music.wav");
	///	\endcode
	////////////////////////////////////////////////////////////
	MusicComponent(Actor* actor, const std::string& file);

	////////////////////////////////////////////////////////////
	///	\brief The method that is called every tick.
	///	
	///	This method does nothing. Absolutely. It is useless. But it is necessary.
	////////////////////////////////////////////////////////////
	virtual void tick(const int& delta, sf::RenderWindow& window) override;

	////////////////////////////////////////////////////////////
	///	\brief Is called when actor is moved.
	///	
	///	Does nothing.
	////////////////////////////////////////////////////////////
	virtual void actorMove(Vector2f to) override;

	////////////////////////////////////////////////////////////
	///	\brief Starts playing.
	///	
	///	Plays the music.
	////////////////////////////////////////////////////////////
	virtual void play();

	////////////////////////////////////////////////////////////
	///	\brief Pauses playing.
	///	
	///	Pauses the music.
	////////////////////////////////////////////////////////////
	virtual void pause();

private:

	std::string file_;

	sf::Music music_;
};

}