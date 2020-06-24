    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Gui.cpp                     //
////////////////////////////////////////

#include "Gui.h"

snow::Gui::GuiPriorityComparator snow::Gui::comparator_;
snow::Gui::GuiPointerPriorityComparator snow::Gui::pointerComparator_;

snow::Gui::Gui(int priority)
{
	priority_ = priority;
}

snow::IComparator<snow::Gui>* snow::Gui::getComparator()
{
	return &comparator_;
}

snow::IComparator<snow::Gui*>* snow::Gui::getPointerComparator()
{
	return &pointerComparator_;
}

int snow::Gui::GuiPriorityComparator::compare(const Gui& first, const Gui& second) const
{
	return first.priority_ - second.priority_;
}

int snow::Gui::GuiPointerPriorityComparator::compare(const GuiPointer& first,
													 const GuiPointer& second) const
{
	return (*first).priority_ - (*second).priority_;
}