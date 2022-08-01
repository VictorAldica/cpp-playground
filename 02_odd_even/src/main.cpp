#include <stdio.h>
#include <iostream>
#include <string>


void printOddOrEven(int number)
{
	if(!number)
	{
		printf("NAN\n");
	}
	else if (number % 2 == 0)
	{
		printf("EVEN\n");
	}
	else
	{
		printf("ODD\n");
	}
}

bool printNAN(const char* input)
{
	bool nan = false;
	for (int i = 0; i < strlen(input); i++)
		if (input[i] < '0' && input[i]>'9') nan = true;
	return nan;
}

int main(int argc, char *argv[])
{
	int number = -13;

	// What is this program expected to do?
	// - Shows whether an argument is an ODD or EVEN number.
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  02_odd_even.exe 1		=> Output: ODD
	//		  02_odd_even.exe 2		=> Output: EVEN
	//		  02_odd_even.exe 		=> Output: No program arguments found.
	//		  02_odd_even.exe ABC   => Undefined output (do whatever).
	//		

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		printf("No program arguments found.\n");
	}
	
	// TODO(Gusti): i don't know why this doesn't work, but someone please FIX it.
	// --------------- start

	// Get the first argument
	std::string argumentAsString = argv[1];
	const char* argumentAsCharArray = argumentAsString.c_str();
	
	if (printNAN(argumentAsCharArray))
		printf("NAN\n");
	else
		number = atoi(argumentAsCharArray);
	
	// --------------- stop

	printOddOrEven(number);

	return 0;
}