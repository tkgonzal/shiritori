/*
Shiritori.hpp
-Declares the Shiritori class, a class which facilitates a variant of the
game Shiritori (a Japanese word game), and its members.

Traven 'tkwtph' Gonzales 2019
*/


#ifndef SHIRITORI_HPP
#define SHIRITORI_HPP


#include <ctime>
#include <algorithm>
#include "ShiritoriGamestate.hpp"
#include "TimeUpException.hpp"


// STRING CONSTANTS
// WORDS_FILE source is an edited version of the corncob_lowercase.txt 
// from http://www.mieliestronk.com/corncob_lowercase.txt
const std::string WORDS_FILE = "corncob_lowercase (edited).txt";
const std::string RULES = "--------------------------------------------------------------------------------------------------\n"
"Welcome to shiritori--a Japanese word game meant to be played among friends!\n"
"The rules of the game are simple:\n"
"    -A player says a word and other players must continue the game by saying other words\n"
"    -All words must be at least four letters long\n"
"        -No player can simply change the tense of a word or make a word plural to make it longer\n"
"    -All words played be REAL words you can find in a dictionary\n"
"    -After the first player, the word played must start with the last letter of the last word\n"
"     played\n"
"    -All words must be unique, so you can't say a word someone else has already said\n"
"    -When it come to a player's turn to say a word, they have only 10 seconds\n"
"    -If any player violates any of these rules, they are eliminated and the game continues\n"
"     until only one player is left!\n"
"With that, let's get you all started playing the game!\n"
"--------------------------------------------------------------------------------------------------\n";


class Shiritori
{
public:
	// CONSTRUCTOR AND DESTRUCTOR
	Shiritori();
	~Shiritori();

	// GAME EXECUTION
	void execute();


private:
	// INPUT GATHERING
	unsigned int getNoOfPlayers();
	std::string* getPlayerNames();
	std::string getPlayerName(unsigned int index);
	std::string getWord();

	// INPUT CLEANING
	static void cleanWord(std::string& word);
	static void lowerString(std::string& word);
	static void strip(std::string& word);
	static void lstrip(std::string& word);
	static void rstrip(std::string& word);

	// DISPLAY
	void printStart();
	void printResults();

	// STATIC MEMBERS
	const static unsigned int MAX_PLAYER_COUNT = 4;
	const static unsigned int TIME_LIMIT = 10;
	const static unsigned int MIN_GAME_WORD_LEN = 4;

	// MEMBERS
	unsigned int playerNo;
	std::string* playerNames;
	ShiritoriGamestate gamestate;
};


#endif

