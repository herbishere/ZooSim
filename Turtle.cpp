/**************************************************************************************************
** Program name:Program 02 - Zoo Tycoon
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/29/2018
** Description: THIS IS THE IMPLEMENTATION FILE OF THE TURTLE CLASS
**		This program is a game that simulates the day-to-day maintenance of a zoo. The user
**		takes the role as a Zoo's director. Before the program is run, the user must the
**		number of each animal they want in their zoo initally. Then, the user decides what
**		kind of food to feed their animals. A random event then is called, which depending
**		on the type of food, could lead to the death of one of their animals. At the end
**		of the day, the user can then purchae an adult animal and choose whether or not
**		to retire as the director, or continue. If the player's bank ever goes below 0, the
**		user has a Game-Over.
**************************************************************************************************/
// Turtle.cpp
#include "Turtle.hpp"

/**************************************************************************************************
** Description: Turtle();						 **PUBLIC::2019.01.30::HD**
**              This is a constructor for the Turtle class that is	 **************************
**		derived from the Animal base class. This constructor takes an integer that sets
**		the age and initalizes the other data members to the default values
**************************************************************************************************/
Turtle::Turtle() 
: Animal(CREATION_AGE, COST_TURTLE, NUM_BABIES_TURTLE, FOOD_MULT_TURTLE, PAYOFF_TURTLE)
{
}
