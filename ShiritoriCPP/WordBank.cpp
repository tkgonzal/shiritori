/*
WordBank.cpp
-Defines the WordBank class, a container of words that are either 
to be considered legal in a game of Shiritori or have already been 
played in the game, and its members.

Traven 'tkgonzal' Gonzales 2019
*/


#include "WordBank.hpp"


// PUBLIC

// CONSTRUCTORS
// Initializes a WordBank given a file name and minimum length by 
// iterating through each line in the file and adding the string
// on the line if it's length is greater than or equal to the
// given minimum length
WordBank::WordBank(const std::string& fileName, unsigned int minLen)
	: minLen{minLen}
{
	std::ifstream wordsFile{fileName};
	std::string word;

	while (std::getline(wordsFile, word))
		if (word.length() >= minLen)
			insert(word);

	wordsFile.close();
}

WordBank::WordBank()
{
}

// WORD PROCESSING
// Returns whether or not a given word is in the WordBank
bool WordBank::search(std::string word)
{
	int index = determineIndex(word);
	if (words.size() > 0 && index < words.size())
		return words[determineIndex(word)] == word;
	else
		return false;
}

// Inserts a word into the WordBank's words vector in alphabetical
// order
void WordBank::insert(std::string word)
{
	auto wordsStart = words.begin();
	unsigned int insertIndex = determineIndex(word);
	words.insert(wordsStart + insertIndex, word);
}

// DEBUGGING
// Prints all words stored in the WordBank (Used primarily for
// debugging purposes)
void WordBank::printWords()
{
	for (std::string word : words)
		std::cout << word << std::endl;
}


// PRIVATE
// WORD PROCESSING
// Determines the proper index for a word in a WordBank's words vector
// using binary search
int WordBank::determineIndex(std::string word)
{
	int min = 0;
	int max = (int) words.size() - 1;
	int mid;

	while (min <= max)
	{
		mid = min + (max - min) / 2;
		if (word < words[mid])
			max = mid - 1;
		else if (word > words[mid])
			min = mid + 1;
		else
			return mid;
	}
	return min;
}

