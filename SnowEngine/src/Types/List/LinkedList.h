    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: LinkedList.h                //
////////////////////////////////////////

#pragma once

#include <list>

#include "List.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief A template class that implements a linked list.
///
///	The wrapper of std::list class. This class is used for creating a linked list. It provides
///	faster adding and removing elements but slower access to them than an array.
///	\warning The template parameter must define operator ==.
////////////////////////////////////////////////////////////
template<typename T>
class LinkedList : public IList<T>
{
public:

	typedef typename std::list<T>::iterator listIterator;
	typedef typename std::list<T>::const_iterator constListIterator;

	////////////////////////////////////////////////////////////
	///	\brief The default constructor.
	///
	///	The default constructor creating an empty list.
	////////////////////////////////////////////////////////////
	LinkedList();

	////////////////////////////////////////////////////////////
	///	\brief This constructor allows to copy a list.
	///
	///	Creates the copy of other list.
	///	\param list The source list.
	////////////////////////////////////////////////////////////
	LinkedList(const LinkedList<T>& list);

	////////////////////////////////////////////////////////////
	///	\brief The length of the list.
	///
	///	Allows to get a length of the list.
	///	\return Number of elements in the list.
	////////////////////////////////////////////////////////////
	int length() const override;

	////////////////////////////////////////////////////////////
	///	\brief Checks whether the list is empty.
	///
	///	Allows to check whether the list is empty.
	///	\return <b>true</b> if the list is empty.
	////////////////////////////////////////////////////////////
	bool isEmpty() const override;

	////////////////////////////////////////////////////////////
	///	\breif Adds a new element in the list.
	///
	///	This methos puts a new element in the end of the list.
	///	\param item A new element.
	///	\return <b>true</b> if an element was successfully added.
	////////////////////////////////////////////////////////////
	virtual bool add(const T& item) override;

	////////////////////////////////////////////////////////////
	///	\brief Adds a new element in the list with passed index.
	///
	///	Puts a new element in the list with passed index.
	///	\param item A new element.
	///	\param pos An index.
	///	\return <b>true</b> if an element was successfullt added.
	////////////////////////////////////////////////////////////
	virtual bool add(const T& item, int pos) override;

	////////////////////////////////////////////////////////////
	///	\brief Adds a new element without violating the sort of the list.
	///	
	///	Allows to put a new element to the sorted list. The element will be added according to a
	///	passed comparator.
	///	\param item An element to put.
	///	\return <b>true</b> if an element was successfully added.
	/// \warning Use this method only for sorted or empty list. The SnowEngine doesn`t control
	///	this and work of this method for unsorted list may be wrong.
	////////////////////////////////////////////////////////////
	virtual bool add(const T& item, IComparator<T>& comparator) override;

	////////////////////////////////////////////////////////////
	///	\brief Removes an element with passed index from the list.
	///
	///	This method allows to remove an element from the list.
	///	\param pos An index of removing element.
	///	\return <b>true</b> if an element was successfully removed.
	////////////////////////////////////////////////////////////
	virtual bool remove(int pos) override;

	////////////////////////////////////////////////////////////
	///	\brief Removes an element from passed position.
	///	
	///	This method removes the element that the passed iterator points to.
	///	\param pos The iterator to the element to remove.
	///	\return The iterator to the element following the removed element.
	listIterator remove(listIterator pos);

	////////////////////////////////////////////////////////////
	/// \brief Returns the index of passed value.
	///	
	///	This method allows to find the value in the list.
	///	\param value The value for searching.
	///	\return The index of the first element that is equal to passed value or <b>-1</b> if the
	///	list doesn`t contain it.
	////////////////////////////////////////////////////////////
	int find(const T& value) const override;

	////////////////////////////////////////////////////////////
	/// \brief Allows to check whether the list contains the item.
	///	
	///	This method checks whether there is a passed value in the list.
	///	\param value The value for searching.
	///	\return <b>true</b> if the list contains the value.
	////////////////////////////////////////////////////////////
	bool contains(const T& value) const override;

	////////////////////////////////////////////////////////////
	///	\brief The method allows to fill the list with values from an array.
	///
	///	Clears the list and fills it with values from an array.
	///	\param array The pointer to the array to copy.
	///	\param size The size of the array.
	////////////////////////////////////////////////////////////
	virtual void sort(IComparator<T>& comparator) override;

	////////////////////////////////////////////////////////////
	///	\brief The method allows to fill the linked list with values from an array.
	///
	///	Clears the list and fills it with values from an array.
	///	\param array The pointer to the array to copy.
	///	\param size The size of the array.
	////////////////////////////////////////////////////////////
	virtual void fromArray(T* array, int size) override;

	////////////////////////////////////////////////////////////
	///	\brief Allows to get the array with values of the list.
	///
	///	Allows to convert the list to an array.
	///	\return The pointer to the result array. Use the method length() to get its size.
	////////////////////////////////////////////////////////////
	T* toArray() const override;

