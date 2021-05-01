#pragma once

#include <string>
#include "Constants.h"
#include <iostream>
#include <fstream>

namespace PasswordGenerator {
	class Output
	{
	public:
		static void toCli(std::string list);
		static void toFile(std::string list);

	private:

	};
}