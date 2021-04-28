// PasswordGenerator.cpp : Defines the entry point for the application.
//

#include "PasswordGenerator.h"

using namespace std;

#include "Constants.h"

using namespace PasswordGenerator;

int main(int argc, char** argv) {
	if (argc == 1) {
		printf("Please include a valide number of options.\n For more help try:\n \"PasswordGen -h\"\n");
	}
	else {
		for (int i = 0; i < argc; ++i) {
			std::string arg = argv[i];
			if (arg == "-h") { //Option for printing the Help statement
				printf("Insert Help statement here\n Please Do it\n I need help\n");
			}
			else if (arg == "-l") { //Option for list of all possible passwords between 2 lengths
				Constants::list = true;
			}
			else if (arg == "-s") { //Option for a single random password
				Constants::list = false;
			}
			else if (arg == "-o") { //Option for setting an output file
				Constants::outputFile = argv[i + 1];
				Constants::outputToFile = true;
			}
		}
	}
	return 0;
}