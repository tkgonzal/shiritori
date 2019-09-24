/*
main.cpp
-Ran in order to use Shiritori Program
-Shiritori is a Japanese word game where players take turns saying words
and each word must start with the last letter of the last word said. 
-This program implements an English variant of the word game. More in
depth rules can be seen when running the program and in the RULES variable
in Shiritori.hpp

Traven 'tkwtph' Gonzales 2019
*/


#include "Shiritori.hpp"
// #include "vld.h" // Visual Leak Detector used to check for memory leaks during developmemt


int main()
{
	Shiritori game;
	game.execute();
	system("pause");
	return 0;
}

