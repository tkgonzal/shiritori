/*
TimeUpException.hpp
-Declares and defines the TimeUpException class, an exception class meant to be
thrown whenever the user takes to long in trying to play a word.

Traven 'tkwtph' Gonzales 2019
*/


#ifndef TIME_UP_EXCEPTION_HPP
#define TIME_UP_EXCEPTION_HPP


#include "ShiritoriException.hpp"


class TimeUpException : public ShiritoriException
{
public:
	explicit TimeUpException(std::string word)
		: ShiritoriException{word}
	{
	}

	virtual std::string get_message() override
	{
		std::ostringstream oss;
		oss << "Too bad slowpoke! Took to long to play " << word << "!";
		return oss.str();
	}
};


#endif

