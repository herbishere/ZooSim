/**************************************************************************************************
** Program name:Program 02 - Zoo Tycoon
** Author:      Herbert Diaz <diazh@oregonstate.edu>
** Date:        1/29/2018
** Description: THIS IS A HEADER FILE CONTAINING ALL THE GLOBAL CONSTANTS FOR PROGRAM 02
**              ABSTRACTION OF: The constants of the function
**              PURPOSE:        Hold all the global constants in one header file
**              HOW TO USE:     Include the header file "P2Constants.hpp" and call constant names.
**              SUMMARY:        Holds global constants representing the minimum and maximum
**				integers for functions, the initial bank amount of the player,
**				and the various animal costs, food costs, and payoff modifiers.
**************************************************************************************************/
// P2Constants.hpp
#if !defined(P2CONSTANTS_HPP)	// Method of constant header from stackoverflow Q#12042549
#define P2CONSTANTS_HPP

// Menu Constants
const int IGNORE_NUMF		= 10000;	// number of characters to ignore for ignore function
const int MIN_MENU_ALL		= 1;		// minimum menu integer
const int MAX_MENU		= 2;		// maximum main menu integer
const int MAX_CONFIG		= 5;		// maximum configuration menu integer
const int MAX_ANIMALS		= 2;		// maximum number of starting animals
const double BANK_DEFAULT	= 100000;	// starting amount of money in player's bank
// Animal Prices
const double COST_TIGER		= 10000;	// cost of a tiger
const double COST_PENGUIN	= 1000;		// cost of a penguin
const double COST_TURTLE	= 100;		// cost of a turtle
const double COST_BEAR		= 5000;		// cost of a bear **EXTRA CREDIT**
// Number of Offspring for each animal
const int NUM_BABIES_TIGER	= 1;
const int NUM_BABIES_PENGUIN	= 5;
const int NUM_BABIES_TURTLE	= 10;
const int NUM_BABIES_BEAR	= 2;
// Multiplier of Base Food Cost for each Animal
const double FOOD_MULT_TIGER	= 5.0;
const double FOOD_MULT_PENGUIN	= 1.0;
const double FOOD_MULT_TURTLE	= 0.5;
const double FOOD_MULT_BEAR	= 3.0;
// Multiplier of Base FOod Cost for type of Feed
const double FOOD_MULT_CHEAP	= 0.5;
const double FOOD_MULT_GENERIC	= 1;
const double FOOD_MULT_PREMIUM	= 2;
// Payoff Multipliers for each Animal
const double PAYOFF_TIGER	= 0.2;
const double PAYOFF_PENGUIN	= 0.1;
const double PAYOFF_TURTLE	= 0.05;
const double PAYOFF_BEAR	= 0.15;
// Zoo Constants
const double BASE_FOOD_COST 	= 10;
const int ARRAY_SIZE_START	= 10;		// inital array size
const int ARRAY_SIZE_INCREASE	= 10;		// amount array increases when increased
const int NUM_FOOD_TYPES	= 3;
const int PURCHASE_MAX		= 5;		// maximum purchase menu integer
const int NUM_ANIMALS		= 4;		// total number of animals.
// Animal Ages
const int BABY_AGE		= 0;
const int START_AGE		= 1;
const int ADULT_AGE		= 3;
// Animal Initalization Ages
const int CREATION_AGE		=-8;		// used for debugging/inital animal creation	
const int REMOVAL_AGE		=-22;		// used for debugging/animal removal
// Tiger Random Bonuses
const int BONUS_MIN		= 250;		// minimum bonus money
const int BONUS_MAX		= 500;		// maximum bonus money
// Random Number Choices
const int RANDOM_MIN		= 24;		// number of random choices

#endif
