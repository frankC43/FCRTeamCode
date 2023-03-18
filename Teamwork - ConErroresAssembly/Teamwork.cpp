#include <iostream>

extern "C" bool IsValidAssembly(int a, int b, int c);

using std::cin;
using std::cout;
using std::endl;
/**
* Read two strings from the console, if one of both is incorrect the program ends.
* 
* @return true if and only if both pass stirng are valid
*/
bool checkPass()
{
	char string[20];

	cout << "Introduce input: " << endl;
	cin.width(20);
	cin >> string;
	if ( strcmp(string, "nydhov") == 0 ) {
		cout <<  "Introduce key input: " << endl;
		cin >> string;
		if (strlen(string) >= 5 && string[3] == string[4] ){
			return true;
		}
		else {
			cout << "Fail" << endl;
			exit(1);
		}
	}
	else {
		cout << "Wrong input" << endl;
		exit(1);
	}
}

bool checkMask() 
{
	//unsiged int of 32 bits
	unsigned int firstInput;
	unsigned int secondInput;

	cout << "First number: " << endl;
	cin >> firstInput;
	cout << "Second number: " << endl;
	cin >> secondInput;

	/*
		Perform a bit mask of the second and first inputs:
		Draw of input bits:
		 XXXX XXXX XXXX XXXX	XXXX XXXX XX[XX X]XXX 

		 In order to check try with second Input = 56 , the result in bits6To4Second must be 5, as 56 : 0...00011 1000
		 In order to check try with first Input = 0 , the condition must be accepted as all bits are 0...0
	*/
	int bits6To4Second = (secondInput & 0x00000028) >> 3;
	if (bits6To4Second != 5) {
		cout << "There was an error" << endl;
		exit(1);
	}

	int bit6FirstIsZero = (firstInput & 0x00000020) >> 4;
	if (bit6FirstIsZero != 0) {
		cout << "Error" << endl;
		exit(1);
	}

	int sig21BitsFirst = (firstInput & 0xfffff800) >> 15;
	int least11BitsSecond = (secondInput & 0x000007ff); //It is already at the right side, no need to swift
	if (sig21BitsFirst + least11BitsSecond > 18437) {
		cout << "Error" << endl;
		exit(1);
	}
	return true;
}

bool assemblyAccess() {
	signed int int1Assembly;
	signed int int2Assembly;
	signed int int3Assembly;
	cout << "first: " << endl;
	cin >> int1Assembly;
	cout << "second: " << endl;
	cin >> int2Assembly;
	cout << "third: " << endl;
	cin >> int3Assembly;

	if (IsValidAssembly(int1Assembly, int2Assembly, int3Assembly) != 1) {
		cout << "There was an error" << endl;
		exit(1);
	}
	return true;
}

int main()
{
	//checkPass();
	//checkMask();
	assemblyAccess();  //WARNIGN: 1.2v of this code has errors in assembly part, ask for the syntax error of the assembly

	return 0;
}
