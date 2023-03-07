// ****************************************
// Program Title: Project 07
// Project File: Project_07.cpp
// Name: Benjamin Curths
// Course Section: CPE-211-01
// Lab Section: 05
// Due Date: 2020/10/22
// Program Description:  Uses randomly generated numbers 
//		to approximate pi, simulate a coin-toss, or
//		simulate a 5-sided die.  Demonstrates user-
//		defined functions and use of random numbers.
// *****************************************
#include <iostream>
#include <cstdlib>	// rand(), srand(), RAND_MAX
#include <iomanip>	// fixed, setprecision()
#include <string>	// string()
#include <cmath>	// pow(), sqrt()
#include <climits>	// INT_MAX
using namespace std;

void PrintMenu();		// Outputs menu options
int GetInteger();		// prompts for and returns an integer value
void CalculatePi();		// uses Monte Carlo method to approximate pi with random values
void CoinFlip();		// simulates a fair coin-flip for a user-defined number of trials
void DieRoll();			// simulates a fair die-roll for a user-defined number of trials 

int main()
{
	int seed;
	int num;

		// prompt for seed value for RNG
	cout << endl << "Enter in the seed(integer > 0) for the random number generator: ";
	cin >> seed;
	cout << seed << endl << endl;
	srand(seed);
	
		// infinite loop.  controls program flow and exits program on user selection
	while(1)
	{
		PrintMenu();
		num = GetInteger();

		switch (num)
		{
			case 1:
				CalculatePi();
				break;
			case 2:
				CoinFlip();
				break;
			case 3:
				DieRoll();
				break;
			case 4:
					// program loop continues until case 4 is selected.
				cout << "Exit selected.  Exiting the program now..." << endl << endl;
				return 0;
			default:
				cout << string(15, '*') << " Invalid Integer " << string(15, '*') << endl
					<< "==> Invalid integer entered." << endl
					<< "==> Please try again..." << endl
					<< string(47, '*') << endl << endl;
		}
	}
	
	return 0;
}

void PrintMenu()
{
	cout << string(24, '*') << endl
		<< "***** Menu Options *****" << endl
		<< string(24, '*') << endl
		<< "1) Approximate PI" << endl
		<< "2) Flip a fair coin" << endl
		<< "3) Toss a fair 5-sided die" << endl
		<< "4) Exit" << endl
		<< string(24, '*') << endl << endl;

	return;
}

int GetInteger()
{
	int num = 0;

		// prompt for an integer value
	cout << "Enter your choice: ";
	cin >> num;
	
		// validate input.  clear errors and reprompt on invalid entry
	while (!cin)
	{
		char ch;	// char variable to hold invalid input for display

			// reset the input stream, pull and echo-print the invalid character
		cin.clear();
		cin >> ch;
		cout << ch << endl << endl;		
			// remove the remaining invalid input to prepare for next prompt
		cin.ignore(INT_MAX, '\n');

		cout << string(14, '*') << " Invalid Character " << string(14, '*') << endl
			<< "==> Invalid character(s) entered." << endl
			<< "==> Please try again..." << endl
			<< string(47, '*') << endl << endl;

			// redisplay options and prompt for valid input
		PrintMenu();
		cout << "Enter your choice: ";
		cin >> num;
	}

		// echo-print the valid input value
	cout << num << endl << endl;
	
		// return the user's input value
	return num;
}

void CalculatePi()
{
	int num,		// user-defined iteration count
		in = 0;		// count of interior coordinates
	double x,		// x-coordinate of random point
		y;			// y-coordinate of random point

		// prompt for number of iterations.  assumes valid input.
	cout << "Monte Carlo Method for finding PI has been selected" << endl << endl
		<< "Number of iterations: ";
	cin >> num;
	cout << num << endl << endl;

		// loops for input number of iterations
	for(int i = 0; i < num; i++)
	{
			// get random x and y coordinates for calculation
		x = double(rand()/double(RAND_MAX));
		y = double(rand()/double(RAND_MAX));

			// determine if random coordinates exist within a unit circle with center (0,0).
			// if so, increment count of interior coordinates.
		if ( sqrt((pow(x, 2.0) + pow(y, 2.0)) <= 1 ))
			in++;;
	}

		// calculate and output resulting approximation of pi.
	cout << "********** Option 1: Calculating PI **********" << endl
		<< "For " << num << " iterations, pi is about " << fixed << setprecision(6) << double(4.0*(in/double(num))) << endl
		<< string(46, '*') << endl << endl;
	
	return;
}

void CoinFlip()
{
	int num,			// user-defined number of iterations.
		heads = 0;		// count of random values determined to be "heads"

		// prompt for number of iterations.  assumes valid inputs.
	cout << "Flipping of a fair coin has been selected" << endl << endl
		<< "How many flips of the coin? ";
	cin >> num;
	cout << num << endl << endl;
	
		// loops for input number of iterations.
	for(int i = 0; i < num; i++)
	{
			// get random value and increment heads count if value is > 0.5.
		if (double(rand()/double(RAND_MAX)) > 0.5)
			heads++;
	}

		// calculate and output total results of simulation
	cout << "********** Option 2: Flipping a Coin **********" << endl
		<< "For " << num << " flips of a fair coin:" << endl
		<< "Heads percentage: " << fixed << setprecision(4) << 100 * double(heads/double(num)) << endl
		<< "Tails percentage: " << fixed << setprecision(4) << 100 * (1.0 - double(heads/double(num))) << endl
		<< string(47, '*') << endl << endl;
	
	return;
}

void DieRoll()
{
	int num,		// user-defined number of iterations.
		side1 = 0,	// counts of simulated die results
		side2 = 0,
		side3 = 0,
		side4 = 0,
		side5 = 0;

		// prompt for number of iterations.  assumes valid input.
	cout << "Tossing of a fair 5-sided die has been selected" << endl << endl
		<< "How many times do you want to roll the die? ";
	cin >> num;
	cout << num << endl << endl;

		// loop for input number of iterations.
	for(int i = 0; i < num; i++)
	{
			// get random value for current iteration.
		double roll = double(rand()/double(RAND_MAX));

			// compare random value to set breakpoints to determine simulated die result and increment side count.
		if (roll >= 0.8)
			side5++;
		else if (roll >= 0.6)
			side4++;
		else if (roll >= 0.4)
			side3++;
		else if (roll >= 0.2)
			side2++;
		else
			side1++;
	}

		// calculate and output total results of simulation.
	cout << "********** Option 3: Tossing a Die **********" << endl
		<< "For " << num << " rolls of a fair die:" << endl
		<< "Side 1 percentage: " << fixed << setprecision(4) << 100 * double(side1/double(num)) << endl
		<< "Side 2 percentage: " << fixed << setprecision(4) << 100 * double(side2/double(num)) << endl
		<< "Side 3 percentage: " << fixed << setprecision(4) << 100 * double(side3/double(num)) << endl
		<< "Side 4 percentage: " << fixed << setprecision(4) << 100 * double(side4/double(num)) << endl
		<< "Side 5 percentage: " << fixed << setprecision(4) << 100 * double(side5/double(num)) << endl
		<< string(45, '*') << endl << endl;
	
	return;

}