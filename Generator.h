#pragma once
#include <string>
#include <vector>
#include "Constants.h"
#include <iostream>

namespace PasswordGenerator {
	class Generator
	{
	public:
		static std::string list();
		static std::string single();
		static void addToList();

	private:


	};
}