#pragma once
#include <string>
#include <vector>
#include "Constants.h"

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