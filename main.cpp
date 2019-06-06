/**************************************************************************************************
** Program name:Program 03 - Zoo Tycoon
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/27/2018
** Description:	THIS IS THE MAIN FUNCTION OF PROGRAM 03 - ZOO TYCOON
**		This program is a game that simulates the day-to-day maintenance of a zoo. The user
**		takes the role as a Zoo's director. Before the program is run, the user must the
**		number of each animal they want in their zoo initally. Then, the user decides what
**		kind of food to feed their animals. A random event then is called, which depending
**		on the type of food, could lead to the death of one of their animals. At the end
**		of the day, the user can then purchae an adult animal and choose whether or not
**		to retire as the director, or continue. If the player's bank ever goes below 0, the
**		user has a Game-Over.
**		TO RUN: In terminal run the makefile using the "make" command and run the
**		executable file "main".
**************************************************************************************************/
// main.cpp
#include <iostream>

#include "Menu.hpp"
#include "Zoo.hpp"

int main()
{	
	// Create Menu	
	Menu menu;

	do
	{	
		// Run the Menu
		menu.run();
		if(menu.getPlay())
		{
			// Create Zoo Based on Menu Settings
			int tigers = menu.getNumTigers();
			int bears = menu.getNumBears();
			int penguins = menu.getNumPenguins();
			int turtles = menu.getNumTurtles();
			double bank = menu.getBank();

			Zoo segFaultZoo(tigers, bears, penguins, turtles, bank);

			// Run the Zoo
			segFaultZoo.open();

			// Ask the user if they want to play again
			menu.playAgain();
		}
	} while (menu.getPlay());

	return 0;
}
