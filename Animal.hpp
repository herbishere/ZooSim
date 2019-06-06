/**************************************************************************************************
** Program name:Program 02 - Zoo Tycoon
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/27/2018
** Description: THIS IS THE HEADER FILE OF THE ANIMAL CLASS
**		This program is a game that simulates the day-to-day maintenance of a zoo. The user
**		takes the role as a Zoo's director. Before the program is run, the user must the
**		number of each animal they want in their zoo initally. Then, the user decides what
**		kind of food to feed their animals. A random event then is called, which depending
**		on the type of food, could lead to the death of one of their animals. At the end
**		of the day, the user can then purchae an adult animal and choose whether or not
**		to retire as the director, or continue. If the player's bank ever goes below 0, the
**		user has a Game-Over.
**		ABSTRACTION OF:	The base class for all subsequent animal classes
**		PURPOSE:	This class contains all the shared data members and functions used
**				by subsequent derived classes.
**		HOW TO USE:	Use the constructor to set the data members.
**		SUMMARY:	
**************************************************************************************************/
// Animal.hpp
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "P2Constants.hpp"

class Animal
{
	private:
		int age;
		double cost;
		int numBabies;
		double baseFoodCost;
		double payoff;
	public:
		Animal(int, double, int, double, double);	// constructor
		void incAge();					// increases animal age by 1
		// Get Functions
		int getAge();
		double getCost();
		int getNumBabies();
		double getBaseFoodCost();
		double getPayoff();
		// Set Function
		void setAge(int);
};
#endif
