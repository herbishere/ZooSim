/**************************************************************************************************
** Program name:Program 02 - Zoo Tycoon
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/27/2018
** Description: THIS IS THE HEADER FILE OF THE MENU CLASS
**		This program is a game that simulates the day-to-day maintenance of a zoo. The user
**		takes the role as a Zoo's director. Before the program is run, the user must the
**		number of each animal they want in their zoo initally. Then, the user decides what
**		kind of food to feed their animals. A random event then is called, which depending
**		on the type of food, could lead to the death of one of their animals. At the end
**		of the day, the user can then purchae an adult animal and choose whether or not
**		to retire as the director, or continue. If the player's bank ever goes below 0, the
**		user has a Game-Over.
**		ABSTRACTION OF:	The Menu of the Program
**		PURPOSE:	This class provides an interface for users to interact with and
**				determine the settings of the program. Also validates user inputs.
**		HOW TO USE:	Create a menu object using the default constructor
**		SUMMARY:	The default constructor initalizes the number of each animal to 0
**				and sets the play data member to true.
**				The run() function displays multiple menus to the user, validates
**				the users responses, and sets relevant data members in accordance
**				to user input.
**				The playAgain() function asks the user if they want to play again,
**				gets and validates the user's input, and sets the play data member.
**				The get function return the values of their relevant data members.
**************************************************************************************************/
// Menu.hpp
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "P2Constants.hpp"

using std::cin;
using std::cout;

class Menu
{
	private:
		// Private Data Members
		bool play;		// Determines whether to continue the program or quit
		double bank;		// Holds current amount of money inside the bank
		int numTigers;		// Holds the initial number of tigers in the zoo
		int numPenguins;	// Holds the initial number of penguins in the zoo
		int numTurtles;		// Holds the inital number of turtles in the zoo
		int numBears;		// Holds the inital number of bears in the zoo
		// Utility Functions
		bool checkEmpty();
		void cleanInput();
		double calcBank();
		// Private Helper Functions
		// 	Display Functions
		void dispMenu();
		void dispConfig();
		void queryAnimals(int);
		void queryQuit();
		// 	Input Validation Functions
		void validateMenu();
		int validateConfig();
		void validateAnimal(int);
	public:
		Menu();			// Default Constructor
		void run();		// Combines helper functions into 1 function
		void playAgain();	// Asks and validates user input about the play member variable
		// Get Functions
		bool getPlay();
		double getBank();
		int getNumTigers();
		int getNumBears();
		int getNumPenguins();
		int getNumTurtles();
};

#endif
