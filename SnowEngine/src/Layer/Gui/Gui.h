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
class Gui : public Layer
{
public:
	////////////////////////////////////////////////////////////
	///	\brief The constructor. Can set a priority.
	///	
	///	This constructor allows to set a priority. The GUI with lower priority is drawed later
	/// to be on top of other one.
	///	\return A pointer to IComparator.
	////////////////////////////////////////////////////////////
	Gui(int priority=0);

	////////////////////////////////////////////////////////////
	///	\brief Returns the comparator of Gui.
	///	
	///	This method returns the comparator that compares priorities of GUI`s.
	///	\return A pointer to IComparator.
	////////////////////////////////////////////////////////////
	static IComparator<Gui>* getComparator();

	////////////////////////////////////////////////////////////
	///	\brief Returns the comparator of Gui*.
	///	
	///	This method returns the comparator that compares priorities of GUI`s (Gui*).
	///	\return A pointer to IComparator.
	////////////////////////////////////////////////////////////
	static IComparator<Gui*>* getPointerComparator();

protected:

	int priority_; ///< Defines the order of drawing the GUI`s. The GUI with lower priority is
				   ///  drawed later to be on top of other one.

	class GuiPriorityComparator : public IComparator<Gui>
	{
	public:
		int compare(const Gui& first, const Gui& second) override;
	};

	class GuiPointerPriorityComparator : public IComparator<Gui*>
	{
		typedef Gui* GuiPointer; // I really don`t know why it works but it works. I hope...
	public:
		int compare(const GuiPointer& first, const GuiPointer& second) override;
	};

	static GuiPriorityComparator comparator_;
	static GuiPointerPriorityComparator pointerComparator_;
};

}