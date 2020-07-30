    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: ArrayList.h                 //
////////////////////////////////////////

#pragma once

#include <vector>

#include "List.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The class that implements an array list.
///	
///	The wrapper of the std::vector class. Use this class to create an array list. It provides fast
///	access to the element but adding and removing are not fast. If you need to add and remove
///	elements fast, use a linked list.
///	\warning The template parameter must define operator ==.
////////////////////////////////////////////////////////////
template<typename T>
class ArrayList : public IList<T>
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The default constructor.
	///	
	///	This constructor creates an empty array.
	////////////////////////////////////////////////////////////
	ArrayList();

	////////////////////////////////////////////////////////////
	///	\brief The constructor that allows to set an initial size.
	///	
	///	This constructor lets you to set an initial size of the array. Note that this constructor
	///	creates an empty array but the initial array will have a passed size. If you know how many
	///	elements you`ll need in advance, it`s recommended to use this constructor. You will still may add in
	///	the array unlimited number of items.
	////////////////////////////////////////////////////////////
	ArrayList(int size);

	////////////////////////////////////////////////////////////
	///	\brief This constructor allows to copy a list.
	///	
	///	Creates the copy of other list.
	///	\param list The source list.
	////////////////////////////////////////////////////////////
	ArrayList(const ArrayList<T>& list);

	////////////////////////////////////////////////////////////
	///	\brief The methot that allows to get a number of the elements.
	///	
	///	This method lets you to get a number of the elements in the array.
	///	\return The size of the array.
	////////////////////////////////////////////////////////////
	int length() const override;

	////////////////////////////////////////////////////////////
	///	\brief Checks whether the array is empty.
	///	
	///	Allows to check whether the array list is empty.
	///	\return <b>true</b> if the array is empty.
	////////////////////////////////////////////////////////////
	bool isEmpty() const override;

	////////////////////////////////////////////////////////////
	///	\brief The method for adding an element to the end of the array.
	///	
	///	Adds a passed element to the end of the array list.
	///	\param item Putted element.
	///	\return <b>true</b> if an element was successfully added.
	////////////////////////////////////////////////////////////
	bool add(const T& item) override;

	////////////////////////////////////////////////////////////
	///	\brief The method for adding an element.
	///	
	///	Adds an element to the array list with passed index.
	///	\param item Putted element.
	///	\param pos An index for the new element.
	///	\return <b>true</b> if an element was successfully added.
	////////////////////////////////////////////////////////////
	bool add(const T& item, int pos) override;

	////////////////////////////////////////////////////////////
	///	\brief Adds a new element without violating the sort of the list.
	///	
	///	Allows to put a new element to the sorted list. The element will be added according to a
	///	passed comparator.
	///	\param item An element to put.
	///	\return <b>true</b> if an element was successfully added.
	/// \warning Use this method only for sorted or empty list. The SnowEngine doesn`t controle
	///	this and work of this method for unsorted list may be wrong.
	////////////////////////////////////////////////////////////
	bool add(const T& item, IComparator<T>& comparator) override;

	////////////////////////////////////////////////////////////
	///	\brief The method for removing an element.
	///	
	///	Removes an element with the passed index from the array list.
	///	\param pos An index of the removing element.
	///	\return <b>true</b> if an element was successfully removed.
	////////////////////////////////////////////////////////////
	bool remove(int pos) override;

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
	void sort(IComparator<T>& comparator) override;

	////////////////////////////////////////////////////////////
	///	\brief The method allows to fill the array list with values from an array.
	///	
	///	Clears the list and fills it with values from an array.
	///	\param array The pointer to the array to copy.
	///	\param size The size of the array.
	////////////////////////////////////////////////////////////
	void fromArray(T* array, int size) override;

	////////////////////////////////////////////////////////////
	///	\brief Allows to get the array with values of the list.
	///	
	///	Allows to convert the list to an array.
	///	\return The pointer to the result array. Use the method length() to get its size.
	////////////////////////////////////////////////////////////
	T* toArray() const override;

	////////////////////////////////////////////////////////////
	///	\brief The operator that allows to get access to one of the elements.
	///	
	///	Gives you an address of the element with passed index.
	///	\param pos An index.
	///	\return An address of the element.
	///	\throws std::out_of_range if there is no element with passed index.
	////////////////////////////////////////////////////////////
	T& operator[](int pos) override;

	////////////////////////////////////////////////////////////
	///	\brief The operator that allows to get access to one of the elements.
	///	
	///	Gives you an address of the element with passed index.
	///	\param pos An index.
	///	\return An address of the element.
	///	\throws std::out_of_range if there is no element with passed index.
	////////////////////////////////////////////////////////////
	const T& operator[](int pos) const override;

	////////////////////////////////////////////////////////////
	///	\brief Return <b>true</b> if two lists are equal.
	///	
	///	Checks whether two lists are equal. They are equal when their elements are equal.
	///	\param list Other list.
	///	\return <b>true</b> if lists are equal.
	////////////////////////////////////////////////////////////
	bool operator==(const ArrayList& list) const;

	////////////////////////////////////////////////////////////
	///	\brief Return <b>true</b> if two lists are not equal.
	///	
	///	Checks whether two lists are different. They are equal when their elements are equal.
	///	\param list Other list.
	///	\return <b>true</b> if lists are not equal.
	////////////////////////////////////////////////////////////
	bool operator!=(const ArrayList& list) const;

	////////////////////////////////////////////////////////////
	///	\brief The assignment operator.
	///	
	///	Clears the array and copies the passed array.
	///	\param list An array list for copy.
	///	\return The array list, that you can use, for example, for the construction below:
	///	\code
	///		ArrayList<int> first;
	///		ArrayList<int> second;
	///		ArrayList<int> third;
	///		first.add(5);
	///	
	///		third = second = first;
	///	\endcode
	////////////////////////////////////////////////////////////
	ArrayList<T> operator=(const ArrayList<T>& list);

