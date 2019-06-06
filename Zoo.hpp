/**************************************************************************************************
** Program name:Program 02 - Zoo Tycoon
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/29/2018
** Description: THIS IS THE HEADER FILE OF THE ZOO CLASS
**		This program is a game that simulates the day-to-day maintenance of a zoo. The user
**		takes the role as a Zoo's director. Before the program is run, the user must the
**		number of each animal they want in their zoo initally. Then, the user decides what
**		kind of food to feed their animals. A random event then is called, which depending
**		on the type of food, could lead to the death of one of their animals. At the end
**		of the day, the user can then purchae an adult animal and choose whether or not
**		to retire as the director, or continue. If the player's bank ever goes below 0, the
**		user has a Game-Over.
**		ABSTRACTION OF: A zoo, with its animals, its bank, its budgets, and random events
**				that affect those aspects
**		PURPOSE:	To encapsulate all the functions and data related to the operation
**				of a zoo.
**		HOW TO USE:	Use constructor to create a zoo object
**		SUMMARY:	The run function organizes all the helper utility functions and
**				has them run in order according to how the zoo operates throughout
**				the day. This class includes display functions, input validation,
**				calling random events, and changing the relevant data members.
**************************************************************************************************/
// Zoo.hpp
#ifndef ZOO_HPP
#define ZOO_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

#include "P2Constants.hpp"
#include "Tiger.hpp"
#include "Bear.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;
using std::srand;

// enumerated data types
enum Feed {CHEAP, GENERIC, PREMIUM};
enum Status {START, BABY, ADULT};
enum AnimalType {TIGER, BEAR, PENGUIN, TURTLE, NONE};
enum RandomEvent {SICK, BONUS, BORN, NOTHING};

class Zoo
{
	private:
		bool play;			// whether or not the player should continue or quit
		Feed feedType;			// the type of feed that is currently being fed
		double bank;			// the bank balance
		double bonus;			// amount of bonus money made for the day
		AnimalType born;		// the animal that was born;
		AnimalType died;		// the animal that has died;
		int day;			// stores the current day
		// number of each animal
		int numTigers;
		int numBears;
		int numPenguins;
		int numTurtles;
		// pointer to dynamically allocated array of animals
		Animal* tigers;
		Animal* bears;
		Animal* penguins;
		Animal* turtles;
		// size of each array
		int arraySizeTiger;
		int arraySizeBear;
		int arraySizePenguin;
		int arraySizeTurtle;
		// seed for random functions
		static bool seed;
		// display functions
		void drawBorder();		// creates a border between display options
		void askFeed();			// asks user for type of feed for animals
		void dispPurchase();		// asks user if they want to purchase adult animal
		void dispEndDay();		// shows user zoo info and asks if user wants to retire
		void dispGameOver();		// shows game over screen
		void displayEndGame();		// shows final player stats
		// utility functions
		void cleanInput();		// cleans input for input validation
		// input validation functions
		void validateFeed();		// gets/makes sure input valid and sets feed
		void validatePurchase();	// gets/makes sure input valid and adds animal if wanted
		void validateEndDay();		// gets/makes sure input valid and sets play
		// array interaction functions
		void incrArraySize(AnimalType);	// increases the size of the array by 10
		void addAnimal(AnimalType,int);	// adds an animal to the zoo
		void removeAnimal(AnimalType);	// removes an animal from the zoo
		void ageUp();			// increases the age of each animal in zoo by 1
		// random functions
		void randomEventMessage(RandomEvent);
		void randomSick();
		void randomBonus();
		void randomBaby();
		void callRandom();
		// calculation functions
		double calcBaseFoodCost();	// calculates the base cost of all the food for animals
		double calcFoodCost();		// calculates the cost of the food
		double calcEarnings();		// calculates the earnings of the zoo
		double calcNetWorth();		// calculates the net worth of the zoo;
	public:
		Zoo(int, int, int, int, double);
		~Zoo();
		void open();
};
#endif
