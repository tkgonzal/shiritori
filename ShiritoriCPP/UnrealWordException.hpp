/*
UnrealWordException.hpp
-Declares and defines the UnrealWordException class, an exception class meant to 
be raised whenever the user tries to provide a word that cannot be found within 
the game's WordBank, making it considered "not real".

Traven 'tkwtph' Gonzales 2019
*/


#ifndef UNREAL_WORD_EXCEPTION_HPP
#define UNREAL_WORD_EXCEPTION_HPP


#include "ShiritoriException.hpp"


class UnrealWordException : public ShiritoriException
{
public:
	explicit UnrealWordException(std::string word)
		: ShiritoriException{ word }
	{
	}

	virtual std::string get_message() override
	{
		std::ostringstream oss;
		oss << word << " is not a real word!";
		return oss.str();
	}
};


#endif

