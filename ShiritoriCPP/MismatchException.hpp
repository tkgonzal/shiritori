/*
MismatchException.hpp
-Declares and defines the MismatchException class, an exception class meant to be
thrown whenever a player tries to play a word that does not start with the last 
letter of the last word played.

Traven 'tkwtph' Gonzales 2019
*/


#ifndef MISMATCH_EXCEPTION_HPP
#define MISMATCH_EXCEPTION_HPP


#include "ShiritoriException.hpp"


class MismatchException : public ShiritoriException
{
public:
	explicit MismatchException(std::string& word, char last)
		: ShiritoriException{word}, last{last}
	{
	}

	virtual std::string get_message() override
	{
		std::ostringstream oss;
		oss << word << " does not start with the letter " << last << "!";
		return oss.str();
	}


private:
	char last;
};


#endif

