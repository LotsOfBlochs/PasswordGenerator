#pragma once
#include <string>
namespace PasswordGenerator {
	class Constants
	{
	public:
		static bool list; //Selects a list of possible passwords as output
		static std::string outputFile; //File to output to 
		static bool outputToFile; //Whether it should output to file
		static bool single; //Selects a single random password as output
		static int minimum; //Selects what the minimum value is 
		static bool minimumSet; //Selects whether to use the minimum value
		static int maximum; //Selects what the maximum value is 
		static bool maximumSet; //Selects whether to use the maximum value
		static int length; //Selects the length of the password
		static bool lengthSet; //Selects whether the length is set
	};
}
