    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Input.h                     //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include "../Types/Vectors.h"

namespace snow
{

typedef sf::Event::KeyEvent KeyData;
typedef sf::Keyboard::Key Key;
typedef sf::Mouse::Button MouseButton;

////////////////////////////////////////////////////////////
///	\brief Contains pointers to the event functions.
///	
///	This structure contains pointers to the functions that are called when an event happens.
////////////////////////////////////////////////////////////
struct Input
{
	///	Key on keyboard was pressed.
	void(*keyPressed)(KeyData key) = nullptr;

	///	Key on keyboard was released.
	void(*keyReleased)(KeyData key) = nullptr;

	///	Mouse button was pressed.
	void(*mouseButtonPressed)(MouseButton button, Vector2f position) = nullptr;

	///	Mouse button was released.
	void(*mouseButtonReleased)(MouseButton button, Vector2f position) = nullptr;

	///	Mouse wheel was scrolled.
	void(*mouseWheelScrolled)(int delta, Vector2f position) = nullptr;

	///	Mouse was moved.
	void(*mouseMoved)(Vector2f position) = nullptr;
};

}