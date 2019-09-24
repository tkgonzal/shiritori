/*
ShiritoriGamestate.hpp
-Declares the ShiritoriGamestate class, a class meant to hold information
pertaining to an English variant of the game Shiritori.
-Declares also the Player struct, a structure meant to hold relevant player
info for players in the game such as their name, status, and score.

Traven 'tkwtph' Gonzales 2019
*/


#ifndef SHIRITORI_GAMESTATE_HPP
#define SHIRITORI_GAMESTATE_HPP


#include <cctype>
#include <stack>
#include "WordBank.hpp"
#include "ShortWordException.hpp"
#include "UnrealWordException.hpp"
#include "MismatchException.hpp"
#include "RepeatWordException.hpp"


struct Player
{
	// CONSTRUCTORS
	Player(const std::string& name);
	Player();

	// PLAYER EDITING
	void add_points(int points);
	void eliminate();

	// MEMBER VARIABLES
	std::string name;
	bool inGame; // Tells gamestate whether player has been eliminated
	int score;
};


class ShiritoriGamestate
{
public:
	// CONSTRUCTOR AND DESTRUCTOR
	ShiritoriGamestate(const std::string& fileName, unsigned int minGameLen, std::string* playerNames, unsigned int playerNo);
	~ShiritoriGamestate();

	// GAMESTATE EDITING
	void playWord(Player* person, std::string word);
	void eliminatePlayer(Player* player);
	void finishGame();

	// GETTERS
	Player* getPlayers();
	std::stack<Player> getEliminated();
	bool gameOver();

	// STATIC MEMBER VARIABLES
	const static unsigned int BASE_POINTS = 100;
	const static unsigned int MIN_WORD_LEN = 1;


private:
	// GAMESTATE HANDLING
	void processWord(std::string word);
	void awardPlayer(Player* player, std::string word);

	// WORD VALIDATION
	bool validate(std::string word);
	bool isRealWord(std::string word);
	bool isLongEnough(std::string word);
	bool matchesLetters(std::string word);
	bool isUnique(std::string word);

	// MEMBERS
	WordBank wordBank, usedWords;
	Player* players;
	std::stack<Player> eliminated;
	unsigned int playerNo, minLen, remaining; // remaining tells gamestate how many players are left in the game
	char last; // last member idetifies the last letter of the last word succesfully played
};


#endif

