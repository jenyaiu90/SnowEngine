    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: LinkedList.h                //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief File for LinkedList class.
///
///	This file contains the declaration and the definition of the LinkedList class.
////////////////////////////////////////////////////////////

#pragma once

#include "List.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief A template class that implements a linked list.
///
///	This class is used for creating a linked list. It provides faster adding and removing elements
///	but slower access to them than an array.
///
///	For fast passing through the list you can use a built-in iterator. Using a startIterate() method
///	sets iterator to the first element in the list. If the list is empty, this method returns
///	<b>false</b> Use an iterateNext() method for move the iterator to the next element. This method
///	returns false if there is no next element. A getIterator() method returns a current element. A
///	stopIterate() method clear the iterator. For example, for print all elements of the list, you
///	can use the code below:
///	\code
///		LinkedList<int> list;
///		... // Filling in the list
///
///		if (list.startIterate()) // False if the list is empty
///		{
///			do
///			{
///				cout << list.getIterator() << " ";
///			} while (list.iterateNext()); // False if iterator points to the last element of the list
///		}
///	\endcode
///	\warning The remove() method and one of overloads of the add() method calls the stopIterate().
///	Don`t use them in cycles like above.
////////////////////////////////////////////////////////////
template<typename T>
class LinkedList : public IList<T>
{
public:

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
	///	\brief Fills the linked list with values from an array.
	///
	///	Fills the list with values from an array.
	///	\param array The pointer to the array to copy.
	///	\param size The size of the array.
	////////////////////////////////////////////////////////////
	LinkedList(T* array, int size);

	////////////////////////////////////////////////////////////
	///	\brief The destructor.
	///
	///	Removes all elements.
	////////////////////////////////////////////////////////////
	~LinkedList();

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
	/// \warning Use this method only for sorted or empty list. The SnowEngine doesn`t controle
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
	///	\brief The method allows to fill the linked list with values from an array.
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
	///	\brief Sets the iterator to the begin of the list.
	///
	///	If you want to use the iterator, you have to call this method firstly. It sets the iterator
	///	to the first element of the list.
	///	\return <b>true</b> if the list is not empty and the iterator was successfully set.
	////////////////////////////////////////////////////////////
	bool startIterate();

	////////////////////////////////////////////////////////////
	///	\brief Returns the element that the iterator points to.
	///
	///	Allows to get access to the element that the iterator points to.
	///	\return A current element.
	///	\throws std::logic_error if the startIterate() method wasn`t called.
	////////////////////////////////////////////////////////////
	T& getIterator();

	////////////////////////////////////////////////////////////
	///	\brief Returns the index of the element that the iterator points to.
	///	
	///	Allows to get the index of the element that the iterator points to now.
	///	\return The index of the element of iterator, if the startIterate() method wasn`t called
	///	returns -1.
	////////////////////////////////////////////////////////////
	int getIteratorPosition();

	////////////////////////////////////////////////////////////
	///	\brief Sets the iterator to the next element.
	///
	///	Moves the iterator to the next element of the list.
	///	\return <b>false</b> if the iterator has reached the end of the list or the startIterate()
	///	method wasn`t called.
	////////////////////////////////////////////////////////////
	bool iterateNext();

	////////////////////////////////////////////////////////////
	///	\brief Clears the iterator.
	///
	///	Resets the iterator.
	////////////////////////////////////////////////////////////
	void stopIterate();

private:
	struct Note
	{
		Note* prev;
		T item;
		Note* next;
	};
	Note* begin_;
	Note* end_;
	int size_;

	Note* iterator_;
	int iteratorPos_;
};

// Below are the methods of the LinkedList.

template<typename T>
LinkedList<T>::LinkedList()
{
	begin_ = nullptr;
	end_ = nullptr;
	size_ = 0;
	iterator_ = nullptr;
	iteratorPos_ = -1;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	*this = list;
}

template<typename T>
LinkedList<T>::LinkedList(T* array, int size)
{
	fromArray(array, size);
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	if (size_ > 1)
	{
		for (Note* i = begin_->next; i != nullptr; i = i->next)
		{
			delete i->prev;
		}
		delete end_;
	}
	else
	{
		delete begin_;
	}
}

template<typename T>
int LinkedList<T>::length() const
{
	return size_;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
	return size_ == 0;
}

template<typename T>
bool LinkedList<T>::add(const T& item)
{
	if (size_ == 0)
	{
		begin_ = new Note;
		begin_->prev = nullptr;
		end_ = begin_;
	}
	else
	{
		end_->next = new Note;
		end_->next->prev = end_;
		end_ = end_->next;
	}
	end_->item = item;
	end_->next = nullptr;
	size_++;
	return true;
}

