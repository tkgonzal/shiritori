/*
WordBank.hpp
-Declares the WordBank class, a container of words that
can function as either: a container of words to be defined
as legal for a game of Shiritori or a container of words
that have already been played in the game and thus 
cannot be played again.

Traven 'tkgonzal' Gonzales 2019
*/


#ifndef WORD_BANK_HPP
#define WORD_BANK_HPP


#include <string>
#include <vector>
#include <fstream>
#include <iostream>


// The WordBank class defines an object meant to be a container
// of string objects which either represent words eligible for 
// play in a game of Shiritori or words that have already been
// played in the game. The use of each instance of a WordBank
// is determined by which constructor is called.
class WordBank
{
public:
	// CONSTRUCTORS
	WordBank(const std::string& fileName, unsigned int minLen);
	WordBank();

	// WORD PROCESSING
	bool search(std::string word);
	void insert(std::string word);

	// DEBUGGING
	void printWords();


private:
	// WordBank EDITING
	int determineIndex(std::string word);

	// PRIVATE MEMBERS
	unsigned int minLen;
	std::vector<std::string> words;
};


#endif

