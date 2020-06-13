    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Comparator.h                //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief The file for Comparator interface.
///	
///	This file contains the declaration of the Comparator interface.
////////////////////////////////////////////////////////////

#pragma once

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief Uses, for expample, for sorting in lists.
///	
///	If you want to sort the list you should create the class that implements this interface and
///	override a compare() method. The sort() method of a list takes an object of the comparator.
////////////////////////////////////////////////////////////
template<typename T>
class IComparator
{
public:

	////////////////////////////////////////////////////////////
	///	\brief Allows to compare two objects.
	///	
	///	This method takes to objects and returns a result of their comparing.
	///	\param first The first object.
	///	\param second The second object.
	///	\return
	///		- <b>0</b> if objects are equal.
	///		- <b>A positive value</b> if a first object is greater than a second one.
	///		- <b>A negative value</b> if a first object is less than a second one.
	////////////////////////////////////////////////////////////
	virtual int compare(const T& first, const T& second) = 0;
};

}