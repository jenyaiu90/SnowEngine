    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Gui.cpp                     //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief The file with definition of the Gui class.
///	
///	This file contains the definitions of the methods of the Gui class.
////////////////////////////////////////////////////////////

#include "Gui.h"

snow::Gui::GuiPriorityComparator snow::Gui::comparator_;

void snow::Gui::draw(sf::RenderWindow& window)
{

}

snow::IComparator<snow::Gui>* snow::Gui::getComparator()
{
	return &comparator_;
}

int snow::Gui::GuiPriorityComparator::compare(const Gui& first, const Gui& second)
{
	return first.priority_ - second.priority_;
}