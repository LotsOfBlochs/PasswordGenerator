// PasswordGenerator.cpp : Defines the entry point for the application.
//

#include "PasswordGenerator.h"

using namespace std;
using namespace PasswordGenerator;

string passwordsList;

int main(int argc, char** argv) {
	printf("Welcome to the Password Generator\n\n");
	if (argc == 1) {
		//Constants::single = true;
		//Constants::length = 12;
		//Constants::lengthSet = true;
		//goto test;
		cout << "Please use a valid number of options!";
		return 1;
	}
	else {
		for (int i = 0; i < argc; ++i) {
			string arg = argv[i];
			if (arg == "-h") { //Option for printing the Help statement
				cout << "Insert Help statement here\nPlease Do it\nI need help\n";
				return 0;
			}
			else if (arg == "-l") { //Option for list of all possible passwords between 2 lengths
				Constants::list = true;
			}
			else if (arg == "-s") { //Option for a single random password
				Constants::single = true;
			}
			else if (arg == "-o") { //Option for setting an output file
				Constants::outputFile = argv[i + 1];
				Constants::outputToFile = true;
			}
			else if (arg == "-m") { //Option for setting the minimum length
				Constants::minimum = PasswordGen::str2int(argv[i + 1]);
				Constants::minimumSet = true;
			}
			else if (arg == "-M") { //Option for setting maximum length
				Constants::maximum = PasswordGen::str2int(argv[i + 1]);
				Constants::maximumSet = true;
			}
			else if (arg == "-L") { //Option for setting the length
				Constants::length = PasswordGen::str2int(argv[i + 1]);
				Constants::lengthSet = true;
			}
		}
		//.test:
		if (CheckOptions::check() == 1) {
			printf("There was an error in your options, Failed to run.\nFor more help try:\n\"PasswordGen -h\"\n");
			return 1;
		}
		else
		{
			printf("Executing with settings\n");
			if (Constants::list) {
				passwordsList = Generator::list(); //generates a list of all passwords that meet the requirments
			}
			else if (Constants::single) {
				passwordsList = Generator::single(); //generates a single random password that meets the requirments
			}
			else {
				return 1;
			}
			if (Constants::outputToFile) {
				ofstream file(Constants::outputFile);
				file << passwordsList;
				file.close();
				return 0;
			}
			else {
				cout << passwordsList;
				return 0;
			}
		}
	}
	printf("Exiting for unkown reason!");
	return 0;
}

int PasswordGen::str2int(const char* s)
{
	int res = 0;
	while (*s) {
		res *= 10;
		res += *s++ - '0';
	}

	return res;
}