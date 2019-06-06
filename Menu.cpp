/**************************************************************************************************
** Program name:Program 02 - Zoo Tycoon
** Author:      Herbert Diaz <diazh@oregonstate.edu>
** Date:        1/27/2018
** Description: THIS IS THE IMPLEMENTATION FILE FOR THE MENU CLASS
**		This program is a game that simulates the day-to-day maintenance of a zoo. The user
**		takes the role as a Zoo's director. Before the program is run, the user must the
**		number of each animal they want in their zoo initally. Then, the user decides what
**		kind of food to feed their animals. A random event then is called, which depending
**		on the type of food, could lead to the death of one of their animals. At the end
**		of the day, the user can then purchae an adult animal and choose whether or not
**		to retire as the director, or continue. If the player's bank ever goes below 0, the
**		user has a Game-Over.
**************************************************************************************************/
// Menu.cpp
#include "Menu.hpp"

/**************************************************************************************************
** Description:	Menu();						 	 **PUBLIC::2019.01.27::HD**
**		This is the default constructor for the Menu Class.	 **************************
**************************************************************************************************/
Menu::Menu()
{
	bank = BANK_DEFAULT;
	numTigers = numPenguins = numTurtles = numBears = 0;
	play = true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///	== UTILITY FUNCTIONS == UTILITY FUNCTIONS == UTILITY FUNCTIONS == UTILITY FUNCTIONS ==	///
///////////////////////////////////////////////////////////////////////////////////////////////////


/**************************************************************************************************
** Description: checkEmpty();						**PRIVATE::2019.01.27::HD**
**              This function checks to see if there are 0 of any	***************************
**		animal and returns true if it empty.
**************************************************************************************************/
bool Menu::checkEmpty()
{
	if (numTigers == 0 || numBears == 0 || numPenguins == 0 || numTurtles == 0)
	{	return true;
	}
	else
	{	return false;
	}
}

/**************************************************************************************************
** Description:	cleanInput();						**PRIVATE::2019.01.27::HD**
**		This function clears the input and ignores characters	***************************
**		Used in input validation functions.
**************************************************************************************************/
void Menu::cleanInput()
{
	cin.clear();
	cin.ignore(IGNORE_NUMF,'\n');
}

/**************************************************************************************************
** Description: calcBank();						**PRIVATE::2019.01.27::HD**
**              This function calculates the remaining amount of money  ***************************
**              in the bank.
**************************************************************************************************/
double Menu::calcBank()
{
	return 	BANK_DEFAULT -	((numTigers * COST_TIGER) + (numPenguins * COST_PENGUIN) + 
				(numTurtles * COST_TURTLE) + (numBears * COST_BEAR));
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///	== DISPLAY FUNCTIONS ==	DISPLAY FUNCTIONS == DISPLAY FUNCTIONS == DISPLAY FUNCTIONS ==	///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description: dispMenu();						**PRIVATE::2019.01.27::HD**
**              This function displays the main menu of the program.	***************************
**************************************************************************************************/
void Menu::dispMenu()
{
	cout << "\n== CS162 == PROGRAM02 == ZOO TYCOON == HERBERT DIAZ ==ExCred1+2+3_attempted==\n";
	cout << "\nPROGRAM INFORMATION:\n";
	cout << "	This Program is a simulation of owning a zoo.\n";
	cout << "	-->This Zoo has 4 Animals: Tigers, Penguins, Turtles, and Bears.\n";
	cout << "	-->You will begin $100k and you must purchase 1 or 2 of each animal.\n";
	cout << "	EACH DAY and food is purchased for the  animals. RANDOM EVENT may occur.\n";
	cout << "	RANDOM EVENTS could lead to BONUS MONEY, ANIMAL DEATH, OR ANIMALS BORN.\n";
	cout << "	These animals can reproduce via Miosis, so no mating pair is needed.\n";
	cout << "	After end of the day, players can RETIRE or CONTINUE to the next day.\n";
	cout << "	If the players BANK ever reaches 0, it is GAME OVER.\n\n";
	cout << "Would You Like to:\n";
	cout << "	[1] PLAY GAME\n";
	cout << "	[2] QUIT GAME\n";
}

/**************************************************************************************************
** Description: dispConfig();						**PRIVATE::2019.01.27::HD**
**              This function displays the configuration menu.		***************************
**************************************************************************************************/
void Menu::dispConfig()
{

	cout << "\n=============================================================================\n";
	cout << "\nBANK BALANCE:	$" << calcBank() << "\n\n";
	cout << "You have:";
	cout << "\n	" << numTigers << " Tigers";
	if (numTigers == 0)
	{	cout << "	[!] WARNING: NEED AT LEAST 1 TIGER";
	}
	cout << "\n	" << numBears << " Bears";
	if (numBears == 0)
	{	cout << "		[!] WARNING: NEED AT LEAST 1 BEAR";
	}
	cout << "\n	" << numPenguins << " Penguins";
	if (numPenguins == 0)
	{	cout << "	[!] WARNING: NEED AT LEAST 1 PENGUIN";
	}
	cout << "\n	" << numTurtles << " Turtles";
	if (numTurtles == 0)
	{	cout << "	[!] WARNING: NEED AT LEAST 1 TURTLE";
	}
	cout << "\n\n\nWould You Like To:\n";
	cout << "	[1] BUY TIGERS\n";
	cout << "	[2] BUY BEARS\n";
	cout << "	[3] BUY PENGUINS\n";
	cout << "	[4] BUY TURTLES\n";
	cout << "	[5] OPEN THE ZOO\n";
	cout << "\n=============================================================================\n";
}

/**************************************************************************************************
** Description: queryAnimals(int);					**PRIVATE::2019.01.27::HD**
**              This function takes an integer to determine which	***************************
**		animal if being purchased and displays the purchasing information of the animal.
**************************************************************************************************/
void Menu::queryAnimals(int animal)
{
	cout << "\nWould you like to purchase [1] or [2] ";
	if (animal == 1)
	{	cout << "tigers?\n";
	}
	else if (animal == 2)
	{	cout << "bears?\n";
	}
	else if (animal == 3)
	{	cout << "penguins?\n";
	}
	else if (animal == 4)
	{	cout << "turtles?\n";
	}
	cout << "	Press [1] for a single animal.\n";
	cout << "	Press [2] for a pair of animals.\n";
}

/**************************************************************************************************
** Description: queryQuit();						**PRIVATE::2019.01.27::HD**
**              This function asks the user if they want to quit.	***************************
**************************************************************************************************/
void Menu::queryQuit()
{
	cout << "\nWould you like to Play Again?\n";
	cout << "	[1] Play Again\n";
	cout << "	[2] Quit\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///== INPUT VALIDATION FUNCTIONS == INPUT VALIDATION FUNCTIONS == INPUT VALIDATION FUNCTIONS ==	///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description: validateMenu();						**PRIVATE::2019.01.27::HD**
**		This function ensures the user enters a valid input for	***************************
**		the main menu. Modifies the run function.
**************************************************************************************************/
void Menu::validateMenu()
{	
	// Get Input
	int choice;
	cin >> choice;

	// Validate Input
	while (!cin || choice < MIN_MENU_ALL || choice > MAX_MENU)
	{
		cleanInput();
		cout << "\n<!>WARNING: INPUT INVALID<!>\n";
		cout << "Please Enter\n";
		cout << "	[1] To Play\n";
		cout << "	[2] To Quit\n";
		cin >> choice;
	}

	if (choice == 1)
	{	play = true;
	}
	else
	{	play = false;
	}	
}

/**************************************************************************************************
** Description: validateConfig();					**PRIVATE::2019.01.27::HD**
**              This function ensures the user enters a valid input for	***************************
**		the configuration menu. Returns an integer representing the user's animal choice.
**************************************************************************************************/
int Menu::validateConfig()
{
	cleanInput();

	// Get Input
	int choice;
	cin >> choice;

	// Validate Input
	while (!cin || choice < MIN_MENU_ALL || choice > MAX_CONFIG || (choice == 5 && checkEmpty() == true))
	{
		cleanInput();
		// If the input is invalid
		if (!cin || choice < MIN_MENU_ALL || choice > MAX_CONFIG)
		{
			cout << "<!>WARNING: INPUT INVALID<!>\n";
			cout << "Please enter an integer from 1 to " << MAX_CONFIG << ":\n";
		}
		// If the user tries to open the zoo while missing an animal
		else
		{	cout << "<!>WARNING: NEED AT LEAST 1 OF EVERY ANIMAL.<!>\n";
			cout << "Please Purchase Missing Animal.\n";
		}
		cin >> choice;
	}

	// Return Value
	return choice;
}

/**************************************************************************************************
** Description: validateAnimal(int);					**PRIVATE::2019.01.27::HD**
**		This function takes an integer representing the animal	***************************
**		being purchased, makes sure the user enters a valid input for the animal query,
**		sets the number of the animal, and recalculates the bank.
**************************************************************************************************/
void Menu::validateAnimal(int animal)
{
	cleanInput();

	// Get Input
	int choice;
	cin >> choice;

	// Validate Input
	while (!cin || choice < MIN_MENU_ALL || choice > MAX_ANIMALS)
	{
		cleanInput();
		cout << "<!>WARNING: INPUT INVALID<!>\n";
		cout << "Please enter an integer from [1] to [" << MAX_ANIMALS << "]:\n";
		cin >> choice;
	}

	// Set number of animal based on argument
	if (animal == 1)
	{	numTigers = choice;
	}
	else if (animal == 2)
	{	numBears = choice;
	}
	else if (animal == 3)
	{	numPenguins = choice;
	}
	else if (animal == 4)
	{	numTurtles = choice;
	}

	// Set Bank
	bank = calcBank();
}

/**************************************************************************************************
** Description: run();							 **PUBLIC::2019.01.27::HD**
**		This function combines all the display functions with	 **************************
**		their respective input validation functions to have the user set all the data
**		members of the class.
**************************************************************************************************/
void Menu::run()
{
	dispMenu();
	validateMenu();
	if (play == true)
	{
		int choice;
		do
		{	dispConfig();
			choice = validateConfig();
			if (choice != MAX_CONFIG)
			{
				queryAnimals(choice);
				validateAnimal(choice);
			}
		} while (choice != MAX_CONFIG);
	}
	
	cleanInput();	// clean input for Zoo class
}

/**************************************************************************************************
** Description: playAgain()						 **PUBLIC::2019.01.27::HD**
**		Asks the user if they want to play again and gets the	 **************************
**		user input, validates the input, then sets the play data member.
**************************************************************************************************/
void Menu::playAgain()
{
	queryQuit();
	cleanInput();
	validateMenu();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/// == GET FUNCTIONS == GET FUNCTIONS == GET FUNCTIONS == GET FUNCTIONS == GET FUNCTIONS ==	///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description: getPlay()						 **PUBLIC::2019.01.27::HD**
**		Returns the bool data member, play.			 **************************
**************************************************************************************************/
bool Menu::getPlay()
{
	return play;
}

/**************************************************************************************************
** Description: getBank()						 **PUBLIC::2019.01.27::HD**
**		Returns the int data member, bank.			 **************************
**************************************************************************************************/
double Menu::getBank()
{
	return bank;
}

/**************************************************************************************************
** Description: getNumTigers();						**PUBLIC::2019.01.27::HD**
**		Returns the int data member, numTigers			***************************
**************************************************************************************************/
int Menu::getNumTigers()
{
	return numTigers;
}

/**************************************************************************************************
** Description: getNumBears();						**PUBLIC::2019.01.27::HD**
**		Returns the int data member, numBears			***************************
**************************************************************************************************/
int Menu::getNumBears()
{
	return numBears;
}

/**************************************************************************************************
** Description: getNumPenguins();					**PUBLIC::2019.01.27::HD**
**		Returns the int data member, numPenguins		***************************
**************************************************************************************************/
int Menu::getNumPenguins()
{
	return numPenguins;
}

/**************************************************************************************************
** Description: getNumTurtles();					**PUBLIC::2019.01.27::HD**
**		Returns the int data member, numTurtles			***************************
**************************************************************************************************/
int Menu::getNumTurtles()
{
	return numTurtles;
}


