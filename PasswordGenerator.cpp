// PasswordGenerator.cpp : Defines the entry point for the application.
//

#include "PasswordGenerator.h"
#include <iostream>

using namespace std;
using namespace PasswordGenerator;

string passwordsList;

int main(int argc, char** argv) {
	if (argc == 1) {
		printf("Please include a valid number of options.\nFor more help try:\n\"PasswordGen -h\"\n");
		return 1;
	}
	else {
		for (int i = 0; i < argc; ++i) {
			string arg = argv[i];
			if (arg == "-h") { //Option for printing the Help statement
				printf("Insert Help statement here\nPlease Do it\nI need help\n");
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
			else if (arg == "-m")
			{
				Constants::minimum = (int)argv[i + 1] - 48;
				Constants::minimumSet = true;
			}
			else if (arg == "-M")
			{
				Constants::maximum = (int)argv[i + 1] - 48;
				Constants::maximumSet = true;
			}
			else if (arg == "-L")
			{
				Constants::length = (int)argv[i + 1] - 48;
				Constants::lengthSet = true;
			}
		}
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
				//Output::toFile(passwords);
			}
			else {
				//Output::toCli(passwords);
				cout << passwordsList;
			}
		}
	}
	return 0;
}