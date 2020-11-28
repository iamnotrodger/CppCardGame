# Card Game
- Team Members:
  - Rodger Retanal - 300052309
  - Patric Huang - 300097191

This is a card game. 

## Compiling
g++ -std=c++11 src/main.cpp src/cards/*.cpp

## Starting a New Game
To start a new game simply run the compiled file.
- Example:
  - ./a.out

## Loading a Game
To load a game, run the compiled file along with a command-line argument which directs to a saved file of the game.
- Example:
  - ./a.out saved_file.txt
  
## Saving a Game
The program will ask you if you want to save a game at the end of every turn. The game will be saved into a '.txt' file.
