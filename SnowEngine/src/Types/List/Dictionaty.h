    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Dictionary.h                //
////////////////////////////////////////

#pragma once

#include <stdexcept>

#include "ArrayList.h"

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The container that has a key-value pairs.
///	
///	The Dictionary allows you to create a key-value pairs. The first template argument is the key
///	type, the second is the value type. You can use other containers as key or value.
///	\warning The template parameters must define operator ==.
////////////////////////////////////////////////////////////
template<typename K, typename V>
class Dictionary
{
public:

	////////////////////////////////////////////////////////////
	///	\brief Returns the list of all keys.
	///	
	///	Allows to get the list of all keys of the dictionary.
	///	\return The ArrayList with the keys.
	////////////////////////////////////////////////////////////
	const ArrayList<K>& getKeys() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the list of all values.
	///	
	///	Allows to get the list of all values of the dictionary.
	///	\return The ArrayList with the values.
	////////////////////////////////////////////////////////////
	const ArrayList<V>& getValues() const;

	////////////////////////////////////////////////////////////
	///	\brief Finds the key in the dictionary.
	///	
	///	Allows to check whether passed key is in the dictionary and get its ID.
	///	\param key The key to searching.
	///	\return Id of passed key or <b>-1</b> if this key doesn`t exits.
	////////////////////////////////////////////////////////////
	int findKey(const K& key) const;

	////////////////////////////////////////////////////////////
	///	\brief Finds the value in the dictionary.
	///	
	///	Allows to get the key of the value.
	///	\param value The value for searching.
	///	\return The pointer to the key of the value, nullptr if the dictionary doesn`t contain
	///	the value.
	////////////////////////////////////////////////////////////
	const K* find(const V& value) const;

	////////////////////////////////////////////////////////////
	///	\brief Sets the value with the key.
	///	
	///	Sets passed value with passed key. If there is an other value with such key, it overrides
	///	it.
	///	\param key The key of new value.
	///	\param value The value for setting.
	///	\return <b>true</b> if the value was successfully set.
	////////////////////////////////////////////////////////////
	bool set(const K& key, V value);

	////////////////////////////////////////////////////////////
	///	\brief Removes the value with passed key.
	///	
	///	This methos removes the value that is associated with passed key.
	///	\param key The key of removing element.
	///	\return <b>true</b> if the element was successfully removed.
	////////////////////////////////////////////////////////////
	bool remove(const K& key);

	////////////////////////////////////////////////////////////
	///	\brief Returns the value with passed key.
	///	
	///	Allows to get the value of the item with passed key. Is equal to operator[].
	///	\param key The key.
	///	\return The value with passed key.
	///	\throw std::out_of_range if there is no value with passed key.
	////////////////////////////////////////////////////////////
	V& get(const K& key);

	////////////////////////////////////////////////////////////
	///	\brief Returns the value with passed key.
	///	
	///	Allows to get the value of the item with passed key. Is equal to operator[].
	///	\param key The key.
	///	\return The value with passed key.
	///	\throw std::out_of_range if there is no value with passed key.
	////////////////////////////////////////////////////////////
	const V& get(const K& key) const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the value with passed key.
	///	
	///	Allows to get the value of the item with passed key. Is equal to get() method.
	///	\param key The key.
	///	\return The value with passed key.
	///	\throw std::out_of_range if there is no value with passed key.
	////////////////////////////////////////////////////////////
	V& operator[](const K& key);

	////////////////////////////////////////////////////////////
	///	\brief Returns the value with passed key.
	///	
	///	Allows to get the value of the item with passed key. Is equal to get() method.
	///	\param key The key.
	///	\return The value with passed key.
	///	\throw std::out_of_range if there is no value with passed key.
	////////////////////////////////////////////////////////////
	const V& operator[](const K& key) const;

	////////////////////////////////////////////////////////////
	///	\brief Return <b>true</b> if two dictionaries are equal.
	///	
	///	Checks whether two dictionaries are equal. They are equal when their elements are equal.
	///	\param dictionary Other dictionary.
	///	\return <b>true</b> if lists are equal.
	////////////////////////////////////////////////////////////
	bool operator==(const Dictionary& dictionary) const;

