#include <iostream>

extern "C" bool IsValidAssembly(int a, int b, int c);

using std::cin;
using std::cout;
using std::endl;
/**
* Read two strings from the console, if one of both is incorrect the program ends.
* @return true if and only if both pass stirng are valid
*/
bool CheckPass()
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

bool CheckMask() 
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
		 XXXX XXXX XXXX XXXX	XXXX XXXX XXXX XXXX 

	*/
	int bits6To4Second = (secondInput & 0x00000038) >> 3;
	if (bits6To4Second != 5) {
		cout << "There was an error" << endl;
		exit(1);
	}

	int bit6FirstIsZero = (firstInput & 0x00000030) >> 4;
	if (bit6FirstIsZero != 0) {
		cout << "Error" << endl;
		exit(1);
	}

	int sig21BitsFirst = (firstInput & 0xfffff800) >> 15;
	int least11BitsSecond = (secondInput & 0x000007ff); //It is already at the right side, no need to swift
	if (sig21BitsFirst + least11BitsSecond < 18437) {
		cout << "Error" << endl;
		exit(1);
	}
	return true;
}

/*
	To try the functionality of isValidAssembly you can try with:

		Valid :  a = 67 b = 0 c = 0

		Invalid : a <= 66

*/
bool AssemblyAccess() {
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

/*
	
	To try this function:

	Good inputs:
		num1 = 81	num2 = 81	num3 = 81

	Wrong inputs:
		num1 = 81	num2 = 0	num3 = 0
*/
bool ArrayValues() {
	const unsigned int arrayLength = 3;
	signed int num1;
	signed int num2;
	signed int num3;

	cout << "Input the first integer: " << endl;
	cin >> num1;
	cout << "Input the second integer: " << endl;
	cin >> num2;
	cout << "Input the third and final integer: " << endl;
	cin >> num3;
	int array[arrayLength] = { num1, num2, num3 };

	int bitwiseAnd = num1 & num2 & num3;
	if (bitwiseAnd != 81) {
		cout << "That's wrong";
		exit(1);
	}
	return true;
}

int main()
{
	CheckPass();
	CheckMask();
	AssemblyAccess();
	ArrayValues();
	cout << "Correct" << endl;
	
	return 0;
}