/*
RepeatWordException.hpp
-Declares and defines the RepeatWordException class, an
exception class meant to be raised whenever a player
tries to play a word that has already been played.

Traven 'tkwtph' Gonzales 2019
*/


#ifndef REPEAT_WORD_EXCEPTION_HPP
#define REPEAT_WORD_EXCEPTION_HPP


#include "ShiritoriException.hpp"


class RepeatWordException : public ShiritoriException
{
public:
	explicit RepeatWordException(std::string word)
		: ShiritoriException{word}
	{}

	virtual std::string get_message() override
	{
		std::ostringstream oss;
		oss << word << " has already been played!";
		return oss.str();
	}
};


#endif