	////////////////////////////////////////////////////////////
	///	\brief Removes the value with passed id.
	///	
	///	This methos removes the value that is associated with a key with passed id. Works faster
	///	than remove().
	///	\param id The id of removing element.
	///	\return <b>true</b> if the element was successfully removed.
	////////////////////////////////////////////////////////////
	bool removeById(int id);

	////////////////////////////////////////////////////////////
	///	\brief Returns the value with passed id.
	///	
	///	Allows to get the value of the item with passed id. Works faster than get() of operator[].
	///	\param id The id.
	///	\return The value with passed id.
	///	\throw std::out_of_range if there is no value with passed key.
	////////////////////////////////////////////////////////////
	V& getById(int id);

	////////////////////////////////////////////////////////////
	///	\brief Returns the value with passed id.
	///	
	///	Allows to get the value of the item with passed id. Works faster than get() of operator[].
	///	\param id The id.
	///	\return The value with passed id.
	///	\throw std::out_of_range if there is no value with passed key.
	////////////////////////////////////////////////////////////
	const V& getById(int id) const;

protected:

	ArrayList<K> keys_;
	ArrayList<V> values_;

};

}

// Below are the methods of the Dictionary

template<typename K, typename V>
const snow::ArrayList<K>& snow::Dictionary<K, V>::getKeys() const
{
	return keys_;
}

template<typename K, typename V>
const snow::ArrayList<V>& snow::Dictionary<K, V>::getValues() const
{
	return values_;
}

template<typename K, typename V>
int snow::Dictionary<K, V>::findKey(const K& key) const
{
	return keys_.find(key);
}

template<typename K, typename V>
const K* snow::Dictionary<K, V>::find(const V& value) const
{
	int index = values_.find(value);
	if (index == -1)
	{
		return nullptr;
	}
	else
	{
		return &keys_[index];
	}
}

template<typename K, typename V>
bool snow::Dictionary<K, V>::set(const K& key, V value)
{
	int index = keys_.find(key);
	if (index == -1)
	{
		keys_.add(key);
		values_.add(value);
	}
	else
	{
		values_[index] = value;
	}
	return true;
}

template<typename K, typename V>
bool snow::Dictionary<K, V>::remove(const K& key)
{
	int index = keys_.find(key);
	return keys_.remove(index) & values_.remove(index);
}

template<typename K, typename V>
V& snow::Dictionary<K, V>::get(const K& key)
{
	int index = keys_.find(key);
	if (index == -1)
	{
		throw std::out_of_range("dictionaty doesn`t have this key");
	}
	else
	{
		return values_[index];
	}
}

template<typename K, typename V>
const V& snow::Dictionary<K, V>::get(const K& key) const
{
	int index = keys_.find(key);
	if (index == -1)
	{
		throw std::out_of_range("dictionaty doesn`t have this key");
	}
	else
	{
		return values_[index];
	}
}

template<typename K, typename V>
V& snow::Dictionary<K, V>::operator[](const K& key)
{
	return get(key);
}

template<typename K, typename V>
const V& snow::Dictionary<K, V>::operator[](const K& key) const
{
	return get(key);
}

template<typename K, typename V>
inline bool snow::Dictionary<K, V>::operator==(const snow::Dictionary<K, V>& dictionary) const
{
	return keys_ == dictionary.keys_ && values_ == dictionary.values_;
}

template<typename K, typename V>
bool snow::Dictionary<K, V>::removeById(int id)
{
	return keys_.remove(id) & values_.remove(id);
}

template<typename K, typename V>
V& snow::Dictionary<K, V>::getById(int id)
{
	if (id < 0 || id >= keys_.length())
	{
		throw std::out_of_range("Passed id is out of range");
	}
	else
	{
		return values_[id];
	}
}

template<typename K, typename V>
const V& snow::Dictionary<K, V>::getById(int id) const
{
	if (id < 0 || id >= keys_.length())
	{
		throw std::out_of_range("Passed id is out of range");
	}
	else
	{
		return values_[id];
	}
}