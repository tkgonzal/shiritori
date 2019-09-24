/*
Shiritori.cpp
-Defines the Shiritori class and its members. The Shiritori class is meant
to facilitate an English variant of the Japanese Word game, Shiritori. Rules
of the game are explained within the RULES constant in Shiritori.hpp.

Traven 'tkwtph' Gonzales 2019
*/


#include "Shiritori.hpp"


// PUBLIC
// CONSTRUCTOR AND DESTRUCTOR
// Creates a Shiritori object and makes a cin stream in order to
// retrieve information needed for a game of Shiritori. After th
// necessary input is collected, a gamestate for the game is
// created
Shiritori::Shiritori()
	: playerNo{getNoOfPlayers()}, playerNames{getPlayerNames()}, gamestate{WORDS_FILE, MIN_GAME_WORD_LEN, playerNames, playerNo}
{
}

// Frees the playerNames member
Shiritori::~Shiritori()
{
	delete[] playerNames;
}

// GAME EXECUTION
// Facilitates the game of Shiritori by going through each player,
// having them attempt to play a word if they are in game, and
// processing their input accordingly: either validating their word
// and updating the gamestate accordingly or eliminating the player
// and carrying on with the game
void Shiritori::execute()
{
	Player* players = gamestate.getPlayers();
	std::cout << std::endl << "--------GAME START!--------" << std::endl;

	while (true)
	{
		for (unsigned int i = 0; i < playerNo; i++)
		{
			Player* cur_player = &players[i];

			if (cur_player->inGame)
			{
				try
				{
					std::cout << cur_player->name << "'s turn; Enter word: ";
					std::string playerWord = getWord();
					cleanWord(playerWord);
					gamestate.playWord(cur_player, playerWord);
				}
				catch (ShiritoriException& e)
				{
					std::cout << e.get_message() << std::endl;
					gamestate.eliminatePlayer(cur_player);
					std::cout << cur_player->name << " eliminated!" << std::endl;
				}
			}
			if (gamestate.gameOver())
				break;
		}

		if (gamestate.gameOver())
		{
			gamestate.finishGame();
			break;
		}
	}

	printResults();
}


// PRIVATE
// INPUT GATHERING
// Retrieves the number of players for the game (must be in the range
// [2, MAX_PLAYER_COUNT])
unsigned int Shiritori::getNoOfPlayers()
{
	// Called here so game info is shown before data retrieval
	printStart();
	std::string input;
	int no;

	do
	{
		std::cout << "Please enter number of players: ";
		std::getline(std::cin, input);
		std::stringstream ss{input};

		if (ss >> no)
		{
			if (ss.eof())
			{
				if (no <= 0)
					std::cout << "Please enter a positive number." << std::endl;
				else if (no == 1)
					std::cout << "You can't play this by yourself!" << std::endl;
				else if (no > MAX_PLAYER_COUNT)
					std::cout << "The max number of players is " << MAX_PLAYER_COUNT << "!" << std::endl;
				else
					break;
			}
		}
		else
			std::cout << "That's not a number!" << std::endl;
	} 
	while (true);

	return (unsigned int) no;
}

// Retrieves the names to be used for the roster of a game of
// Shiritori
std::string* Shiritori::getPlayerNames()
{
	std::string* result = new std::string[playerNo];
	for (unsigned int i = 0; i < playerNo; ++i)
		result[i] = getPlayerName(i);
	return result;
}

// Retrieves name to be used for a player in the game
std::string Shiritori::getPlayerName(unsigned int index)
{
	std::string name;
	std::cout << "Player " << index + 1 << ", please enter name: ";
	std::getline(std::cin, name);
	return name;
}

// Gets a player's word for their turn. Throws an exception if
// they take too long to input their word
std::string Shiritori::getWord()
{
	std::time_t start = std::time(nullptr);
	std::string input;

	std::getline(std::cin, input);
	
	if (difftime(time(nullptr), start) > TIME_LIMIT)
		throw TimeUpException{input};

	return input;
}

// INPUT CLEANING
// Cleans a word to be processed by the gamestate
// by stripping whitespace from its left and right
// and making all letters appearing within the word
// lowercase if possible
void Shiritori::cleanWord(std::string& word)
{
	strip(word);
	lowerString(word);
}

// Makes a string all lowercase
// Adapted from Not So Freqeuently Asked Questions
// https://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/
void Shiritori::lowerString(std::string& word)
{
	std::transform(word.begin(), word.end(), word.begin(), std::tolower);
}

// Strips whitespace from the left and right of a string
// Adapted from a stackoverflow question
// https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
void Shiritori::strip(std::string& word)
{
	lstrip(word);
	rstrip(word);
}

// Strips whitespace from the left of a string
// Adapted from a stackoverflow question
// https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
void Shiritori::lstrip(std::string& word)
{
	word.erase(word.begin(), std::find_if(word.begin(), word.end(),
		[](int ch) { return !std::isspace(ch); }));
}

// Strips whitespace from the left of a string
// Adapted from a stackoverflow question
// https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
void Shiritori::rstrip(std::string& word)
{
	word.erase(std::find_if(word.rbegin(), word.rend(),
		[](int ch) { return !std::isspace(ch); }).base(), word.end());
}

// DISPLAY
// Prints the title of the game and its rules
void Shiritori::printStart()
{
	std::cout << "--------SHIRITORI--------" << std::endl;
	std::cout << RULES << std::endl;
}

// Prints the results of a finished game, printing out the players
// in order of who lasted the longest along with their score
void Shiritori::printResults()
{
	std::cout << std::endl << "--------RESULTS--------" << std::endl;
	std::stack<Player> results = gamestate.getEliminated();

	for (unsigned int i = 1; i <= playerNo; ++i)
	{
		Player cur_player = results.top();
		results.pop();

		std::cout << "\t" << i << ". " << cur_player.name << " - "
			<< cur_player.score << std::endl;
	}

	std::cout << std::endl;
}

