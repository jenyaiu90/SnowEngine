    ////////////////////////////////////////
   //      SnowEngine by SnegirSoft      //
  //                                    //
 //  File: Serializable.h              //
////////////////////////////////////////

#pragma once

#include <string>

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief The interface for classes that can be converted to string.
///	
///	Declares fromString and toString methods for classes that can be converte to and from string.
///	\warning The string shouldn`t contain '\n' symbols!
////////////////////////////////////////////////////////////
class ISerializable
{
public:

	virtual std::string toString() = 0;						///< Converts the object to a string.
	virtual void fromString(const std::string& str) = 0;	///< Converts the string to an object.

};

}