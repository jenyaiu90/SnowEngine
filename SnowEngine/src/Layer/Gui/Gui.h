    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Gui.h                       //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief The file with the declaration of the Gui class.
///	
///	In this file the Gui class is declared.
////////////////////////////////////////////////////////////

#pragma once

#include "../Layer.h"
#include "../../Types/List/Comparator.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief Class for GUI management.
///	
///	This class can be used for creating, management and displaying GUI.
////////////////////////////////////////////////////////////
class Gui : public ILayer
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The method for displaying the GUI.
	///	
	///	Draws the GUI on the passed window.
	///	\param window The window for drawing (uses an SMFL window).
	////////////////////////////////////////////////////////////
	void draw(sf::RenderWindow& window) override;

	////////////////////////////////////////////////////////////
	///	\brief Returns the comparator.
	///	
	///	This method returns the comparator that compares priorities of GUI`s.
	///	\return A pointer to IComparator.
	////////////////////////////////////////////////////////////
	static IComparator<Gui>* getComparator();

protected:

	int priority_; ///< Defines the order of drawing the GUI`s. The GUI`s with lower priority are
				   ///  drawed later to be on top of other one.

	class GuiPriorityComparator : public IComparator<Gui>
	{
	public:
		int compare(const Gui& first, const Gui& second) override;
	};

	static GuiPriorityComparator comparator_;
};

}