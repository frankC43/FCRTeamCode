#include <iostream>

extern "C" bool IsValidAssembly(int a, int b, int c);


/**
* Read two strings from the console, if one of both is incorrect the program ends.
* 
* @return true if and only if both pass stirng are valid
*/
bool checkPass()
{
	char string[20];

	std::cout << "Introduce input: " << std::endl;
	std::cin.width(20);
	std::cin >> string;
	if ( strcmp(string, "nydhov") == 0 ) {

		std::cout <<  "Introduce key input: " << std::endl;
		std::cin >> string;

		if (strlen(string) >= 5 && string[3] == string[4] ){
			return true;
		}
		else {
			std::cout << "Fail" << std::endl;
			exit(1);
		}

	}
	else {
		std::cout << "Wrong input" << std::endl;
		exit(1);
	}

}

int main()
{
	bool isValid = checkPass();
	std::cout << "is : " << isValid << std::endl;

	return 0;
}
