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
	///	\param gui The GUI for attaching.
	///	\return <b>true</b> if the GUI was successfully attached.
	////////////////////////////////////////////////////////////
	bool attach(Gui& gui);

	////////////////////////////////////////////////////////////
	///	\brief Detaches the GUI from the window.
	///	
	///	Allows to detach the GUI from the window.
	///	\param gui The GUI for detaching.
	///	\return <b>true</b> if this GUI has been attached earlier and is detached now.
	////////////////////////////////////////////////////////////
	bool detach(Gui& gui);

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

	////////////////////////////////////////////////////////////
	///	\brief Wait for the window closing.
	///	
	///	This method pauses current thread while window isn`t closed.
	////////////////////////////////////////////////////////////
	void join();

protected:

	std::mutex windowMutex_;	///< The mutex for the window.
	std::mutex guisMutex_;		///< The mutex for the GUI list.

	sf::RenderWindow* window_;	///< The window (an SFML type).
	std::string title_;			///< The window`s title.
	Vector2i resolution_;		///< The window`s resolution (in pixels).
	bool isFullscreen_;			///< Is fullscreen.
								//   Unexpectedly...
/*
	Comments in my code look like this:

	            &
	          &&
		    &&& <-------------- // Smoke
	      &&&
	    &&&&
	   &&
	   &	^
	   _   / \
	  | | /   \ <-------------- // Roof
	  | |/ ___ \
	  | | | | | \
	  |/  |-|-| <-------------- // Window
	  |   |_|_|   \
	 /             \
	/_______________\	<------	// House
	|               |
	|      ___      |
	|     |   |     |
	|     |_  |     |
	|     |   |     |
	|_____|___|_____|
		   /|\
			------------------- // Door
*/

	Level* level_;				///< The level that is attached to the window.
	LinkedList<Gui*> guis_;		///< The list of GUI`s that are attached to the window.

	Input input_;				///< The struct for react to the input.

	/// Starts new window.
	void startWindow_(const std::string& title, const Vector2i& resolution, bool isFullscreen);
	void windowCycle_(); ///< The window`s behaviour.
						 //   No, I`m not British.

};

}