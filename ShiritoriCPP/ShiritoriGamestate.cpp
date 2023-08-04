/*
ShiritoriGamestate.cpp
-Defines the member functions of the ShiritoriGamestate class, 
a class meant to hold information pertaining to an English 
variant of the word game Shiritori.

Traven 'tkgonzal' Gonzales 2019
*/


#include "ShiritoriGamestate.hpp"


// --------Player DEFINITIONS--------
// CONSTRUCTORS
// Makes a new player by assigning them their name, starting them
// as part of the game and starting with 0 points
Player::Player(const std::string& name)
	: name{name}, inGame{true}, score{0}
{
}

// A default constructor that creates a blank player by assigning 
// them the empty string as their name and starting them in game
// and with 0 points (Made to allow for dynamic allocation of
// Player structures)
Player::Player()
	: name{""}, inGame{true}, score{0}
{
}

// PLAYER EDITING
// Adds a given number of points to a player's score
void Player::add_points(int points)
{
	score += points;
}

// Sets a player's inGame as false, eliminating them
void Player::eliminate()
{
	inGame = false;
}


// --------ShiritoriGamestate DEFINITIONS--------
// PUBLIC
// CONSTRUCTOR AND DESTRUCTOR
// Creates the a ShiritoriGamestate using a string as a file name
// and integer for a minimum length to initialize a WordBank which
// the gamestate will use to validate words given by players and 
// an array of player names and its length to create an array of 
// player structs which the gamestate will use to track player
// information
ShiritoriGamestate::ShiritoriGamestate(const std::string& fileName, unsigned int minGameLen, std::string* playerNames, unsigned int playerNo)
	: wordBank{fileName, MIN_WORD_LEN}, players{new Player[playerNo]}, playerNo{playerNo}, minLen{minGameLen}, remaining{playerNo}, last{' '}
{
	// last is started as a space character to signify the beginning of a game where the first player may play any
	// real word

	for (unsigned int i = 0; i < playerNo; i++)
		players[i] = Player{playerNames[i]};
}

// Frees the players array upon destruction of the gamestate
ShiritoriGamestate::~ShiritoriGamestate()
{
	delete[] players;
}

// GAMESTATE EDITING
// Given a pointer to a player and a word, attempts to play
// the word in the game by validating it, and processes the
// word upon validation.
void ShiritoriGamestate::playWord(Player* person, std::string word)
{
	if (validate(word))
	{
		awardPlayer(person, word);
		processWord(word);
	}
}

// Given a pointer to a player, sets the player as eliminated
// from the game, decreases the remaining member, and adds the
// player to the eliminated queue
void ShiritoriGamestate::eliminatePlayer(Player* player)
{
	player->eliminate();
	--remaining;
	eliminated.push(*player);
}

// To only be called when 1 player remains, ends the game by
// declaring the last player the winner and eliminating them
// so the game standings may be retrieved
void ShiritoriGamestate::finishGame()
{
	for (unsigned int i = 0; i < playerNo; i++)
		if (players[i].inGame)
			eliminatePlayer(&players[i]);
}

// GETTERS
// Returns the array of Player structs
Player* ShiritoriGamestate::getPlayers()
{
	return players;
}

// Returns the queue of Players that have been eliminated
std::stack<Player> ShiritoriGamestate::getEliminated()
{
	return eliminated;
}

// Returns whether the game has been won (i.e. one person
// remains
bool ShiritoriGamestate::gameOver()
{
	return remaining == 1;
}


// PRIVATE
// GAMESTATE EDITING
// Processes a validated word played in the gamestate
// by changing the last member to the last letter of 
// the word and adding the word to the usedWord member
void ShiritoriGamestate::processWord(std::string word)
{
	last = (char) std::tolower(word.back());
	usedWords.insert(word);
}

// Gives players point for succefully playing a word
// based on the length of the word played
void ShiritoriGamestate::awardPlayer(Player* player, std::string word)
{
	player->add_points(BASE_POINTS * word.size());
}

// WORD VALIDATION
// Either returns that a given word properly follows all of
// the rules of Shiritori, or throws an exception based on
// which rule it violates
bool ShiritoriGamestate::validate(std::string word)
{
	if (!isRealWord(word))
		throw UnrealWordException{word};
	else if (!isLongEnough(word))
		throw ShortWordExcpetion{word};
	else if (!matchesLetters(word))
		throw MismatchException{word, last};
	else if (!isUnique(word))
		throw RepeatWordException{ word };
	else
		return true;
}

// Returns whether or not a given word is real, determined by
// whether or not is in the wordBank of the gamestate.
bool ShiritoriGamestate::isRealWord(std::string word)
{
	return wordBank.search(word);
}

// Returns whether or not a given word meets the minimum length
// specified by the game
bool ShiritoriGamestate::isLongEnough(std::string word)
{
	return word.size() >= minLen;
}

// Returns whether or not a given word starts with the last letter
// of the last word played. The the last member is a space, the word
// played will be treated as the first word and will succesfully 
// be treated as matching
bool ShiritoriGamestate::matchesLetters(std::string word)
{
	if (last == ' ')
		return true;
	else
		return (char) std::tolower(word.front()) == last;
}

// Returns whether or not the word is in the usedWords WordBank
bool ShiritoriGamestate::isUnique(std::string word)
{
	return !usedWords.search(word);
}

