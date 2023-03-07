// ****************************************
// Program Title: Project 03
// Project File: Project_03.cpp
// Name: Benjamin Curths
// Course Section: CPE-211-01
// Lab Section: 05
// Due Date: 2020/09/07
// Program Description:  Calculates and outputs
// the accrued balance of a saving account using
// multiple interest intervals.
// *****************************************
#include <iostream>
#include <iomanip>	// fixed, setprecision()
#include <cmath>	// pow(), exp()
using namespace std;

int main()
{
		// Declare variables for user input.
	double principle,
			rate,
			term;
		
		// Prompt for user input and echo input values.
	cout << "\nInput the starting balance: ";
	cin >> principle;
	cout << principle;
	
	cout << "\nInput the interest rate (Ex: 5 for 5%): ";
	cin >> rate;
	cout << rate;
	
	cout << "\nInput the number of years: ";
	cin >> term;
	cout << term;

		// Set desired formatting for output
	cout << fixed << setprecision(2);

		// Summary of user input to be used in calculations.
	cout << "\n\nFor a principle of $" << principle
		<< "\nat an interest rate of " << rate << "%"
		<< "\nfor a period of " << term << " years,"
		<< "\nthe final account balance would be:";

		// Variable rate is adjusted from input value
		// to simplify calculations.
	rate = rate/100;

		// Baseline simple interest calculation and output.
	cout << "\n\nSimple Interest:"
		"\n\tBalance = $" << principle*(1+rate*term);

		// Compound interest calculation and output.
		// First statement calculates monthly (12*term).
		// Second statement calculates daily (365*term).
		// Formulae are identical with exception of 12->365.
	cout << "\n\nCompounded Monthly:"
		<< "\n\tBalance = $" << principle*pow((1+(rate/12)),(term*12))
		<< "\n\tThe Effective Simple Interest Rate: " << ((pow((1+(rate/12)),(term*12))-1)/term)*100 << "%"
		<< "\n\tBalance using Simple Interest at the Effective Rate = $" << principle*(1+((((pow((1+(rate/12)),(term*12))-1)/term))*term));

	cout << "\n\nCompounded Daily:"
		<< "\n\tBalance = $" << principle*pow((1+(rate/365)),(term*365))
		<< "\n\tThe Effective Simple Interest Rate: " << ((pow((1+(rate/365)),(term*365))-1)/term)*100 << "%"
		<< "\n\tBalance using Simple Interest at the Effective Rate = $" << principle*(1+((((pow((1+(rate/365)),(term*365))-1)/term))*term));

		// Continuous interest calculation and output.
	cout << "\n\nCompounded Continuously:"
		<< "\n\tBalance = $" << principle*exp(rate*term)
		<< "\n\tThe Effective Simple Interest Rate: " << ((exp(rate*term)-1)/term)*100 << "%"
		<< "\n\tBalance using Simple Interest at the Effective Rate = $" << principle*(1+((((exp(rate*term)-1)/term))*term));
		
	cout << endl << endl;

	return 0;
}
