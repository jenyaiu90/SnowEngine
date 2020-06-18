////////////////////////////////////////
//         After by SnegirSoft        //
//                                    //
//  File: CircularList.h              //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief File for CircularList class.
///
///	This file contains the declaration and the definition of the CircularList class.
////////////////////////////////////////////////////////////

#pragma once

#include "LinkedList.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief A template class that implements a circular linked list.
///
///	This class is used for creating a circular linked list. It provides faster adding and removing
///	elements but slower access to them than an array.
///
///	For fast passing through the list you can use a built-in iterator. Using a startIterate()
///	method sets iterator to the first element in the list. If the list is empty, this method
///	returns <b>false</b> Use an iterateNext() method for move the iterator to the next element.
///	This method	returns <b>false</b> if the startIterate() method wasn`t called. In the circular
///	list the iterateNext() method after the last element will point to the first element. A
///	getIterator() method returns a current element. A stopIterate() method clear the iterator.
///	\warning The remove() method and one of overloads of the add() method calls the stopIterate().
////////////////////////////////////////////////////////////
template<typename T>
class CircularList : public LinkedList<T>
{
public:

	////////////////////////////////////////////////////////////
	///	\brief The default constructor.
	///
	///	The default constructor creating an empty list.
	////////////////////////////////////////////////////////////
	CircularList();

	////////////////////////////////////////////////////////////
	///	\brief This constructor allows to copy a list.
	///
	///	Creates the copy of other list.
	///	\param list The source list.
	////////////////////////////////////////////////////////////
	CircularList(const CircularList<T>& list);

	////////////////////////////////////////////////////////////
	///	\brief Fills the linked list with values from an array.
	///
	///	Fills the list with values from an array.
	///	\param array The pointer to the array to copy.
	///	\param size The size of the array.
	////////////////////////////////////////////////////////////
	CircularList(T* array, int size);

	////////////////////////////////////////////////////////////
	///	\brief The destructor.
	///
	///	Removes all elements.
	////////////////////////////////////////////////////////////
	~CircularList();

	////////////////////////////////////////////////////////////
	///	\breif Adds a new element in the list.
	///
	///	This methos puts a new element before the begin of the list.
	///	\param item A new element.
	///	\return <b>true</b> if an element was successfully added. Doesn`t clear the iterator.
	////////////////////////////////////////////////////////////
	bool add(const T& item) override;

	////////////////////////////////////////////////////////////
	///	\brief Adds a new element in the list with passed index.
	///
	///	Puts a new element in the list with passed index. Clears the iterator.
	///	\param item A new element.
	///	\param pos An index.
	///	\return <b>true</b> if an element was successfullt added.
	////////////////////////////////////////////////////////////
	bool add(const T& item, int pos) override;

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
	bool add(const T& item, IComparator<T>& comparator) override;

	////////////////////////////////////////////////////////////
	///	\brief Removes an element with passed index from the list.
	///
	///	This method allows to remove an element from the list. Clears the iterator.
	///	\param pos An index of removing element.
	///	\return <b>true</b> if an element was successfully removed.
	////////////////////////////////////////////////////////////
	bool remove(int pos) override;

	////////////////////////////////////////////////////////////
	///	\brief The method allows to fill the list with values from an array.
	///
	///	Clears the list and fills it with values from an array.
	///	\param array The pointer to the array to copy.
	///	\param size The size of the array.
	////////////////////////////////////////////////////////////
	void sort(IComparator<T>& comparator) override;

	////////////////////////////////////////////////////////////
	///	\brief The method allows to fill the list with values from an array.
	///
	///	Clears the list and fills it with values from an array.
	///	\param array The pointer to the array to copy.
	///	\param size The size of the array.
	////////////////////////////////////////////////////////////
	void fromArray(T* array, int size) override;

	////////////////////////////////////////////////////////////
	///	\brief Gives an element of the list with passed index.
	///
	///	This method allows to get an access to an element of the list.
	///	\param pos An index.
	///	\return An address of the element.
	///	\throws std::out_of_range if an index is out of bounds.
	////////////////////////////////////////////////////////////
	T& operator[](int pos) const override;

	////////////////////////////////////////////////////////////
	///	\brief Copies a list.
	///
	///	Clears the list and pastes to it a content of another list. Doesn`t copy the positin of an
	///	iterator.
	///	\param list A list to copy.
	///	\return The list, that you can use, for example, for the construction below:
	///	\code
	///		CircularList<int> first;
	///		CircularList<int> second;
	///		CircularList<int> third;
	///		first.add(5);
	///
	///		third = second = first;
	///	\endcode
	////////////////////////////////////////////////////////////
	CircularList<T> operator=(const CircularList<T>& list);

	////////////////////////////////////////////////////////////
	///	\brief Sets the iterator to the next element.
	///
	///	Moves the iterator to the next element of the list.
	///	\return <b>false</b> if the iterator has reached the end of the list or the startIterate()
	///	method wasn`t called.
	////////////////////////////////////////////////////////////
	bool iterateNext() override;

};

// Below are the methods of the CircularList.

