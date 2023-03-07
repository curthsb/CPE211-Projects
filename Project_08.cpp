// ****************************************
// Program Title: Project 08
// Project File: Project_08.cpp
// Name: Benjamin Curths
// Course Section: CPE-211-01
// Lab Section: 05
// Due Date: 2020/11/03
// Program Description:  Reads a user-defined input file,
//		tests the input data for a given condition, and writes
//		qualifying data to a user-defined output file.  Demonstrates
//		the declaration and use of structured data.
// *****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <climits>	// INT_MAX

using namespace std;

	// declare necessary structures.
struct SubscriberName
{
	string first;
	string last;
	int custID;
};
struct Address
{
	string street;
	string city;
	string state;
	int zip;
};
struct Date
{
	string month;
	int day;
	int year;
};
struct RenewalInfo
{
	int remaining;
	Date lastNotice;
};
struct SubscriberRecord
{
	SubscriberName name;
	Address address;
	RenewalInfo renew;
};

	// function prototypes
void InputFile(ifstream&);	// opens/error-checks the input filestream
void OutputFile(ofstream&);	// opens/error-checks the output filestream
SubscriberRecord PopulateRecord(ifstream&);		// extracts data from input file and populates the working struct
void WriteRecord(ofstream&, SubscriberRecord);	// writes qualifying records to the output file

int main()
{
		// Declare necessary variables.
	int custCount = 0,
		expiredCount = 0;
	ifstream inFile;
	ofstream outFile;	
	SubscriberRecord currentRecord;
	
		// call functions to set up filestreams with user-defined filenames
	InputFile(inFile);
	OutputFile(outFile);
	
		// check input file for data.  If eof, write output and terminate.
	inFile.peek();  // sets eof flag if file is empty
	if(inFile.eof())
	{
		outFile << string(52, '-') << endl
				<< "==> The input file does not contain any information." << endl
				<< string(52, '-') << endl;

		cout << "===> Input file is empty.  Program terminated" << endl << endl;
		return(1);
	}

		// if file is not empty, call functions to process records.  Loop until file is empty.
	while(!inFile.eof())
	{
		currentRecord = PopulateRecord(inFile);	// populates working structure
		custCount++;
		
			// if data qualifies, write record to output file
		if(currentRecord.renew.remaining == 0)
		{
			expiredCount++;
			WriteRecord(outFile, currentRecord);
		}
	}

		// output total record counts to terminal
	cout << endl << string(47, '-') << endl
		<< "Number of subscribers processed: " << custCount << endl
		<< "The number of expired subscriptions is: " << expiredCount << endl
		<< string(47, '-') << endl << endl;

		// cleanup
	inFile.close();
	outFile.close();

	return 0;
}

void InputFile(ifstream& inFile)
{
	string filename;  // user-defined filename
	
	cout << endl << "Enter name of input file or Control-C to quit program: ";
	cin >> filename;
	cout << filename << endl << endl;
	inFile.open(filename.c_str());
	
		// check filestream opened successfully.  If not, clear error and loop until file opened.
	while(!inFile)
	{
		inFile.clear();
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl
			<< "==> Input file failed to open properly!!" << endl
			<< "==> Attempted to open file: " << filename << endl
			<< "==> Please try again..." << endl
			<< string(47, '*') << endl << endl;
		
		cout << "Enter name of input file or Control-C to quit program: ";
		cin >> filename;
		cout << filename << endl << endl;
		inFile.open(filename.c_str());
	}
}

void OutputFile(ofstream& outFile)
{
	string filename;	// user-defined filename
	
	cout << "Enter name of output file or Control-C to quit program: ";
	cin >> filename;
	cout << filename << endl << endl;
	outFile.open(filename.c_str());
	
		// check filestream opened successfully.  If not, clear error and loop until file opened.
	while(!outFile)
	{
		outFile.clear();
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl
			<< "==> Output file failed to open properly!!" << endl
			<< "==> Attempted to open file: " << filename << endl
			<< "==> Please try again..." << endl
			<< string(47, '*') << endl << endl;
		
		cout << "Enter name of output file or Control-C to quit program: ";
		cin >> filename;
		cout << filename << endl << endl;
		outFile.open(filename.c_str());
	}
}

SubscriberRecord PopulateRecord(ifstream& inFile)
{
		// declare used variables.  temp variables probably not
		// needed, but employed during debugging and didn't bother removing.
	SubscriberRecord inputRecord;
	string tempStr;
	int tempNum;
	
		// extraction operator reads each entry from the input file.
		// ignore function used to remove remaining '\n' from each line.
	inFile >> tempStr;
		inFile.ignore(INT_MAX, '\n');
		inputRecord.name.first = tempStr;
	inFile >> tempStr;
		inFile.ignore(INT_MAX, '\n');
		inputRecord.name.last = tempStr;
	inFile >> tempNum;
		inFile.ignore(INT_MAX, '\n');
		cout << "====> Processing Customer ID: " << tempNum << endl;	// output to terminal the current entry ID
		inputRecord.name.custID = tempNum;
	getline(inFile, tempStr);
		inputRecord.address.street = tempStr;
	getline(inFile, tempStr);
		inputRecord.address.city = tempStr;
	getline(inFile, tempStr);
		inputRecord.address.state = tempStr;
	inFile >> tempNum;
		inFile.ignore(INT_MAX, '\n');
		inputRecord.address.zip = tempNum;
	inFile >> tempNum;
		inFile.ignore(INT_MAX, '\n');
		inputRecord.renew.remaining = tempNum;
	inFile >> tempStr;
		inFile.ignore(INT_MAX, '\n');
		inputRecord.renew.lastNotice.month = tempStr;
	inFile >> tempNum;
		inFile.ignore(INT_MAX, '\n');
		inputRecord.renew.lastNotice.day = tempNum;
	inFile >> tempNum;
		inFile.ignore(INT_MAX, '\n');	
		inputRecord.renew.lastNotice.year = tempNum;

	inFile.peek();  // checks for any remaining data in file before next main loop iteration
	
	return(inputRecord);	// returns the populated structure
}

void WriteRecord(ofstream& outFile, SubscriberRecord outputRecord)
{
		// outputs the structure parameter to the output filestream, formatted per spec. 
	outFile << string(55, '*') << endl
			<< outputRecord.name.first << " " << outputRecord.name.last << "(" << outputRecord.name.custID << ")" << endl
			<< outputRecord.address.street << endl
			<< outputRecord.address.city << ", " << outputRecord.address.state << " " << outputRecord.address.zip << endl
			<< "The last renewal notice was sent on " << outputRecord.renew.lastNotice.month << " " << outputRecord.renew.lastNotice.day << ", " << outputRecord.renew.lastNotice.year << endl
			<< string(55, '*') << endl << endl;
}