	////////////////////////////////////////////////////////////
	///	\brief Gives an element of the list with passed index.
	///
	///	This method allows to get an access to an element of the list.
	///	\param pos An index.
	///	\return An address of the element.
	///	\throws std::out_of_range if an index is out of bounds.
	////////////////////////////////////////////////////////////
	virtual T& operator[](int pos) override;

	////////////////////////////////////////////////////////////
	///	\brief Gives an element of the list with passed index.
	///
	///	This method allows to get an access to an element of the list.
	///	\param pos An index.
	///	\return An address of the element.
	///	\throws std::out_of_range if an index is out of bounds.
	////////////////////////////////////////////////////////////
	virtual const T& operator[](int pos) const override;

	////////////////////////////////////////////////////////////
	///	\brief Return <b>true</b> if two lists are equal.
	///	
	///	Checks whether two lists are equal. They are equal when their elements are equal.
	///	\param list Other list.
	///	\return <b>true</b> if lists are equal.
	////////////////////////////////////////////////////////////
	bool operator==(const LinkedList& list) const;

	////////////////////////////////////////////////////////////
	///	\brief Return <b>true</b> if two lists are not equal.
	///	
	///	Checks whether two lists are not equal. They are equal when their elements are equal.
	///	\param list Other list.
	///	\return <b>true</b> if lists are not equal.
	////////////////////////////////////////////////////////////
	bool operator!=(const LinkedList& list) const;

	////////////////////////////////////////////////////////////
	///	\brief Copies a list.
	///
	///	Clears the list and pastes to it a content of another list.
	///	\param list A list to copy.
	///	\return The list, that you can use, for example, for the construction below:
	///	\code
	///		LinkedList<int> first;
	///		LinkedList<int> second;
	///		LinkedList<int> third;
	///		first.add(5);
	///
	///		third = second = first;
	///	\endcode
	////////////////////////////////////////////////////////////
	LinkedList<T> operator=(const LinkedList<T>& list);

	////////////////////////////////////////////////////////////
	///	\brief Returns the iterator to the first element of the list.
	///	
	///	Is equivalent to the std::list`s begin() method.
	///	\return The iterator to the first element.
	////////////////////////////////////////////////////////////
	listIterator begin();

	////////////////////////////////////////////////////////////
	///	\brief Returns the const iterator to the first element of the list.
	///	
	///	Is equivalent to the std::list`s begin() method.
	///	\return The iterator to the first element.
	////////////////////////////////////////////////////////////
	constListIterator begin() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the iterator to the last element of the list.
	///	
	///	Is equivalent to the std::list`s end() method.
	///	\return The iterator to the last element.
	////////////////////////////////////////////////////////////
	listIterator end();

	////////////////////////////////////////////////////////////
	///	\brief Returns the const iterator to the last element of the list.
	///	
	///	Is equivalent to the std::list`s end() method.
	///	\return The iterator to the last element.
	////////////////////////////////////////////////////////////
	constListIterator end() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the iterator to an element of the list.
	///	
	///	Allows to get the iterator to the element with passed position.
	///	\return The iterator to the element with passed position.
	///	\throws std::out_of_range if an index is out of bounds.
	////////////////////////////////////////////////////////////
	listIterator getIterator(int pos);

	////////////////////////////////////////////////////////////
	///	\brief Returns the const iterator to an element of the list.
	///	
	///	Allows to get the iterator to the element with passed position.
	///	\return The iterator to the element with passed position.
	///	\throws std::out_of_range if an index is out of bounds.
	////////////////////////////////////////////////////////////
	constListIterator getIterator(int pos) const;

protected:

	std::list<T> list_;

};

// Below are the methods of the LinkedList.

template<typename T>
LinkedList<T>::LinkedList() :
	list_()
{
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) :
	list_(list.list_)
{
}

template<typename T>
inline int LinkedList<T>::length() const
{
	return static_cast<int>(list_.size());
}

template<typename T>
inline bool LinkedList<T>::isEmpty() const
{
	return list_.size() == 0;
}

template<typename T>
inline bool LinkedList<T>::add(const T& item)
{
	list_.push_back(item);
	return true;
}

template<typename T>
inline bool LinkedList<T>::add(const T& item, int pos)
{
	if (pos < 0 || pos > list_.size())
	{
		return false;
	}
	else
	{
		if (pos == list_.size())
		{
			return add(item);
		}
		else
		{
			list_.insert(getIterator(pos), item);
			return true;
		}
	}
}

template<typename T>
inline bool LinkedList<T>::add(const T& item, IComparator<T>& comparator)
{
	if (list_.size() == 0)
	{
		return add(item);
	}
	else
	{
		listIterator i;
		for (i = list_.begin(); i != list_.end(); i++)
		{
			if (comparator.compare(*i, item) > 0)
			{
				break;
			}
		}
		list_.insert(i, item);
		return true;
	}
}

