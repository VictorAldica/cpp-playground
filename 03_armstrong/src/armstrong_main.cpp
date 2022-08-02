#include <iostream>

bool isArmstrongNumber(int number)
{
	int nr = number;
	int digit = -1;
	int armstrong = 0;
	while (nr)
	{
		digit = nr % 10;
		armstrong += digit * digit * digit;
		nr /= 10;
	}
	if (armstrong == number) return true;
	return false;
}

bool printNAN(const char* input)
{
	bool nan = false;
	for (int i = 0; i < strlen(input); i++)
		if (input[i] < '0' && input[i]>'9') nan = true;
	return nan;
}


void printIsArmstrong(int number)
{
	if (isArmstrongNumber(number))
	{
		std::cout << "Armstrong" << std::endl;
	}
	else
	{
		std::cout << "NOT Armstrong" << std::endl;
	}
}

int main(int argc, char *argv[])
{
	// What is this program expected to do?
	// - Shows whether an argument is an armstrong number.
	// (what?)
	// -	An Armstrong number is a number that is equal to the sum of cubes of its digits.
	//		For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
	//		Let's try to understand why 153 is an Armstrong number:
	//			1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
	//
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  03_armstrong.exe 1		=> Output: Armstrong
	//		  03_armstrong.exe 2		=> Output: NOT Armstrong
	//		  03_armstrong.exe 			=> Output: No program arguments found.
	//		  03_armstrong.exe ABC		=> Undefined output (do whatever).
	//		  03_armstrong.exe 153		=> Output: Armstrong
	//		  03_armstrong.exe 154		=> Output: NOT Armstrong
	//

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		std::cout << "No program arguments found." << std::endl;
		return 1;
	}

	int readNumber = 0;
	// Get the first argument
	std::string argumentAsString = argv[1];
	const char* argumentAsCharArray = argumentAsString.c_str();
	if(printNAN(argumentAsCharArray))
		std::cout<<"NAN\n";
	else
	{
		readNumber = atoi(argumentAsCharArray);
		printIsArmstrong(readNumber);
	}
	return 0;
}