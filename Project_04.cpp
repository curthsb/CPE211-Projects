// ****************************************
// Program Title: Project 04
// Project File: Project_04.cpp
// Name: Benjamin Curths
// Course Section: CPE-211-01
// Lab Section: 05
// Due Date: 2020/09/13
// Program Description:  Calculates and outputs
// the ballistic properties of a projectile given
// file input of initial conditions.
// *****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>	// setw(), setprecision(), left
#include <cmath>	// pow(), sin(), cos()
using namespace std;

int main()
{
		// Declare and initialize variables.
		// Gravitational acceleration and pi are constants.
		// All variables are initialized with default values.
	const double PI = 3.14159265,
			GRAV = 9.80665;
	double velocity = 0.0,
			angle = 0.0;
	string filename = "None";
			
		// Declare input filestream object.
	ifstream fRead;
	
	cout << endl << string(30, '*') << endl
		<< "***** Projectile Motion\n"
		<< string(30, '*') << endl << endl;
	
		// Request user input of datafile name.
		// This is the only use of the standard input so
		// cleaning of the input buffer is not performed.
	cout << "Enter the name of the input file: ";
	getline(cin, filename, '\n');
	cout << filename << endl;

		// Attempt to open the user-defined filename.
	fRead.open(filename.c_str());
	
		// If file fails to open, report the error and terminate
		// the program, returning exit value of 1 per spec.
	if(fRead.fail())
	{
			cout << endl << string(47, '*') << endl
				<< "==> Input file failed to open properly!\n"
				<< "==> Name of file opened: " << filename << endl
				<< "==> Terminating program!!!\n"
				<< string(47, '*') << endl;
				return 1;
	}

		// Read the values from the file into the
		// appropriate variables.
	fRead >> velocity >> angle;

		// Output initial values read from file.
	cout << "\nInitial Velocity(in m/s): " << velocity
		<< "\n\nStarting angle(in degrees): " << angle << endl;
	
		// Set output data formatting per spec. 
	cout << fixed << setprecision(3);

		// Calculate and output the required results
		// formatted per spec.
	cout << "\nResults:"
		<< "\n--------\n"
		<< setw(25) << left << "Time to max height:" << (velocity*sin((angle*PI)/180))/GRAV << " seconds" << endl
		<< setw(25) << left << "Time to max distance:" << (2*velocity*sin((angle*PI)/180))/GRAV << " seconds" << endl
		<< setw(25) << left << "Maximum height:" << (pow(velocity, 2)*pow(sin((angle*PI)/180), 2))/(2*GRAV) << " meters" << endl
		<< setw(25) << left << "Maximum distance:" << velocity*((2*velocity*sin((angle*PI)/180))/GRAV)*cos((angle*PI)/180) << " meters";
		
	cout << endl << endl;

		// Close the opened file as cleanup.
	fRead.close();
	
	return 0;
}
