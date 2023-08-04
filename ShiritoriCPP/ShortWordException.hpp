/*
ShortWordException.hpp
-Declares and defines the ShortWordException class, an exception meant to be thrown
whenever a player attempts to play a word that is too short in a game of Shiritori.

Traven 'tkgonzal' Gonzales 2019
*/


#ifndef SHORT_WORD_EXCEPTION_HPP
#define SHORT_WORD_EXCEPTION_HPP


#include "ShiritoriException.hpp"


class ShortWordExcpetion : public ShiritoriException
{
public:
	explicit ShortWordExcpetion(std::string& word)
		: ShiritoriException{word}
	{
	}

	virtual std::string get_message() override
	{
		std::ostringstream oss;
		oss << word << " is only " << word.length() << " letters long!";
		return oss.str();
	}
};


#endif

