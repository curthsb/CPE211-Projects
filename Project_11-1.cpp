// ****************************************
// Program Title: Project 11
// Project File: Project_11.cpp
// Name: Benjamin Curths
// Course Section: CPE-211-01
// Lab Section: 05
// Due Date: 2020/12/04
// Program Description: Reads name and test score data from
//	a user-defined input file.  Calculates and outputs per-student
//	and per-class averages as well as high/low scores and grade counts.
// ****************************************

#include <iostream>
#include <iomanip>	// setw(), setprecision(), left, right, setfill(), fixed
#include <fstream>
#include <climits>	// INT_MAX
#include <string>

using namespace std;

void InputFile(ifstream&);	// prompts for and validates user-defined name of input file

int main()
{
	int testCount,	// number of test scores per student
		testSum,	// running total of scores per student
		studentCount = 0;	// increments for each student line processed
		
	int gradeCount[5] = {0,0,0,0,0};	// array for tracking letter-grade counts.  elements from 0 to 4 are A, B, C, D, F.
		
	float average,	// calculated student test average
		classSum = 0,	// running total of test averages for the entire class
		highest = 0,	// highest test average value
		lowest = 100;	// lowest test average value
		
	string firstName,	// student's first name
		lastName;		// student's last name
	
		// declare input filestream and call function for filename definition and opening
	ifstream inFile;
	InputFile(inFile);
	
		// read initial integer value for number of test scores per student
	inFile >> testCount;

		// if initial read fails, file is empty and .eof() is set (valid data is assumed)
	if(inFile.eof())
	{
		cout << string(16, '*') << " File Is Empty " << string(16, '*') << endl
			<< "==> Input file is empty" << endl
			<< "==> No information to process" << endl
			<< string(47, '*') << endl << endl;
			
		return 1;
	}

		// output headings for data table
	cout << left << setw(3) << "#" << setw(12) << "Last" << setw(7) << "First" << setw(9) << "Average"	<< setw(6) << "Grade" << endl;
	cout << left << setw(3) << "-" << setw(12) << "----" << setw(7) << "-----" << setw(9) << "-------"	<< setw(6) << "-----" << endl;
	
		// loop until end of file to process input data.  Valid data is assumed and no further checks are performed.
	while(!inFile.eof())
	{
			// prepare variables for current iteration
		testSum = 0;
		int temp = 0;
		char ch;

			// read name data into string variables
		inFile >> lastName;
		inFile >> firstName;
		
			// individual score values are not needed for output or further calculation.
			// therefore, each input value is read into a temporary variable and added to
			// the running per-student total for calculation of the average value later.
			// loop iteration total depends on testCount value from initial input. 
		for(int i = 0; i < testCount; i++)
		{
			inFile >> temp;
			testSum += temp;
		}

			// calculate and store the average test score value for the student
			// and add the value to the running class total.
		average = static_cast<float>(testSum) / static_cast<float>(testCount);
		classSum += average;
		
			// compare the current average to high/low values and replace as needed
		if(average > highest)
			highest = average;
		if(average < lowest)
			lowest = average;
		
			// compare the student average to letter-grade breakpoints
			// increment the appropriate gradeCount element and assign a value to ch
		if(average >= 90)
		{
			gradeCount[0]++;
			ch = 'A';
		}
		else if(average >= 80)
		{
			gradeCount[1]++;
			ch = 'B';
		}
		else if(average >= 70)
		{
			gradeCount[2]++;
			ch = 'C';
		}
		else if(average >= 60)
		{
			gradeCount[3]++;
			ch = 'D';
		}
		else
		{
			gradeCount[4]++;
			ch = 'F';
		}
		
			// increment the total student count
			// also serves as the line number for output
		studentCount++;
		
			// output the processed line of data per spec
		cout << left << setw(3) << studentCount << setw(12) << lastName.substr(0, 10) << setw(7) << firstName.substr(0, 5) << setw(9) << setprecision(2) << fixed << average << setw(6) << ch << endl;

			// .ignore() to remove errant line breaks before .peek()
			// checks for .eof() before next iteration
		inFile.ignore(INT_MAX, '\n');
		inFile.peek();
	}

		// output processed per-class totals
	cout << endl << setfill('.') << setw(22) << "Class Average" << (classSum / static_cast<float>(studentCount)) << endl
		<< setw(22) << "Highest Average" << highest << endl
		<< setw(22) << "Lowest Average" << lowest << setfill(' ') << endl << endl;
		
		// output letter-grade histogram
		// for each letter-grade, cout through a for() loop a number of iterations
		// determined by the corresponding array element
	cout << right << setw(18) << "Grade Histogram" << endl
		<< "           1         2" << endl
		<< "  12345678901234567890" << endl;
	cout << "A:";
		for(int i = 0; i < gradeCount[0]; i++)
			cout << '*';
	cout << endl << "B:";
		for(int i = 0; i < gradeCount[1]; i++)
			cout << '*';
	cout << endl << "C:";
		for(int i = 0; i < gradeCount[2]; i++)
			cout << '*';
	cout << endl << "D:";
		for(int i = 0; i < gradeCount[3]; i++)
			cout << '*';
	cout << endl << "F:";
		for(int i = 0; i < gradeCount[4]; i++)
			cout << '*';
	cout << endl << endl;
	
	
	return 0;
}

void InputFile(ifstream& inFile)
{
	string filename;	// stores user-defined name of input file
	
		// prompt for and attempt to open user-defined file
	cout << endl << "Enter the name of the input file: ";
	cin >> filename;
	cout << filename << endl << endl;
	inFile.open(filename.c_str());
	
		// if filestream fails, loop until file opens properly
	while(!inFile)
	{
		inFile.clear();
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl
			<< "==> Input file failed to open properly!!" << endl
			<< "==> Attempted to open file: " << filename << endl
			<< string(47, '*') << endl << endl
			<< "Try Again..." << endl << endl;
		
		cout << "Enter the name of the input file: ";
		cin >> filename;
		cout << filename << endl << endl;
		inFile.open(filename.c_str());
	}
}