// ****************************************
// Program Title: Project 05
// Project File: Project_05.cpp
// Name: Benjamin Curths
// Course Section: CPE-211-01
// Lab Section: 05
// Due Date: 2020/09/27
// Program Description: Reads three score values from
//	an input file, and outputs their sum, average, and
//	relative rating of the average.
//	Demonstrates file input/output, command line arguments,
//	and conditional statements.
// ****************************************

#include <iostream>
#include <iomanip>	// fixed, setw(), setprecision(), left
#include <fstream>
#include <climits>	// INT_MAX

using namespace std;

int main(int argc, char* argv[])
{
		// Test for correct number of command line arguments.
		// If argument count != 3, display error and terminate.
	if (argc != 3)
	{
		cout << endl << string(9, '*') << " Command Line Argument Error " << string(9, '*')
			<< "\n==> Incorrect number of Command Line Arguments!"
			<< "\n==> Command for running the program is:"
			<< "\n==> ./Project_05 inputFileName  outputFileName"
			<< endl << string(47, '*') << endl << endl;
		return 1;
	}

		// Declare/Initialize all used variables.
	float score1,
		score2,
		score3;
	string inFileName = argv[1],
		outFileName = argv[2];
	ifstream fRead;
	ofstream fWrite;

		// Open and test input filestream.
	cout << "\nOpening Input File: " << argv[1] << endl << endl;
	fRead.open(argv[1]);
	if (fRead.fail())
	{
		cout << string(15, '*') << " File Open Error " << string(15, '*')
			<< "\n==> Input file failed to open properly!!"
			<< "\n==> Attempted to open file: " << argv[1]
			<< "\n==> Terminating program!!!"
			<< endl << string(47, '*') << endl << endl;
		return 1;
	}

		// Open and test ouput filestream.
	cout << "Opening Output File: " << argv[2] << endl << endl;
	fWrite.open(argv[2]);
	if (fWrite.fail())
	{
		cout << string(15, '*') << " File Open Error " << string(15, '*')
			<< "\n==> Output file failed to open properly!!"
			<< "\n==> Attempted to open file: " << argv[2]
			<< "\n==> Terminating program!!!"
			<< endl << string(47, '*') << endl << endl;
		return 1;
	}

		// Populate test score variables from input file.
	fRead.ignore(INT_MAX, 'A');
	fRead >> score1;
	fRead.ignore(INT_MAX, 'B');
	fRead >> score2;
	fRead.ignore(INT_MAX, 'C');
	fRead >> score3;
	
		// Input is finished => Close input file.
	fRead.close();
	
		// Test for negative input values.
	if ((score1 < 0) || (score2 < 0) || (score3 < 0))
	{
		cout << string(15, '*') << " Negative Number " << string(15, '*');
		if (score1 < 0)
			cout << "\n==> First number is less than 0";
		if (score2 < 0)
			cout << "\n==> Second number is less than 0";
		if (score3 < 0)
			cout << "\n==> Third number is less than 0";
		cout << "\n==> All numbers should be positive"
			<< "\n==> Terminating program!!!"
			<< endl << string(47, '*') << endl << endl;
		return 1;
	}	
	
		// Process data and write to output file.
	fWrite << fixed << setprecision(2);
	fWrite << string(47, '*') << endl;
	fWrite << setw(35) << left << "The numbers read are:";
	fWrite << score1 << " " << score2 << " " << score3 << endl;
	fWrite << setw(35) << left << "The sum of the numbers is:";
	fWrite << (score1 + score2 + score3) << endl;
	fWrite << setw(35) << left << "The average of these numbers is:";
	fWrite << ((score1 + score2 + score3) / 3.0) << endl;
	fWrite << setw(35) << left << "This average is:";
	if (((score1 + score2 + score3) / 3.0) >= 75)
		fWrite << "High";
	if ((((score1 + score2 + score3) / 3.0) < 75) && (((score1 + score2 + score3) / 3.0) >= 25))
		fWrite << "Medium";
	if ((((score1 + score2 + score3) / 3.0) < 25))
		fWrite << "Low";
	fWrite << endl << string(47, '*') << endl;
	
		// Ouput is finished => Close output file.
	fWrite.close();

	return 0;
}