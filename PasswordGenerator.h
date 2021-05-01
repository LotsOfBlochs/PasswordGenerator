// PasswordGenerator.h : Include file for standard system include files,
// or project specific include files.

#pragma once


#include "Constants.h"
#include "CheckOptions.h"
#include "Generator.h"
#include <iostream>
#include <fstream>

namespace PasswordGenerator {
	class PasswordGen
	{
	public:
		static int str2int(const char* s);
	};
}
