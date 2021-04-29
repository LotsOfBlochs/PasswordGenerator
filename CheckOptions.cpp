#include "CheckOptions.h"

using namespace PasswordGenerator;

int PasswordGenerator::CheckOptions::check()
{
	if (Constants::list && Constants::single) { //fail the check if single random and a list of possible passwords are selected
		return 1;
	}
	else if (Constants::lengthSet && Constants::maximumSet || Constants::lengthSet && Constants::minimumSet) { //fail if length is set and maximum or minimum values are set
		return 1;
	}
	else if (Constants::maximumSet != Constants::minimumSet) { //fail if maximum and minimum are not both set or unset
		return 1;
	}
	else {
		return 0;
	}
}
