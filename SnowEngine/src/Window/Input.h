    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Input.h                     //
////////////////////////////////////////

#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
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
	std::function<void(KeyData key)> keyPressed;

	///	Key on keyboard was released.
	std::function<void(KeyData key)> keyReleased;

	///	Mouse button was pressed.
	std::function<void(MouseButton button, Vector2f position)> mouseButtonPressed;

	///	Mouse button was released.
	std::function<void(MouseButton button, Vector2f position)> mouseButtonReleased;

	///	Mouse wheel was scrolled.
	std::function<void(int delta, Vector2f position)> mouseWheelScrolled;

	///	Mouse was moved.
	std::function<void(Vector2f position)> mouseMoved;
};

}