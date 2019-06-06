/**************************************************************************************************
** Program name:Program 02 - Zoo Tycoon
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/29/2018
** Description: THIS IS THE IMPLEMENTATION FILE OF THE ZOO CLASS
**		This program is a game that simulates the day-to-day maintenance of a zoo. The user
**		takes the role as a Zoo's director. Before the program is run, the user must the
**		number of each animal they want in their zoo initally. Then, the user decides what
**		kind of food to feed their animals. A random event then is called, which depending
**		on the type of food, could lead to the death of one of their animals. At the end
**		of the day, the user can then purchae an adult animal and choose whether or not
**		to retire as the director, or continue. If the player's bank ever goes below 0, the
**		user has a Game-Over.
**************************************************************************************************/
// Zoo.cpp
#include "Zoo.hpp"

/**************************************************************************************************
** Description:	Zoo(int, int, int, int, double);			 **PUBLIC::2019.01.29::HD** 
**		This is the constructor for the Zoo class. 		 **************************
**		Takes 4 integer arguments and a double argument. This 4 integer arguments represent
**		the inital number of each animal and the double argument represents the starting
**		balance of the bank. This constructor also initalizes each of the array data
**		members of the function with their respective animals with an age of 1, as well as
**		creates sets the play data member to true.
**************************************************************************************************/
Zoo::Zoo(int numTigers, int numBears, int numPenguins, int numTurtles, double bankStart)
{
	// Set the Initial Number of each animal
	this->numTigers = numTigers;
	this->numBears = numBears;
	this->numPenguins = numPenguins;
	this->numTurtles = numTurtles;

	this->bank = bankStart;		// sets the inital bank balance
	this->play = true;		// sets the play data type to true;
	this->bonus = 0;		// sets initalizes the bonus to 0;
	this->day = 0;			// sets the number of days elapsed to 0;

	// Dynamically allocates memory for animals
	tigers = new Tiger[ARRAY_SIZE_START];
	penguins = new Penguin[ARRAY_SIZE_START];
	turtles = new Turtle[ARRAY_SIZE_START];
	bears = new Bear[ARRAY_SIZE_START];

	// Sets the initial array sizes
	arraySizeTiger = arraySizeBear = arraySizePenguin = arraySizeTurtle = 10;

	// Fill Arrays with animals with an age of 1
	for (int count = 0; count < numTigers; count++)
	{	tigers[count].setAge(1);
	}
	for (int count = 0; count < numBears; count++)
	{	bears[count].setAge(1);
	}
	for (int count = 0; count < numPenguins; count++)
	{	penguins[count].setAge(1);
	}
	for (int count = 0; count < numTurtles; count++)
	{	turtles[count].setAge(1);
	}

	// Seed random generator
	static bool seed = false;
	if (seed == false)
	{	srand(time(0));
		seed = true;
	}
}

/**************************************************************************************************
** Description:	~Zoo();							 **PUBLIC::2019.01.29::HD**
**		This is the deconstructor for the Zoo class.		 **************************
**		Deletes the dynamically allocatted array created from the constructor;
**************************************************************************************************/
Zoo::~Zoo()
{
	delete [] tigers;
	tigers = NULL;
	delete [] bears;
	tigers = NULL;
	delete [] penguins;
	penguins = NULL;
	delete [] turtles;
	turtles = NULL;
}


