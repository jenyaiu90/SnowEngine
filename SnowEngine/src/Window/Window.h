    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Window.h                    //
////////////////////////////////////////

#pragma once

#include "../Layer/Gui/Gui.h"
#include "../Layer/Level/Level.h"
#include "../Component/Visible/InputComponent.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The class of window. A level or UI can be attached for window.
///	
///	A displayed window. You can set a resulution and expand it to full screen. Levels and UI`s can
///	be attached for windows. For one window you can attach only one level and unlimited number of
///	GUI`s. Each window uses its own thread for displaying.
////////////////////////////////////////////////////////////
class Window
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The constuctor of Window. Allows to set a base characteristics.
	///
	///	This constructor creates a new window with passed base characteristics.
	///	\param title Title that will be displayed in the top of the window.
	///	\param resolution The resolution of the window in pixels, x is width, y is height.
	///	\param isFullscreen Allows to set whether the window should be expanded to full screen.
	///	The default value is <i>false</i>.
	////////////////////////////////////////////////////////////
	Window(const std::string& title, const Vector2i& resolution, bool isFullscreen=false);

	////////////////////////////////////////////////////////////
	///	\brief The destructor.
	///	
	///	The destructor closes the window (is it wasn`t closed earlier) and frees up the memory.
	///	\warning After calling this destructor you won`t be able to use the level or GUI`s because
	///	they will be deleted.
	////////////////////////////////////////////////////////////
	virtual ~Window();

	////////////////////////////////////////////////////////////
	///	\brief Attaches the level for the window.
	///	
	///	Allows to attach the level for the window. After attaching the level will being displayed
	///	in this window. Note that you can attach only one level to the window, if you attach a
	///	second level, a first one will be detached.
	///	\param level The level for attaching.
	///	\param safeMode If <b>true</b>, you can`t attach a level for the window if that window has
	///	already an attached level. The default value is <b>false</b>.
	///	\return <b>true</b> if the level was successfully attached.
	////////////////////////////////////////////////////////////
	bool attach(Level& level, bool safeMode=false);

	////////////////////////////////////////////////////////////
	///	\brief Attaches the GUI for the window.
	///	
	///	Allows to attach the GUI for the window. After attaching the GUI will being displayed in
	///	this window on top of the level.
	////////////////////////////////////////////////////////////
	bool attach(Gui& gui);

	////////////////////////////////////////////////////////////
	///	\brief Returns the pointer to sf::RenderWindow.
	///	
	///	Allows to get the pointer to sf::RenderWindow (an SFML type) that is used by this Window.
	///	\return Pointer to sf::RenderWindow.
	////////////////////////////////////////////////////////////
	sf::RenderWindow* getWindow();

	////////////////////////////////////////////////////////////
	///	\brief Returns the Input object.
	///	
	///	Allows to get a pointer to the Input object that can be modified. Use it to set the
	///	controls, for example:
	///	\code
	///		// Using lambda
	///		window.getInput()->mouseButtonPressed = [](MouseButton button, Vector2f position)
	///		{
	///			// Do something
	///		};
	///	\endcode
	///	\return The pointer to the Input object.
	////////////////////////////////////////////////////////////
	Input* getInput();

protected:
	std::mutex windowMutex_;
	std::mutex guisMutex_;

	sf::RenderWindow* window_;
	std::string title_;
	Vector2i resolution_;
	bool isFullscreen_;

	Level* level_;
	LinkedList<Gui*> guis_;

	Input input_;

	void startWindow(const std::string& title, const Vector2i& resolution, bool isFullscreen);
	void windowCycle();
};

}