template<typename T>
inline bool LinkedList<T>::remove(int pos)
{
	if (pos < 0 || pos >= list_.size())
	{
		return false;
	}
	else
	{
		list_.erase(getIterator(pos));
		return true;
	}
}

template<typename T>
inline typename snow::LinkedList<T>::listIterator snow::LinkedList<T>::remove(listIterator pos)
{
	return list_.erase(pos);
}

template<typename T>
inline int snow::LinkedList<T>::find(const T& value) const
{
	int index = 0;
	for (constListIterator i = list_.begin(); i != list_.end(); i++)
	{
		if (*i == value)
		{
			return index;
		}
		index++;
	}
	return -1;
}

template<typename T>
inline bool snow::LinkedList<T>::contains(const T& value) const
{
	return find(value) > -1;
}

template<typename T>
inline void snow::LinkedList<T>::sort(IComparator<T>& comparator)
{
	for (listIterator i = list_.end(); i != list_.begin(); i--)
	{
		for (listIterator j = list_.begin(); j != i; j++)
		{
			if (comparator.compare(*j, *i) > 1)
			{
				T tmp = *j;
				*j = *i;
				*i = tmp;
			}
		}
	}
}

template<typename T>
inline void LinkedList<T>::fromArray(T* array, int size)
{
	list_.clear();
	for (int i = 0; i < size; i++)
	{
		list_.push_back(array[i]);
	}
}

template<typename T>
inline T* snow::LinkedList<T>::toArray() const
{
	T* res = new T[list_.size()];
	int index = 0;
	for (constListIterator i = list_.begin(); i != list_.end(); i++)
	{
		res[index++] = *i;
	}
	return res;
}

template<typename T>
inline T& LinkedList<T>::operator[](int pos)
{
	if (pos < 0 || pos >= list_.size())
	{
		throw std::out_of_range("index is out of bounds");
	}
	else
	{
		return *getIterator(pos);
	}
}

template<typename T>
inline const T& LinkedList<T>::operator[](int pos) const
{
	if (pos < 0 || pos >= list_.size())
	{
		throw std::out_of_range("index is out of bounds");
	}
	else
	{
		return *getIterator(pos);
	}
}

template<typename T>
inline bool snow::LinkedList<T>::operator==(const snow::LinkedList<T>& list) const
{
	if (list_.size() != list.list_.size())
	{
		return false;
	}
	else
	{
		listIterator i1 = list_.begin();
		listIterator i2 = list.list_.begin();
		for (int i = 0; i < list_.size(); i++)
		{
			if (!(*i1 == *i2))
			{
				return false;
			}
		}
		return true;
	}
}

template<typename T>
inline bool snow::LinkedList<T>::operator!=(const snow::LinkedList<T>& list) const
{
	return !(*this == list);
}

template<typename T>
inline LinkedList<T> LinkedList<T>::operator=(const LinkedList<T>& list)
{
	list_ = list.list_;
	return *this;
}

template<typename T>
inline typename snow::LinkedList<T>::listIterator snow::LinkedList<T>::begin()
{
	return list_.begin();
}

template<typename T>
inline typename snow::LinkedList<T>::constListIterator snow::LinkedList<T>::begin() const
{
	return list_.begin();
}

template<typename T>
inline typename snow::LinkedList<T>::listIterator snow::LinkedList<T>::end()
{
	return list_.end();
}

template<typename T>
inline typename snow::LinkedList<T>::constListIterator snow::LinkedList<T>::end() const
{
	return list_.end();
}

template<typename T>
inline typename snow::LinkedList<T>::listIterator snow::LinkedList<T>::getIterator(int pos)
{
	if (pos < 0 && pos >= list_.size())
	{
		throw std::out_of_range("index is out of bounds");
	}
	else
	{
		listIterator p;
		if (pos < list_.size() / 2)
		{
			p = list_.begin();
			for (int i = 0; i < pos; i++)
			{
				p++;
			}
		}
		else
		{
			p = list_.end();
			pos = static_cast<int>(list_.size()) - pos;
			for (int i = 0; i < pos; i++)
			{
				p--;
			}
		}
		return p;
	}
}

template<typename T>
inline typename snow::LinkedList<T>::constListIterator snow::LinkedList<T>::getIterator(int pos) const
{
	if (pos < 0 && pos >= list_.size())
	{
		throw std::out_of_range("index is out of bounds");
	}
	else
	{
		constListIterator p;
		if (pos < list_.size() / 2)
		{
			p = list_.begin();
			for (int i = 0; i < pos; i++)
			{
				p++;
			}
		}
		else
		{
			p = list_.end();
			pos = static_cast<int>(list_.size()) - pos;
			for (int i = 0; i < pos; i++)
			{
				p--;
			}
		}
		return p;
	}
}

}