template<typename T>
bool LinkedList<T>::add(const T& item, int pos)
{
	if (pos < 0 || pos > size_)
	{
		return false;
	}
	else
	{
		if (pos == 0)
		{
			Note* p = new Note;
			p->prev = nullptr;
			p->item = item;
			p->next = begin_;
			begin_->prev = p;
			begin_ = p;
		}
		else
		{
			Note* p;
			if (pos < size_ / 2)
			{
				p = begin_;
				p--;
				for (int i = 0; i < pos; i++)
				{
					p = p->next;
				}
			}
			else
			{
				p = end_;
				pos = size_ - pos;
				for (int i = 0; i < pos; i++)
				{
					p = p->prev;
				}
			}
			Note* tmp = new Note;
			tmp->item = item;
			tmp->prev = p;
			tmp->next = p->next;
			p->next->prev = tmp;
			p->next = tmp;
		}
		size_++;
		stopIterate();
		return true;
	}
}

template<typename T>
bool LinkedList<T>::add(const T& item, IComparator<T>& comparator)
{
	if (size_ == 0)
	{
		return add(item);
	}
	else
	{
		if (comparator.compare(item, begin_->item) < 0)
		{
			Note* p = new Note;
			p->prev = nullptr;
			p->item = item;
			p->next = begin_;
			begin_->prev = p;
			begin_ = p;
		}
		else
		{
			Note* p;
			for (p = begin_; p->next != nullptr; p = p->next)
			{
				if (comparator.compare(p->item, item) < 0)
				{
					break;
				}
			}
			Note* newNote = new Note;
			newNote->prev = p;
			newNote->item = item;
			newNote->next = p->next;
			p->next = newNote;
			if (newNote->next != nullptr)
			{
				newNote->next->prev = newNote;
			}
		}
		size_++;
		return true;
	}
}

template<typename T>
bool LinkedList<T>::remove(int pos)
{
	if (pos < 0 || pos >= size_)
	{
		return false;
	}
	else
	{
		Note* p;
		if (pos < size_ / 2)
		{
			p = begin_;
			for (int i = 0; i < pos; i++)
			{
				p = p->next;
			}
		}
		else
		{
			p = end_;
			pos = size_ - pos - 1;
			for (int i = 0; i < pos; i++)
			{
				p = p->prev;
			}
		}
		Note* prev = p->prev;
		Note* next = p->next;
		if (prev != nullptr)
		{
			prev->next = next;
		}
		if (next != nullptr)
		{
			next->prev = prev;
		}
		delete p;
		size_--;
		stopIterate();
		return true;
	}
}

template<typename T>
void snow::LinkedList<T>::sort(IComparator<T>& comparator)
{
	for (Note* i = end_; i != begin_; i = i->prev)
	{
		for (Note* j = begin_; j != i; j = j->next)
		{
			if (comparator.compare(j->item, i->item) > 1)
			{
				Note* tmp = i;
				i = j;
				j = tmp;
			}
		}
	}
}

template<typename T>
void LinkedList<T>::fromArray(T* array, int size)
{
	this->~LinkedList();
	for (int i = 0; i < size; i++)
	{
		add(array[i]);
	}
}

template<typename T>
T* snow::LinkedList<T>::toArray() const
{
	T* res = new T[size_];
	for (int i = 0; i < size_; i++)
	{
		static Note* p = begin_;
		res[i] = p->item;
		p = p->next;
	}
	return res;
}

template<typename T>
T& LinkedList<T>::operator[](int pos) const
{
	if (pos < 0 || pos >= size_)
	{
		throw std::out_of_range("index is out of bounds");
	}
	else
	{
		Note* p;
		if (pos < size_ / 2)
		{
			p = begin_;
			for (int i = 0; i < pos; i++)
			{
				p = p->next;
			}
		}
		else
		{
			p = end_;
			pos = size_ - pos - 1;
			for (int i = 0; i < pos; i++)
			{
				p = p->prev;
			}
		}
		return p->item;
	}
}

template<typename T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList<T>& list)
{
	~LinkedList();
	iterator_ = nullptr;
	iteratorPos_ = -1;
	for (Note* p = list.begin_; p != nullptr; p = p->next)
	{
		add(p->item);
	}
	return *this;
}

template<typename T>
bool LinkedList<T>::startIterate()
{
	if (size_ > 0)
	{
		iterator_ = begin_;
		iteratorPos_ = 0;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
T& LinkedList<T>::getIterator()
{
	if (iteratorPos_ > -1)
	{
		return iterator_->item;
	}
	else
	{
		throw std::logic_error("iterate wasn`t started");
	}
}

template<typename T>
int LinkedList<T>::getIteratorPosition()
{
	return iteratorPos_;
}

template<typename T>
bool LinkedList<T>::iterateNext()
{
	if (iteratorPos_ < 0 || iteratorPos_ >= size_ - 1)
	{
		return false;
	}
	else
	{
		iterator_ = iterator_->next;
		iteratorPos_++;
		return true;
	}
}

template<typename T>
void LinkedList<T>::stopIterate()
{
	iterator_ = nullptr;
	iteratorPos_ = -1;
}

}