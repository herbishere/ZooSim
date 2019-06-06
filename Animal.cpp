/**************************************************************************************************
** Program name:Program 02 - Zoo Tycoon
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/28/2018
** Description: THIS IS THE IMPLEMENTATION FILE FOR THE ANIMAL CLASS
**		This program is a game that simulates the day-to-day maintenance of a zoo. The user
**		takes the role as a Zoo's director. Before the program is run, the user must the
**		number of each animal they want in their zoo initally. Then, the user decides what
**		kind of food to feed their animals. A random event then is called, which depending
**		on the type of food, could lead to the death of one of their animals. At the end
**		of the day, the user can then purchae an adult animal and choose whether or not
**		to retire as the director, or continue. If the player's bank ever goes below 0, the
**		user has a Game-Over.
**************************************************************************************************/
// Animal.cpp
#include"Animal.hpp"

/**************************************************************************************************
** Description: Animal(int, double, int, double, double);		 **PUBLIC::2019.01.28::HD**
**              This is a constructor for the Animal Class.		 **************************
**************************************************************************************************/
Animal::Animal(int age, double cost, int numBabies, double baseFoodCost, double payoff)
{
	this->age = age;
	this->cost = cost;
	this->numBabies = numBabies;
	this->baseFoodCost = baseFoodCost;
	this->payoff = payoff;
}

/**************************************************************************************************
** Description: incAge();						 **PUBLIC::2019.01.28::HD**
**              This function increases the age by 1.			 **************************
**************************************************************************************************/
void Animal::incAge()
{
	age++;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
/// == GET FUNCTIONS == GET FUNCTIONS == GET FUNCTIONS == GET FUNCTIONS == GET FUNCTIONS ==     ///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description: getAge();						 **PUBLIC::2019.01.28::HD**
**              Returns the age data member.				 **************************
**************************************************************************************************/
int Animal::getAge()
{
	return age;
}

/**************************************************************************************************
** Description: getCost();						 **PUBLIC::2019.01.28::HD**
**              Returns the cost data member.				 **************************
**************************************************************************************************/
double Animal::getCost()
{
	return cost;
}

/**************************************************************************************************
** Description: getNumBabies();						 **PUBLIC::2019.01.28::HD**
**              Returns the numBabies data member.			 **************************
**************************************************************************************************/
int Animal::getNumBabies()
{
	return numBabies;
}

/**************************************************************************************************
** Description: getBaseFoodCost();					 **PUBLIC::2019.01.28::HD**
**              Returns the baseFoodCost data member.			 **************************
**************************************************************************************************/
double Animal::getBaseFoodCost()
{
	return baseFoodCost;
}

/**************************************************************************************************
** Description: getPayoff();						 **PUBLIC::2019.01.28::HD**
**              Returns the payoff data member.				 **************************
**************************************************************************************************/
double Animal::getPayoff()
{
	return payoff;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/// == SET FUNCTIONS == SET FUNCTIONS == SET FUNCTIONS == SET FUNCTIONS == SET FUNCTIONS ==     ///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description: setAge;							 **PUBLIC::2019.01.28::HD**
**              Sets the Age data member.				 **************************
**************************************************************************************************/
void Animal::setAge(int age)
{
	this->age = age;
}


