// ****************************************
// Program Title: Project 09
// Project File: Project_09.cpp
// Name: Benjamin Curths
// Course Section: CPE-211-01
// Lab Section: 05
// Due Date: 2020/11/17
// Program Description:  Reads a user-defined input file,
//		populates an array with data from the input file,
//		and outputs statistical values calculated from the input
//		data.  Demonstrates file input and array manipulation.
// *****************************************
#include <iostream>
#include <fstream>
#include <cmath>		// pow(), sqrt()
#include <iomanip>		// setw(), setfill(), left
using namespace std;

void InputFile(ifstream&);		// opens/error-checks the input filestream
void populateArray(ifstream&, float[], int&);	// loads data from input file to the working array
void sortSEL(float[], int);		// selection-sorts the passed array
float Mean(float[], int);		// calculates/returns the mean of the array values
float Median(float[], int);		// calculates/returns the median of the array values
float Variance(float[], int, float);	// calculates/returns the variance of the array values

int main()
{
		// declare necessary variables
	const int MAX_SIZE = 50;	// maximum size value for the working data array
	int size = 0;				// current size of data set read from input file
	float dataArray[MAX_SIZE],	// working data array
		mean,					// temporary storage for mean and variance values used in later calculations
		variance;
	
		// declare input filestream variable and pass to function for user-defined filename input
	ifstream inFile;
	InputFile(inFile);
	
		// populate the working data array from the input file and sort the values from low to high
	populateArray(inFile, dataArray, size);
	sortSEL(dataArray, size);
	
		// call the Mean() and Variance() functions to return and assign their respective values
	mean = Mean(dataArray, size);
	variance = Variance(dataArray, size, mean);

		// main statistics output.  Median() function and previously assigned variables are called for output.
	cout << string(15, '*') << " File Statistics " << string(15, '*') << endl
		<< string(47, '*') << endl;
	cout << setw(25) << setfill('.') << left << "Number of Values" << size << endl;
	cout << setw(25) << setfill('.') << left << "Average" << mean << endl;
	cout << setw(25) << setfill('.') << left << "Median" << Median(dataArray, size) << endl;
	cout << setw(25) << setfill('.') << left << "Variance" << variance << endl;
	cout << setw(25) << setfill('.') << left << "Standard Deviation" << sqrt(variance) << endl;
	cout << string(47, '*') << endl << endl;


	return 0;
}

void InputFile(ifstream& inFile)
{
	string filename;  // user-defined filename
	
	cout << endl << "Enter the name of the input file (ctrl-c to exit): ";
	cin >> filename;
	cout << filename << endl << endl;
	inFile.open(filename.c_str());
	
		// check filestream opened successfully.  If not, clear error and loop until file opened.
	while(!inFile)
	{
		inFile.clear();
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl
			<< "==> Input file could not be opened." << endl
			<< "==> " << filename << " is an invalid file!!" << endl
			<< "==> Try Again." << endl
			<< string(47, '*') << endl << endl;
		
		cout << "Enter the name of the input file (ctrl-c to exit): ";
		cin >> filename;
		cout << filename << endl << endl;
		inFile.open(filename.c_str());
	}
}

void populateArray(ifstream& inFile, float dataArray[], int& size)
{	
		// read size of data set from input file
	inFile >> size;

		// if initial read fails, determine why and display appropriate error before terminating program
	if(!inFile)
		{
			if(inFile.eof())
			{
				cout << string(15, '*') << " Empty Input File " << string(14, '*') << endl
				<< "==> Input file is empty." << endl
				<< "==> Program terminated." << endl
				<< string(47, '*') << endl << endl;
				
				exit(1);
			}
			
			cout << string(15, '*') << " File Read Error " << string(15, '*') << endl
				<< "==> Error occurred reading the number of values" << endl
				<< "==> present in the input file." << endl
				<< "==> Program terminated." << endl
				<< string(47, '*') << endl << endl;
				
			exit(1);
		}

		// loop through remaining values in the input file and store them in the data array
	for(int i=0; i < size; i++)
	{
		inFile >> dataArray[i];
		
					// if data read fails, determine why and display appropriate error before terminating program
		if(!inFile)
		{
			if(inFile.eof())
			{
				cout << string(15, '*') << " File Read Error " << string(15, '*') << endl
				<< "==> Error occurred trying to reading in number #" << (i+1) << endl
				<< "==> Number was not present in the input file." << endl
				<< "==> Program terminated." << endl
				<< string(47, '*') << endl << endl;
				
				exit(1);
			}
			
			cout << string(15, '*') << " File Read Error " << string(15, '*') << endl
				<< "==> Error occurred reading in number #" << (i+1) << endl
				<< "==> Invalid Character found in file." << endl
				<< "==> Program terminated." << endl
				<< string(47, '*') << endl << endl;
				
			exit(1);
		}
	}	
}

void sortSEL(float dataArray[], int size)
{
		// declare variables for sort value storage
	int pos;
	float temp;
	
		// outer loop decreases the operating range of the inner loop for each iteration
	for(int maxElement = (size - 1); maxElement > 0; maxElement--)
	{
		pos = 0;	// reset position marker for each pass through the array

			// inner loop compares each element of the array to the last element to determine the highest value
		for(int j = 0; j < maxElement; j++)
		{
				// compare the active element to the last and stored elements to determine if it is higher...
			if((dataArray[j] > dataArray[maxElement]) && (dataArray[j] >= dataArray[pos]))
				pos = j;	// if so, store the active element index as the highest found
		}
		
			// if the stored element is higher than the last in the iteration, swap the values.
			// the last element is now the highest for the iteration and is removed from consideration
			// in the following iterations.
		if(dataArray[pos] > dataArray[maxElement])
		{
			temp = dataArray[maxElement];
			dataArray[maxElement] = dataArray[pos];
			dataArray[pos] = temp;		
		}
	}
}

float Mean(float dataArray[], int size)
{
		// declare storage variable for sum of data values
	float sum = 0.0;
	
		// add each array element to the sum value
	for(int i = 0; i < size; i++)
		sum += dataArray[i];

		// divide the sum by the number of elements and return the result
	return(sum/float(size));
}

float Median(float dataArray[], int size)
{
		// if the number of elements is odd, return the value of the element in the middle position
	if((size%2) == 1)
		return(dataArray[(size/2)]);
		// if the number of elements is even, return the average of the values in the two middle positions
	else
		return(((dataArray[(size/2)])+dataArray[(size/2)-1])/2.0);
}

float Variance(float dataArray[], int size, float mean)
{
		// declare variable to store the current sum of the calculations
	float tempSum = 0;
	
		// for each element in the array, square the difference between it and the mean of the data set
		// and add the result to the current sum of previous calculations
	for(int i = 0; i < size; i++)
	{
		tempSum += pow((dataArray[i] - mean), 2);
	}
	
		// divide the sum of the squared differences by the number of elements in the array and return the result
	return(tempSum/float(size));
}