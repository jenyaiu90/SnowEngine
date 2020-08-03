    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: List.h                      //
////////////////////////////////////////

#pragma once

#include "Comparator.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The interface for lists.
///
///	This interface contains all the methods that the list have to have. You can implement it if
///	you want to create your own list.
////////////////////////////////////////////////////////////
template<typename T>
class IList
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The length of the list.
	///
	///	Allows to get a length of the list.
	///	\return Number of elements in the list.
	////////////////////////////////////////////////////////////
	virtual int length() const = 0;

	////////////////////////////////////////////////////////////
	///	\brief Checks whether the list is empty.
	///
	///	Allows to check whether the list is empty.
	///	\return <b>true</b> if the list is empty.
	////////////////////////////////////////////////////////////
	virtual bool isEmpty() const = 0;

	////////////////////////////////////////////////////////////
	///	\brief Adds a new element in the list.
	///
	///	This methos puts a new element in the end of the list.
	///	\param item A new element.
	///	\return <b>true</b> if an element was successfully added.
	////////////////////////////////////////////////////////////
	virtual bool add(const T& item) = 0;

	////////////////////////////////////////////////////////////
	///	\brief Adds a new element in the list with passed index.
	///
	///	Puts a new element in the list with passed index.
	///	\param item A new element.
	///	\param pos An index.
	///	\return <b>true</b> if an element was successfullt added.
	////////////////////////////////////////////////////////////
	virtual bool add(const T& item, int pos) = 0;

	////////////////////////////////////////////////////////////
	///	\brief Adds a new element without violating the sort of the list.
	///	
	///	Allows to put a new element to the sorted list. The element will be added according to a
	///	passed comparator.
	///	\param item An element to put.
	///	\param comparator A link to a comparator object.
	///	\return <b>true</b> if an element was successfully added.
	////////////////////////////////////////////////////////////
	virtual bool add(const T& item, IComparator<T>& comparator) = 0;

	////////////////////////////////////////////////////////////
	///	\brief Removes an element with passed index from the list.
	///
	///	This method allows to remove an element from the list.
	///	\param pos An index of removing element.
	///	\return <b>true</b> if an element was successfully removed.
	////////////////////////////////////////////////////////////
	virtual bool remove(int pos) = 0;

	////////////////////////////////////////////////////////////
	/// \brief Returns the index of passed value.
	///	
	///	This method allows to find the value in the list.
	///	\param value The value for searching.
	///	\return The index of the first element that is equal to passed value or <b>-1</b> if the
	///	list doesn\`t contain it.
	////////////////////////////////////////////////////////////
	virtual int find(const T& value) const = 0;

	////////////////////////////////////////////////////////////
	/// \brief Allows to check whether the list contains the item.
	///	
	///	This method checks whether there is a passed value in the list.
	///	\param value The value for searching.
	///	\return <b>true</b> if the list contains the value.
	////////////////////////////////////////////////////////////
	virtual bool contains(const T& value) const = 0;

	////////////////////////////////////////////////////////////
	///	\brief Sorts the list.
	///	
	///	Allows to sort the list according to a passed comparator. The smallest elements are moved
	///	to the start of the list.
	///	\param comparator An object of a class that implements the IComparator interface.
	////////////////////////////////////////////////////////////
	virtual void sort(IComparator<T>& comparator) = 0;

	////////////////////////////////////////////////////////////
	///	\brief The method allows to fill the list with values from an array.
	///
	///	Clears the list and fills it with values from an array.
	///	\param array The pointer to the array to copy.
	///	\param size The size of the array.
	////////////////////////////////////////////////////////////
	virtual void fromArray(T* array, int size) = 0;

	////////////////////////////////////////////////////////////
	///	\brief Allows to get the array with values of the list.
	///
	///	Allows to convert the list to an array.
	///	\return The pointer to the result array. Use the method length() to get its size.
	////////////////////////////////////////////////////////////
	virtual T* toArray() const = 0;

	////////////////////////////////////////////////////////////
	///	\brief Gives an element of the list with passed index.
	///
	///	This method allows to get an access to an element of the list.
	///	\param pos An index.
	///	\return An address of the element.
	////////////////////////////////////////////////////////////
	virtual T& operator[](int pos) = 0;

	////////////////////////////////////////////////////////////
	///	\brief Gives an element of the list with passed index.
	///
	///	This method allows to get an access to an element of the list.
	///	\param pos An index.
	///	\return An address of the element.
	////////////////////////////////////////////////////////////
	virtual const T& operator[](int pos) const = 0;
};

}