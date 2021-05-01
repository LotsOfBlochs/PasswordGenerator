#include "Output.h"


using namespace std;
using namespace PasswordGenerator;


void Output::toCli(string list) {
	cout << list;
}

void Output::toFile(string list){
	ofstream file(Constants::outputFile);
	file << list;
	file.close();
}