/**************************************************************************************************
** Description:	open();							 **PUBLIC::2019.01.30::HD**
**		This function combines all the helper functions to	 **************************
**		simulate all the functions that occur when running a zoo for the day. This includes
**		getting the type of feed, calling random events, asking if the user wants to buy
**		an animal, and whether or not the player wants to retire.
**************************************************************************************************/
void Zoo::open()
{
	while (play == true)
	{
		//increase the number of days
		day++;
		// ask the user for the type of feed
		askFeed();
		validateFeed();
		// increase age of all the animals in the zoo
		ageUp();
		// calculate the food cost and subtract from bank
		bank -= calcFoodCost();
		// call a random event
		callRandom();
		// calculate profit and add bonus
		bank += calcEarnings();
		// ask user if they would like to buy an animal
		dispPurchase();
		validatePurchase();
			// if the user still has money, ask the player wants to continue
		if (bank > 0)
		{	dispEndDay();
			validateEndDay();
		}
		// otherwise, display game over
		else
		{	dispGameOver();
		}
		// reset bonus to 0
		bonus = 0;
	}
	displayEndGame();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///	== DISPLAY FUNCTIONS == DISPLAY FUNCTIONS == DISPLAY FUNCTIONS == DISPLAY FUNCTIONS ==  ///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	drawBorder()						**PRIVATE::2019.01.30::HD**
**		This function creates a border. This is used to		***************************
**		separate each display function
**************************************************************************************************/
void Zoo::drawBorder()
{
	cout << "\n\n";
	cout << "================================================================================";
	cout << "\n\n";
}

/**************************************************************************************************
** Description:	askFeed();						**PRIVATE::2019.01.30::HD**
**		This function asks the user for the type of feed they	***************************
**		would like to use for their animals.
**************************************************************************************************/
void Zoo::askFeed()
{
	drawBorder();
	cout << "[Day " << day << "]\n";
	cout << "Bank Balance $" << bank << "\n\n";
	cout << "The Cost of Feed is:\n";
	cout << "	$" << BASE_FOOD_COST * FOOD_MULT_TIGER << "	per Tiger.\n";
	cout << "	$" << BASE_FOOD_COST * FOOD_MULT_BEAR << "	per Bear.\n";
	cout << "	$" << BASE_FOOD_COST * FOOD_MULT_PENGUIN << "	per Penguin.\n";
	cout << "	$" << BASE_FOOD_COST * FOOD_MULT_TURTLE << "	per Turtle.\n\n";

	cout << "Today you will feed your animals with:\n";
	cout << "	[1] GENERIC FEED: 	$" << calcBaseFoodCost() * FOOD_MULT_GENERIC << "\n";
	cout << "	[2] CHEAP FEED: 	$" << calcBaseFoodCost() * FOOD_MULT_CHEAP << "\n";
	cout << "		Doubles Chance of Animal Getting Sick, but Half Price!\n";
	cout << "	[3] PREMIUM FEED: 	$" << calcBaseFoodCost() * FOOD_MULT_PREMIUM << "\n";
	cout << "		Halves Chance of Animals Getting Sick, but Double Price\n";
	drawBorder();
}

/**************************************************************************************************
** Description:	dispPurchase();						**PRIVATE::2019.01.30::HD**
**		This function shows the options for the user to either 	***************************
**		continue with the day or purchase an adult animal.
**************************************************************************************************/
void Zoo::dispPurchase()
{
	drawBorder();
	cout << "[Day " << day << "]\n";
	cout << "Bank Balance was: $" << bank - calcEarnings() - bonus << "\n";
	cout << "Zoo Has Earned: $" << calcEarnings()  << " with a Bonus of $" << bonus << "\n\n";
	cout << "Bank Balance: $" << bank << "\n\n";
	cout << "You currently have:\n";
	cout << "	" << numTigers << " Tigers\n";
	cout << "	" << numBears << " Bears\n";
	cout << "	" << numPenguins << " Penguins\n";
	cout << "	" << numTurtles << " Turtles\n\n";
	cout << "Would you like to:\n";
	cout << "	[1] Continue\n\n";
	cout << "Or Would You Like to Purchase an Adult:\n";
	cout << "	[2] Tiger for $" << COST_TIGER << "\n";
	cout << "	[3] Bear for $" << COST_BEAR << "\n";
	cout << "	[4] Penguin for $" << COST_PENGUIN << "\n";
	cout << "	[5] Turtle for $" << COST_TURTLE << "\n";
	drawBorder();
}
/**************************************************************************************************
** Description:	dispEndDay();						**PRIVATE::2019.01.30::HD**
**		This function displays the player stats at the end of	***************************
**		the day, as well as asks the user if they want to continue the game or retire.
**************************************************************************************************/
void Zoo::dispEndDay()
{
	drawBorder();
	cout << "[Day " << day << "]\n";
	cout << "Bank Balance: $" << bank << "\n\n";
        cout << "You currently have:\n";
        cout << "       " << numTigers << " Tigers\n";
        cout << "       " << numBears << " Bears\n";
        cout << "       " << numPenguins << " Penguins\n";
        cout << "       " << numTurtles << " Turtles\n\n";
	cout << "Animal Payoff:	$" << calcEarnings() - bonus << "\n";
	cout << "Bonus:		$" << bonus << "\n";
	cout << "Total Earnings:$" << calcEarnings() << "\n\n";
	cout << "Would You Like To:\n";
	cout << "	[1] Continue\n";
	cout << "	[2] Retire\n";
	drawBorder();
}

/**************************************************************************************************
** Description:	dispGameOver();						**PRIVATE::2019.01.30::HD**
**		This function shows the Game Over Screen and sets the	***************************
**		play data member to false.
**************************************************************************************************/
void Zoo::dispGameOver()
{
	drawBorder();
	cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout << ":: 	== GAME OVER == GAME OVER == GAME OVER == GAME OVER ==	::\n";
	cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
	cout << "The Zoo's Bank Balance is now Empty!\n";
	cout << "You've Been Fired!\n";
	play = false;
}


/**************************************************************************************************
** Description:	displayEndGame();					**PRIVATE::2019.01.30::HD**
**		This function shows the player their stats when the	***************************
**		game ends.
**************************************************************************************************/
void Zoo::displayEndGame()
{
	drawBorder();
	cout << "Thank You For Playing the Game!\n\n";
	cout << "You were Director for " << day << " days!\n";
	cout << "You Left the Zoo with a Bank Balance of $" << bank << ".\n\n";
	cout << "Your Zoo Had:\n";
	cout << "	>" << numTigers << " Tigers\n";
	cout << "	>" << numBears << " Bears\n";
	cout << "	>" << numPenguins << " Penguins\n";
	cout << "	>" << numTurtles << " Turtles\n";
	cout << "In total, the Zoo's Net Worth was: $" << calcNetWorth() << "\n\n";
	cout << "This means, out of the original $" << BANK_DEFAULT << " you started with,";
	cout << " you made $" << calcNetWorth() - BANK_DEFAULT << "!\n\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///	== UTILITY FUNCTIONS == UTILITY FUNCTIONS == UTILITY FUNCTIONS == UTILITY FUNCTIONS ==  ///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	 cleanInput();						**PRIVATE::2019.01.30::HD**
**		 Cleans the input for input validation functions	**************************
**************************************************************************************************/
void Zoo::cleanInput()
{
	cin.clear();
	cin.ignore(IGNORE_NUMF,'\n');
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///== INPUT VALIDATION FUNCTIONS == INPUT VALIDATION FUNCTIONS == INPUT VALIDATION FUNCTIONS == ///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	validateFeed();						**PRIVATE::2019.01.30::HD**
**		Gets and validates the user's input for the askFeed	***************************
**		functions. Sets the feedType data member.
**************************************************************************************************/
void Zoo::validateFeed()
{
	//cleanInput();

	// Get Input
	int choice;
	cin >> choice;

	// Validate Input
	while (!cin || choice < MIN_MENU_ALL || choice > NUM_FOOD_TYPES)
	{
		cleanInput();
		cout << "\n<!>WARNING: INPUT INVALID<!>\n";
		cout << "Please Enter 1, 2, or 3:\n";
		cout << "	[1] FOR GENERIC FEED\n";
		cout << "	[2] FOR CHEAP FEED\n";
		cout << "	[3] FOR PREMIUM FEED\n";
		cin >> choice;
	}

	// Set Feed
	if (choice == 1)
	{	feedType = GENERIC;
	}
	else if (choice == 2)
	{	feedType = CHEAP;
	}
	else if (choice == 3)
	{	feedType = PREMIUM;
	}
	else
	{
		drawBorder();
		cout << "\n<!!!>BUG: ERROR WITH VALIDATE FEED<!!!>\n";
		drawBorder();
	}
}

/**************************************************************************************************
** Description:	validatePurchase();					**PRIVATE::2019.01.30::HD**
**		Gets and validates the user's input for the		***************************
**		dispPurchase function. Creates an adult animal if the user decides to create one
**************************************************************************************************/
void Zoo::validatePurchase()
{
	cleanInput();

	// Get Input
	int choice;
	cin >> choice;

	// Validate Input
	while (!cin || choice < MIN_MENU_ALL || choice > PURCHASE_MAX)
	{
		cleanInput();
		drawBorder();
		cout << "\n<!>WARNING: INPUT INVALID<!>\n";
		cout << "Please Enter an Integer from 1 to 5:\n";
		cout << "	[1] Do Not Purchase Anything\n";
		cout << "	[2] Buy an Adult Tiger\n";
		cout << "	[3] Buy an Adult  Bear\n";
		cout << "	[4] Buy an Adult Penguin\n";
		cout << "	[5] Buy an Adult  Turtle\n";
		drawBorder();
		cin >> choice;
	}

	// If user chooses to add animal, add animal and subtract cost;
	if (choice == 2)
	{	addAnimal(TIGER, ADULT_AGE);
		bank -= COST_TIGER;
	}
	else if (choice == 3)
	{	addAnimal(BEAR, ADULT_AGE);
		bank -= COST_BEAR;
	}
	else if (choice == 4)
	{	addAnimal(PENGUIN, ADULT_AGE);
		bank -= COST_PENGUIN;
	}
	else if (choice == 5)
	{	addAnimal(TURTLE, ADULT_AGE);
		bank -= COST_TURTLE;
	}
}

/**************************************************************************************************
** Description:	validateEndDay();					**PRIVATE::2019.01.30::HD**
**		Gets and validates the user's input for the dispEndDay	***************************
**		function. Sets the play data member.
**************************************************************************************************/
void Zoo::validateEndDay()
{
	cleanInput();

	// Get Input
	int choice;
	cin >> choice;

	// Validate Input
	while (!cin || choice < MIN_MENU_ALL || choice > MAX_MENU)
	{
		cleanInput();
		drawBorder();
		cout << "\n<!>WARNING: INPUT INVALID<!>\n";
		cout << "Please Enter the Integers 1 or 2 to:\n";
		cout << "	[1] Continue Playing\n";
		cout << "	[2] Retire\n";
		drawBorder();
		cin >> choice;
	}

	// Set Play Data Member
	if (choice == 1)
	{	play = true;
	}
	else
	{	play = false;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///		== ARRAY INTERACTION FUNCTIONS == ARRAY INTERACTION FUNCTIONS ==		///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	incrArraySize(AnimalType)				**PRIVATE::2019.01.30::HD**
**		Creates an array with a size that is 10 elements higher	***************************
**		than the previous array, copies elements from the old array to the new array, then
**		deletes the old array.
**************************************************************************************************/
void Zoo::incrArraySize(AnimalType animalIn)
{
	// Get the new array size and the number of the animal
	int numAnimal;
	int tempArraySize;

	if (animalIn == TIGER)
	{	numAnimal = numTigers;
		while(numAnimal > arraySizeTiger)
		{	arraySizeTiger += ARRAY_SIZE_INCREASE;
		}
		tempArraySize = arraySizeTiger;
	}
	else if (animalIn == BEAR)
	{	numAnimal = numBears;
		while(numAnimal > arraySizeBear)
		{	arraySizeBear += ARRAY_SIZE_INCREASE;
		}
		tempArraySize = arraySizeBear;
	}
	else if (animalIn == PENGUIN)
	{	numAnimal = numPenguins;
		while(numPenguins > arraySizePenguin)
		{	arraySizePenguin += ARRAY_SIZE_INCREASE;
		}
		tempArraySize = arraySizePenguin;
	}
	else if (animalIn == TURTLE)
	{	numAnimal = numTurtles;
		while(numAnimal > arraySizeTurtle)
		{	arraySizeTurtle += ARRAY_SIZE_INCREASE;
		}
		tempArraySize = arraySizeTurtle;
	}

	// Allocate a temporary array with +10 the size of the first array
	Animal* tempArray;

	if (animalIn == TIGER)
	{	tempArray = new Tiger[tempArraySize];
	}
	else if (animalIn == BEAR)
	{	tempArray = new Bear[tempArraySize];
	}
	else if (animalIn == PENGUIN)
	{	tempArray = new Penguin[tempArraySize];
	}
	else if (animalIn == TURTLE)
	{	tempArray = new Turtle[tempArraySize];
	}

	// For loop to assign values of the first array into the temporary array
	if (animalIn == TIGER)
	{	for (int index = 0; index < numTigers - 1; index++)
		{	tempArray[index].setAge(tigers[index].getAge());
		}
	}
	else if (animalIn == BEAR)
	{	for (int index = 0; index < numBears - 1; index++)
		{	tempArray[index].setAge(bears[index].getAge());
		}
	}
	else if (animalIn == PENGUIN)
	{	for (int index = 0; index < numPenguins - 1; index++)
		{	tempArray[index].setAge(penguins[index].getAge());
		}
	}
	else if (animalIn == TURTLE)
	{	for (int index = 0; index < numTurtles - 1; index++)
		{	tempArray[index].setAge(turtles[index].getAge());
		}
	}

	// Free allocated memory of the original array and reallocate with size +10
	if (animalIn == TIGER)
	{	delete [] tigers;
		tigers = new Tiger[tempArraySize];
	}
	else if (animalIn == BEAR)
	{	delete [] bears;
		bears = new Bear[tempArraySize];
	}
	else if (animalIn == PENGUIN)
	{	delete [] penguins;
		penguins = new Penguin[tempArraySize];
	}
	else if (animalIn == TURTLE)
	{	delete [] turtles;
		turtles = new Turtle[tempArraySize];
	}

	// For loop to assign values from temp array to original array
	if (animalIn == TIGER)
	{	for (int index = 0; index < numTigers - 1; index++)
		{	tigers[index].setAge(tempArray[index].getAge());
		}
	}
	else if (animalIn == BEAR)
	{	for (int index = 0; index < numBears - 1; index++)
		{	bears[index].setAge(tempArray[index].getAge());
		}
	}
	else if (animalIn == PENGUIN)
	{	for (int index = 0; index < numPenguins - 1; index++)
		{	penguins[index].setAge(tempArray[index].getAge());
		}
	}
	else if (animalIn == TURTLE)
	{	for (int index = 0; index < numTurtles - 1; index++)
		{	turtles[index].setAge(tempArray[index].getAge());
		}
	}

	// Prevent memory leaks by freeing the allocated memory of the temp array
	delete [] tempArray;
}

/**************************************************************************************************
** Description:	addAnimal(AnimalType,int)				**PRIVATE::2019.01.30::HD**
**		Takes an AnimalType to determine the array the animal	***************************
**		will be added to, and an integer to determine the age of the animal. This function
**		then increases the number of the animal, then adds the animal to its appropriate
**		array.
**************************************************************************************************/
void Zoo::addAnimal(AnimalType animalIn, int age)
{
	if (animalIn == TIGER)
	{
		numTigers++;
		if(numTigers > arraySizeTiger)
		{	incrArraySize(TIGER);
		}
		tigers[numTigers-1].setAge(age);
	}
	else if (animalIn == BEAR)
	{
		numBears++;
		if(numBears > arraySizeBear)
		{	incrArraySize(BEAR);
		}
		bears[numBears-1].setAge(age);
	}
	else if (animalIn == PENGUIN)
	{
		numPenguins++;
		if(numPenguins > arraySizePenguin)
		{	incrArraySize(PENGUIN);
		}
		penguins[numPenguins-1].setAge(age);
	}
	else if (animalIn == TURTLE)
	{
		numTurtles++;
		if(numTurtles > arraySizeTurtle)
		{	incrArraySize(TURTLE);
		}
		turtles[numTurtles-1].setAge(age);
	}
}

/**************************************************************************************************
** Description:	removeAnimal(AnimalType)				**PRIVATE::2019.01.30::HD**
**		Takes an AnimalType to determine the animal about to be	***************************
**		removed.
**************************************************************************************************/
void Zoo::removeAnimal(AnimalType animalOut)
{	if (animalOut == TIGER)
	{	numTigers--;
		tigers[numTigers].setAge(REMOVAL_AGE);
	}
	else if (animalOut == BEAR)
	{	numBears--;
		bears[numBears].setAge(REMOVAL_AGE);
	}
	else if (animalOut == PENGUIN)
	{	numPenguins--;
		penguins[numPenguins].setAge(REMOVAL_AGE);
	}
	else if (animalOut == TURTLE)
	{	numTurtles--;
		turtles[numTurtles].setAge(REMOVAL_AGE);
	}
}

/**************************************************************************************************
** Description:	ageUp();						**PRIVATE::2019.01.30::HD**
**		Increases the age of each animal in all the arrays	***************************
**************************************************************************************************/
void Zoo::ageUp()
{
	// increase the age each tiger
	for (int count = 0; count < numTigers; count++)
	{	tigers[count].incAge();
	}
	// increase the age each bear
	for (int count = 0; count < numBears; count++)
	{	bears[count].incAge();
	}
	// increase the age each penguin
	for (int count = 0; count < numPenguins; count++)
	{	penguins[count].incAge();
	}
	// increase the age each turtle
	for (int count = 0; count < numTurtles; count++)
	{	turtles[count].incAge();
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///	== RANDOM FUNCTIONS == RANDOM FUNCTIONS == RANDOM FUNCTIONS == RANDOM FUNCTIONS ==	///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	randomEventMessage(RandomEvent);			**PRIVATE::2019.01.30::HD**
**		Takes a RandomEvent data type to determine the type of 	***************************
**		message and output the message into a text file. It then uses ifstream to read
**		messages from the created text file and display message.
**************************************************************************************************/
void Zoo::randomEventMessage(RandomEvent event)
{
	string fileName = "RandomEvent.txt";
	string line;
	ifstream inputFile;
	ofstream outputFile;

	outputFile.open(fileName.c_str());

	// Write to file
	if (event == SICK)
	{	outputFile << "Tragedy Strikes!\n";
		if (feedType == CHEAP)
		{	outputFile << "Unsurprisingly, the Cheap Food was Tainted.\n";
		}
		else if (feedType == PREMIUM)
		{	outputFile << "Food was too good! One of your animals can't stop dancing!?!\n";
		}
		outputFile << "One of your ";
		if (died == TIGER)
		{	outputFile << "tigers ";
		}
		else if (died == BEAR)
		{	outputFile << "bears ";
		}
		else if (died == PENGUIN)
		{	outputFile << "penguins ";
		}
		else if (died == TURTLE)
		{	outputFile << "turtles ";
		}
		outputFile << "came down with an illness!\n";
		outputFile << "Sadly, it didn't make the night.";
	}
	else if (event == BONUS)
	{	outputFile << "Ka-ching!\n";
		outputFile << "People REALLY wanted to see tigers today!\n";
		if (numTigers > 0)
		{	outputFile << "You made an extra $" << bonus/numTigers << " per tiger!";
		}
		else
		{
			outputFile << "Sadly, you have no tigers.";
		}
	}
	else if (event == BORN)
	{	if (born == NONE)
		{	outputFile << "One day, one of your animals will have a baby.\n";
			outputFile << "Since no-one is old enough, today is not that day.\n";
		}
		else
		{	outputFile << "Aww!\n";
			outputFile << "One of your ";
			if (born == TIGER)
			{	outputFile << "tigers had " << NUM_BABIES_TIGER;
			}
			else if (born == BEAR)
			{	outputFile << "bears had " << NUM_BABIES_BEAR;
			}
			else if (born == PENGUIN)
			{	outputFile << "penguins had " << NUM_BABIES_PENGUIN;
			}
			else if (born == TURTLE)
			{	outputFile << "turtles had " << NUM_BABIES_TURTLE;
			}
			outputFile << " babies!\n";
			outputFile << "The zoo could always have more animals!";
		}
	}
	else if (event == NOTHING)
	{
		outputFile << "Nothing beats peace and quiet.\n";
		outputFile << "The day passses without anything out of the ordinary happening.";
	}
	// Close the file
	outputFile.close();
	
	// Read from the input file
	inputFile.open(fileName.c_str());

	while(getline(inputFile,line))
	{	cout << line << "\n";
	}

	// Close file
	inputFile.close();
}

/**************************************************************************************************
** Description:	randomSick();						**PRIVATE::2019.01.30::HD**
**		This function selects a random animal and "kills" it	***************************
**************************************************************************************************/
void Zoo::randomSick()
{
	int roll;
	bool animalDied = false;

	while (animalDied == false)
	{	roll = rand() % 4;
		if (roll == 0 && numTigers > 0)
		{	died = TIGER;
			removeAnimal(TIGER);
			animalDied = true;
		}
		else if (roll == 1 && numBears > 0)
		{	died = BEAR;
			removeAnimal(BEAR);
			animalDied = true;
		}
		else if (roll == 2 && numPenguins > 0)
		{	died = PENGUIN;
			removeAnimal(PENGUIN);
			animalDied = true;
		}
		else if (roll == 3 && numTurtles > 0)
		{	died = TURTLE;
			removeAnimal(TURTLE);
			animalDied = true;
		}
		else
		{
			cout << "\nAll the animals are dead! None can get sick!\n";
			animalDied = true;
		}
	}
}

/**************************************************************************************************
** Description:	randomBonus();						**PRIVATE::2019.01.30::HD**
**		This function determines the bonus money earned when	***************************
**		triggering the random event. This bonus is then stored in the bonus data member.
**************************************************************************************************/
void Zoo::randomBonus()
{
	int roll = (rand() % (BONUS_MAX - BONUS_MIN + 1)) + BONUS_MIN;

	// Calculate Bonus
	bonus = numTigers * roll;
}

/**************************************************************************************************
** Description:	randomBaby();						**PRIVATE::2019.01.30::HD**
**		This function looks to see if there are any adults in	***************************
**		in each array. If there is, it randomly selects one of the arrays with adults and
**		adds a new animal to the array, and increases the number of the animal by the
**		number of babies it would have.
**************************************************************************************************/
void Zoo::randomBaby()
{
	// create flags for whether there is an adult for each animal
	bool hasAdultTiger, hasAdultPenguin, hasAdultTurtle, hasAdultBear = false;
	bool babyMade = false;	// stays false if a baby isn't made
	bool hasAdult = false;	// whether there is any adult animal
	int roll;		// holds the randomly generated roll value
	
	// check if there is an adult tiger
	for (int count = 0; count < numTigers; count++)
	{	if (tigers[count].getAge() >= ADULT_AGE)
		{	hasAdult = hasAdultTiger = true;
		}
	}
	// check if there is an adult penguin
	for (int count = 0; count < numPenguins; count++)
	{	if (penguins[count].getAge() >= ADULT_AGE)
		{	hasAdult = hasAdultPenguin = true;
		}
	}
	// check if there is an adult turtle
	for (int count = 0; count < numTurtles; count++)
	{	if (turtles[count].getAge() >= ADULT_AGE)
		{	hasAdult = hasAdultTurtle = true;
		}
	}
	// check if there is an adult bear
	for (int count = 0; count < numBears; count++)
	{	if (bears[count].getAge() >= ADULT_AGE)
		{	hasAdult = hasAdultBear = true;
		}
	}

	// if there is an adult, randomly select until a baby is born
	while (	hasAdult == true && babyMade == false)
	{	roll = rand() % NUM_ANIMALS;
		if (roll == 0 && hasAdultTiger == true)
		{	for (int count = 0; count < NUM_BABIES_TIGER; count++)
			{	addAnimal(TIGER, BABY_AGE);
			}
			babyMade = true;
			born = TIGER;
		}
		else if (roll == 1 && hasAdultPenguin == true)
		{	for (int count = 0; count < NUM_BABIES_PENGUIN; count++)
			{	addAnimal(PENGUIN, BABY_AGE);
			}
			babyMade = true;
			born = PENGUIN;
		}
		else if (roll == 2 && hasAdultTurtle == true)
		{	for (int count = 0; count < NUM_BABIES_TURTLE; count++)
			{	addAnimal(TURTLE, BABY_AGE);
			}
			babyMade = true;
			born = TURTLE;
		}
		else if (roll == 3 && hasAdultBear == true)
		{	for (int count = 0; count < NUM_BABIES_BEAR; count++)
			{	addAnimal(BEAR, BABY_AGE);
			}
			babyMade = true;
			born = BEAR;
		}
	}

	// if there is no baby born, set born to none
	if (hasAdult == false)
	{	born = NONE;
	}
}

/**************************************************************************************************
** Description:	callRandom();						**PRIVATE::2019.01.30::HD**
**		This function rolls a random number and chooses a	***************************
**		random event to occur.
**************************************************************************************************/
void Zoo::callRandom()
{	int roll = rand() % RANDOM_MIN;

	// If Food Was Cheap, likely to be sick
	if (feedType == CHEAP)
	{	if (roll < 12)		// 50% or 12/24 chance of sickness
		{	randomSick();
			randomEventMessage(SICK);
		}
		else if (roll < 16)
		{	randomBonus();
			randomEventMessage(BONUS);
		}
		else if (roll < 20)
		{	randomBaby();
			randomEventMessage(BORN);
		}
		else
		{	randomEventMessage(NOTHING);
		}
	}
	else if (feedType == GENERIC)
	{	if (roll < 6)
		{	randomSick();	// 25% or 6/24 chance of sickness
			randomEventMessage(SICK);
		}
		else if (roll < 12)
		{	randomBonus();
			randomEventMessage(BONUS);
		}
		else if (roll < 18)
		{	randomBaby();
			randomEventMessage(BORN);
		}
		else
		{	randomEventMessage(NOTHING);
		}
	}
	// If Food Was Premium, twice less likely to be sick
	else if (feedType == PREMIUM)
	{	if (roll < 2)
		{	randomSick();	// 12.5% or 3/24 chance of sickness
			randomEventMessage(SICK);
		}
		else if (roll < 9)
		{	randomBonus();
			randomEventMessage(BONUS);
		}
		else if (roll < 16)
		{	randomBaby();
			randomEventMessage(BORN);
		}
		else
		{	randomEventMessage(NOTHING);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///	== CALCULATION FUNCTIONS == CALCULATION FUNCTIONS == CALCULATION FUNCTIONS ==		///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	calcBaseFoodCost();					**PRIVATE::2019.01.30::HD**
**		Calculates the food cost without considering the type	***************************
**		of feed.
**************************************************************************************************/
double Zoo::calcBaseFoodCost()
{
	return  	numTigers * FOOD_MULT_TIGER * BASE_FOOD_COST +		// tigers feed
			numPenguins * FOOD_MULT_PENGUIN * BASE_FOOD_COST +	// penguins feed
			numTurtles * FOOD_MULT_TURTLE * BASE_FOOD_COST +	// turtles feed
			numBears * FOOD_MULT_BEAR * BASE_FOOD_COST;		// bears feed
}


/**************************************************************************************************
** Description:	calcFoodCost()						**PRIVATE::2019.01.30::HD**
**		Calculates the total cost of feed all the animals in	***************************
**		the zoo based on the feedType data member.
**************************************************************************************************/
double Zoo::calcFoodCost()
{
	double baseFoodTotal = calcBaseFoodCost();

	if(feedType == CHEAP)
	{	return baseFoodTotal * FOOD_MULT_CHEAP;
	}
	else if(feedType == GENERIC)
	{	return baseFoodTotal * FOOD_MULT_GENERIC;
	}
	else if(feedType == PREMIUM)
	{	return baseFoodTotal * FOOD_MULT_PREMIUM;
	}
	else
	{	cout << "\nBUG: FEED TYPE NOT DETECTED LOOK AT CALCFOODCOST\n";
		return 999999;
	}
}

/**************************************************************************************************
** Description:	calcEarnings();						**PRIVATE::2019.01.30::HD**
**		This function calculates the total earnings of the zoo	***************************
**		for the day;
**************************************************************************************************/
double Zoo::calcEarnings()
{
	double animalPayoff;

	animalPayoff =	numTigers * COST_TIGER * PAYOFF_TIGER +
			numBears * COST_BEAR * PAYOFF_BEAR +
			numPenguins * COST_PENGUIN * PAYOFF_PENGUIN +
			numTurtles * COST_TURTLE * PAYOFF_TURTLE;

	return animalPayoff + bonus;
}


/**************************************************************************************************
** Description:	calcNetWorth();						**PRIVATE::2019.01.30::HD**
**		This function calculates the net worth of the zoo	***************************
**************************************************************************************************/
double Zoo::calcNetWorth()
{
	double animalWorth;

	animalWorth =	numTigers * COST_TIGER +
			numBears * COST_BEAR +
			numPenguins * COST_PENGUIN +
			numTurtles * COST_TURTLE;

	return animalWorth + bank;
}