private:

	std::vector<T> array_;

};

// Below are the methods of the ArrayList.

template<typename T>
ArrayList<T>::ArrayList() :
	ArrayList(5)
{
}

template<typename T>
ArrayList<T>::ArrayList(int size) :
	array_(size)
{
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& list) :
	array_(list.array_)
{
}

template<typename T>
inline int ArrayList<T>::length() const
{
	return static_cast<int>(array_.size());
}

template<typename T>
inline bool ArrayList<T>::isEmpty() const
{
	return array_.size() == 0;
}

template<typename T>
inline bool ArrayList<T>::add(const T& item)
{
	array_.push_back(item);
	return true;
}

template<typename T>
inline bool ArrayList<T>::add(const T& item, int pos)
{
	if (pos < 0 || pos > array_.size())
	{
		return false;
	}
	else
	{
		if (array_.size() == 0)
		{
			add(item);
		}
		else
		{
			array_.push_back(array_.back());
			for (int i = static_cast<int>(array_.size()) - 2; i >= pos; i--)
			{
				array_[i + 1] = array_[i];
			}
			array_[pos] = item;
		}
		return true;
	}
}

template<typename T>
inline bool ArrayList<T>::add(const T& item, IComparator<T>& comparator)
{
	int i;
	for (i = 0; i < array_.size(); i++)
	{
		if (comparator.compare(array_[i], item) > 0)
		{
			break;
		}
	}
	return add(item, i);
}

template<typename T>
inline bool ArrayList<T>::remove(int pos)
{
	if (pos < 0 || pos >= array_.size())
	{
		return false;
	}
	else
	{
		array_.erase(array_.cbegin() + pos);
		return true;
	}
}

template<typename T>
inline int snow::ArrayList<T>::find(const T& value) const
{
	for (int i = 0; i < array_.size(); i++)
	{
		if (array_[i] == value)
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
inline bool snow::ArrayList<T>::contains(const T& value) const
{
	return find(value) > -1;
}

template<typename T>
inline void ArrayList<T>::sort(IComparator<T>& comparator)
{
	for (int i = static_cast<int>(array_.size()); i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (comparator.compare(array_[j], array_[i]) > 1)
			{
				T tmp = array_[j];
				array_[j] = array_[i];
				array_[i] = tmp;
			}
		}
	}
}

template<typename T>
inline void ArrayList<T>::fromArray(T* array, int size)
{
	array_.clear();
	for (int i = 0; i < size; i++)
	{
		array_.push_back(array[i]);
	}
}

template<typename T>
inline T* ArrayList<T>::toArray() const
{
	T* res = new T[array_.size()];
	for (int i = 0; i < array_.size(); i++)
	{
		res[i] = array_[i];
	}
	return res;
}

template<typename T>
inline T& ArrayList<T>::operator[](int pos)
{
	if (pos < 0 || pos >= array_.size())
	{
		throw std::out_of_range("index out of bounds");
	}
	return *(array_.begin() + pos);
}

template<typename T>
inline const T& ArrayList<T>::operator[](int pos) const
{
	if (pos < 0 || pos >= array_.size())
	{
		throw std::out_of_range("index out of bounds");
	}
	return *(array_.cbegin() + pos);
}

template<typename T>
inline bool snow::ArrayList<T>::operator==(const ArrayList<T>& list) const
{
	if (array_.size() != list.array_.size())
	{
		return true;
	}
	else
	{
		for (int i = 0; i < array_.size(); i++)
		{
			if (!(array_[i] == list.array_[i]))
			{
				return false;
			}
		}
		return true;
	}
}

template<typename T>
inline bool snow::ArrayList<T>::operator!=(const ArrayList& list) const
{
	return !(*this == list);
}

template<typename T>
inline ArrayList<T> ArrayList<T>::operator=(const ArrayList<T>& list)
{
	array_ = list.array_;
	return *this;
}

}