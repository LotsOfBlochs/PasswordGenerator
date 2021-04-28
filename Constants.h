#pragma once
#include <string>
namespace PasswordGenerator {
	class Constants
	{
	public:
		static bool list; //Whether it should produce a list of possible passwords or a single random password
		static std::string outputFile; //File to output to 
		static bool outputToFile; //Whether it should output to file
		//void setupConstants(); //Sets default settings for all outputs

	};
}
