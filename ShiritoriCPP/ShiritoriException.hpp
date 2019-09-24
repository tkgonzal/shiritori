/*
ShiritoriException.hpp
-Declares and defines the ShiritoriException class, the abstract base
class that many of the exceptions the Shiritori program utilizes
inherits from, wherein each exception is constructed with a string
object and provides a message relating as to how that string was
not accepted by the ShiritoriException class.

Traven 'tkwtph' Gonzales 2019
*/


#ifndef SHIRITORI_EXCEPTION_HPP
#define SHIRITORI_EXCEPTION_HPP


#include <sstream>


class ShiritoriException
{
protected:
	explicit ShiritoriException(std::string& word)
		: word{word}
	{
	}

	// MEMBER VARIABLES
	std::string word;


public:
	virtual ~ShiritoriException() = default;
	virtual std::string get_message() = 0;
};


#endif