template<typename T>
CircularList<T>::CircularList() :
	begin_(nullptr),
	end_(nullptr),
	size_(0),
	iterator_(nullptr),
	iteratorPos_(-1)
{
}

template<typename T>
CircularList<T>::CircularList(const CircularList<T>& list)
{
	*this = list;
}

template<typename T>
CircularList<T>::CircularList(T* array, int size)
{
	fromArray(array, size);
}

template<typename T>
CircularList<T>::~CircularList()
{
	if (size_ > 0)
	{
		Note* p = begin_;
		for (int i = 0; i < size_ - 1; i++)
		{
			delete p->prev;
		}
		delete p;
	}
}

template<typename T>
bool CircularList<T>::add(const T& item)
{
	if (size_ == 0)
	{
		begin_ = new Note;
		begin_->prev = begin_;
		begin_->next = begin_;
		end_ = begin_;
	}
	else
	{
		begin_->prev->next = new Note;
		begin_->prev->next->prev = begin_;
		begin_->prev->next->next = begin_;
		begin_->prev = begin_->prev->next;
	}
	begin_->prev->item = item;
	size_++;
	return true;
}

template<typename T>
bool CircularList<T>::add(const T& item, int pos)
{
	if (pos < 0 || pos > size_)
	{
		return false;
	}
	else
	{
		if (size_ == 0)
		{
			return add(item);
		}
		else
		{
			Note* p = begin_;
			if (pos < size_ / 2)
			{
				for (int i = 0; i < pos; i++)
				{
					p = p->next;
				}
			}
			else
			{
				for (int i = 0; i < size_ - pos; i++)
				{
					p = p->prev;
				}
			}

			Note* newNote = new Note;
			newNote->prev = p->prev;
			newNote->next = p;
			p->prev->next = newNote;
			p->prev = newNote;
			newNote->item = item;
			if (pos == 0)
			{
				begin_ = begin_->prev;
			}
			stopIterate();
			size_++;
			return true;
		}
	}
}

template<typename T>
bool CircularList<T>::add(const T& item, IComparator<T>& comparator)
{
	if (size_ == 0)
	{
		return add(item);
	}
	else
	{
		if (comparator.compare(item, begin_->item) < 0)
		{
			return add(item, 0);
		}
		else
		{
			Note* p;
			for (p = begin_->next; p != begin_; p = p->next)
			{
				if (comparator.compare(p->item, item) > 0)
				{
					break;
				}
			}
			Note* newNote = new Note;
			newNote->prev = p->prev;
			newNote->next = p;
			p->prev->next = newNote;
			p->prev = newNote;
			newNote->item = item;
			stopIterate();
			size_++;
			return true;
		}
	}
}

template<typename T>
bool CircularList<T>::remove(int pos)
{
	if (pos < 0 || pos >= size_)
	{
		return false;
	}
	else
	{
		Note* p = begin_;
		if (pos < size_ / 2)
		{
			for (int i = 0; i < pos; i++)
			{
				p = p->next;
			}
		}
		else
		{
			for (int i = 0; i < size_ - pos; i++)
			{
				p = p->prev;
			}
		}
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		size_--;
		stopIterate();
		return true;
	}
}

template<typename T>
void snow::CircularList<T>::sort(IComparator<T>& comparator)
{
	Note* pi = begin_->prev;
	for (int i = size_ - 1; i > 0; i--)
	{
		Note* pj = begin_;
		for (int j = 0; j < i; j++)
		{
			if (comparator.compare(pj->item, pi->item) > 1)
			{
				Note* tmp = pi;
				pi = pj;
				pj = tmp;
			}
			pj = pj->next;
		}
		pi = pi->prev;
	}
}

template<typename T>
void CircularList<T>::fromArray(T* array, int size)
{
	this->~CircularList();
	for (int i = 0; i < size; i++)
	{
		add(array[i]);
	}
}

template<typename T>
T& CircularList<T>::operator[](int pos) const
{
	if (pos < 0 || pos >= size_)
	{
		throw std::out_of_range("index is out of bounds");
	}
	else
	{
		Note* p = begin_;
		if (pos < size_ / 2)
		{
			for (int i = 0; i < pos; i++)
			{
				p = p->next;
			}
		}
		else
		{
			for (int i = 0; i < size_ - pos; i++)
			{
				p = p->prev;
			}
		}
		return p->item;
	}
}

template<typename T>
CircularList<T> CircularList<T>::operator=(const CircularList<T>& list)
{
	this->~CircularList();
	iterator_ = nullptr;
	iteratorPos_ = -1;
	add(list.begin_->item);
	for (Note* p = list.begin_->next; p != list.begin_; p = p->next)
	{
		add(p->item);
	}
	return *this;
}

template<typename T>
bool CircularList<T>::iterateNext()
{
	if (iteratorPos_ < 0)
	{
		return false;
	}
	else
	{
		iterator_ = iterator_->next;
		if (iteratorPos_ == size_ - 1)
		{
			iteratorPos_ = 0;
		}
		else
		{
			iteratorPos_++;
		}
		return true;
	}
}

}