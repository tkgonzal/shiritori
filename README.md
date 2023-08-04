# Shiritori
A C++ command line game for an English variant of the Japanese word game Shiritori, where players take turns rapdily saying words that start with the last letter of the last word said. Whoever does not say a word starting with the last letter of the last word, does not say a word fast enough, or does not say a real word, is eliminated. The last player standing is the winner.

## Usage
The game can be played by using the ***ShiritoriCPP.exe*** file in the *Debug* folder. 

Specific rules are shown when the game starts (but are basically as described in the previous section). In order to play, the players must specify how many of them there are, and enter their names. Afterwards, gameplay starts with the first player giving a word starting with any letter, and continues with the described rules with the last player remaining winning. 

Players are also given scores at the end based on the length of the words they played, where the scored is the total length of all valid words they played x100. Though the scores are weighted based on how long of words the players play, ultimately the final standings are only determined by how long each player lasted in the game.

**IMPORTANT:** In order to play the game, the ***ShiritoriCPP.exe*** file must be in the same folder as the ***corncob_lowercase (edited).txt*** file, otherwise the game will not have a wordbank from which to determine if words played are considered "real"

## Dev Notes
This project was largely a practice in implementing a game loop structure in C++, a language that I had far less experience with at the time. I also used the development of the game as a chance to practice using the binary search algorithm, as I used it in my WordBank data structure for both loading in words for the WordBank and determining if a given word existed in it. Though the game lacks a GUI, it still acted as a fun time killer whenever friends and I were bored in college.

If I could come back to this app, I think the main things I would change would be to give it a GUI and some sort of way to play against other players online with some kind of networking feature. A minor thing I would also like to change would be creating my own file for the WordBank, or implementing some type of feature to allow players to provide their own for the game. As it stands, it rubs me a bit wrong using someone else's file for my project, and the file itself is definitely not as comprehensive as I initially thought it would be when I developed the app (though I doubt the file's orignal purpose was to be a complete english dictionary).

## Credits
* The file **corncob_lowercase (edited).txt** is a modified version of
the file [corncob_lowercase.txt](https://github.com/pjackowski/passphrase-gen/blob/master/corncob-lowercase.txt) from a passphrase generator project I found. It is used as the wordbank for the game and is edited to contain random words I found amusing at the time of development.