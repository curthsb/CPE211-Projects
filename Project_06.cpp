// ****************************************
// Program Title: Project 06
// Project File: Project_06.cpp
// Name: Benjamin Curths
// Course Section: CPE-211-01
// Lab Section: 05
// Due Date: 2020/10/06
// Program Description: Program demonstrates the use of sentinel-
//	controlled loops to parse text from an input file.
// *****************************************
#include <iostream>
#include <iomanip>	// fixed, left, setw()
#include <cctype>	// isalpha(), isdigit()
#include <string>
#include <fstream>
#include <climits>	// INT_MAX

using namespace std;

int main()
{
		// declare/initialize variables
	int lineAlpha = 0,
		totalAlpha = 0,
		lineDigit = 0,
		totalDigit = 0,
		lineMisc = 0,
		totalMisc = 0,
		lineCount = 0;
	string fileName;
	char ch;
	ifstream fRead;
		
		// prompt for input file
	cout << endl << "Enter in the name of the input file: ";
	cin >> fileName;
	cout << fileName;	// echo print
		
		// open/test for valid input file
	fRead.open(fileName.c_str());
	
	while(fRead.fail())
	{
			// loop to correct invalid filename
		cout << endl << endl << string(15, '*') << " File Open Error " << string(15, '*') << endl
			<< "==> Input file failed to open properly!!" << endl
			<< "==> Attempted to open file: " << fileName << endl
			<< "==> Please try again..." << endl
			<< string(47, '*') << endl;
		fRead.clear();	// reset fRead from failure
		cin.clear();	// reset and clear cin for next input
		cin.ignore(INT_MAX, '\n');
		cout << endl << "Enter in the name of the input file: ";
		cin >> fileName;
		cout << fileName;	// echo print
		fRead.open(fileName.c_str());
	}
		
		// error if empty file/doubles as priming read
	if(!fRead.get(ch))
	{
		cout << endl << endl << string(13, '*') << " Input File Is Empty " << string(13, '*') << endl
			<< "==> The input file is empty." << endl
			<< "==> Terminating the program." << endl
			<< string(47, '*') << endl << endl;
		return 1;
	}

		// output headings for data
	cout << endl << endl << setw(15) << left << "Line number" << setw(10) << "Letters" << setw(10) << "Digits" << setw(10) << "Other" << setw(10) << "Total" << endl
		<< setw(15) << "-----------" << setw(10) << "-------" << setw(10) << "------" << setw(10) << "-----" << setw(10) << "-----" << endl;
	
		// post-test outer loop for progressing through file
		// and output of per-line character counts
	do
	{		
			// clear line variables for current iteration
		lineAlpha = lineDigit = lineMisc = 0;
	
			// inner loop for processing of each line
		while((!fRead.eof()) && (ch != '\n'))
		{
			if(isalpha(ch))
				lineAlpha++;
			else if(isdigit(ch))
				lineDigit++;
			else
				lineMisc++;
			
			fRead.get(ch);
		}

			// increment line count (includes final line)
		lineCount++;
			// include final '\n', if present, in lineMisc total
		if(ch == '\n')
			lineMisc++;
		
		cout << setw(15) << left << lineCount << setw(10) << lineAlpha << setw(10) << lineDigit << setw(10) << lineMisc << setw(10) << (lineAlpha + lineDigit + lineMisc) << endl;
		
			// add line values to total values
		totalAlpha = (totalAlpha + lineAlpha);
		totalDigit = (totalDigit + lineDigit);
		totalMisc = (totalMisc + lineMisc);
	
		fRead.get(ch);
		
	}while(!fRead.eof());

		// cleanup
	fRead.close();
	
		// final output of per-file character counts
	cout << string(50, '-') << endl
		<< setw(15) << left << "Totals" << setw(10) << totalAlpha << setw(10) << totalDigit << setw(10) << totalMisc << setw(10) << (totalAlpha + totalDigit + totalMisc) << endl
		<< setw(15) << "Percent";
	cout << fixed << setprecision(2) << setw(10) << (totalAlpha/static_cast<double>(totalAlpha + totalDigit + totalMisc))*100 << setw(10) << (totalDigit/static_cast<double>(totalAlpha + totalDigit + totalMisc))*100 << setw(10) << (totalMisc/static_cast<double>(totalAlpha + totalDigit + totalMisc))*100 << endl << endl;
		
	
	return 0;
}