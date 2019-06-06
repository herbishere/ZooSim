/**************************************************************************************************
** Program name:Program 02 - Zoo Tycoon
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/29/2018
** Description: THIS IS THE HEADER FILE OF THE PENGUIN CLASS
**		This program is a game that simulates the day-to-day maintenance of a zoo. The user
**		takes the role as a Zoo's director. Before the program is run, the user must the
**		number of each animal they want in their zoo initally. Then, the user decides what
**		kind of food to feed their animals. A random event then is called, which depending
**		on the type of food, could lead to the death of one of their animals. At the end
**		of the day, the user can then purchae an adult animal and choose whether or not
**		to retire as the director, or continue. If the player's bank ever goes below 0, the
**		user has a Game-Over.
**		ABSTRACTION OF:	The Penguins of the Zoo
**		PURPOSE:	This class contains all the information regarding the creation and
**				information of a Penguin, which is derived from the Animal Class
**		HOW TO USE:	Use the constructor to create a Penguin, or dynamically allocate an
**				animal object and use polymorphism to create a Penguin object.
**		SUMMARY:	This class contains a default constructor
**************************************************************************************************/
// Penguin.hpp
#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal
{
	public:
		Penguin();
};

#endif
