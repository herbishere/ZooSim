/**************************************************************************************************
** Program name:Program 02 - Zoo Tycoon
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/29/2018
** Description: THIS IS THE IMPLEMENTATION FILE OF THE TIGER CLASS
**		This program is a game that simulates the day-to-day maintenance of a zoo. The user
**		takes the role as a Zoo's director. Before the program is run, the user must the
**		number of each animal they want in their zoo initally. Then, the user decides what
**		kind of food to feed their animals. A random event then is called, which depending
**		on the type of food, could lead to the death of one of their animals. At the end
**		of the day, the user can then purchae an adult animal and choose whether or not
**		to retire as the director, or continue. If the player's bank ever goes below 0, the
**		user has a Game-Over.
**************************************************************************************************/
// Tiger.cpp
#include "Tiger.hpp"

/**************************************************************************************************
** Description: Tiger();						 **PUBLIC::2019.01.30::HD**
**              This is a default constructor for the Tiger class that	 **************************
**		is derived from the Animal base class. This constructor initalizes the age and
**		 initalizes the other data members to the default values
**************************************************************************************************/
Tiger::Tiger() 
: Animal(CREATION_AGE, COST_TIGER, NUM_BABIES_TIGER, FOOD_MULT_TIGER, PAYOFF_TIGER)
{
}
