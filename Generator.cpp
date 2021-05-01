#include "Generator.h"
#include <string.h>

using namespace PasswordGenerator;
using namespace std;

string passwords;
string charecters[] = { " ", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "\\", "]", "^", "_", "`", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "{", "|", "}", "~" };
vector<string> currentWords(1,"");
vector<int> nextLetters(1,0);
string word;
int maxLevel;

int i = 0;

string Generator::list() {
	addToList();
	return passwords;
}

string Generator::single() {
	return "";
}

void Generator::addToList() {
	i++;
	if (i > maxLevel) {
		maxLevel = i;
		currentWords.push_back(word);
		nextLetters.push_back(0);
	}
	currentWords[i] = word;
	//currentWords.at(i) = word;
	nextLetters[i] = 0;
	//nextLetters.at(i) = 0;
	for (const auto& y : charecters) {
		word = currentWords[i];
		word = word + charecters[nextLetters[i]];
		nextLetters[i] += 1;
		if (Constants::lengthSet == false) {
			if (word.length() >= Constants::minimum) {
				passwords = passwords + word + "\n";
			}if (Constants::maximum > i) {
				addToList();
			}
		}
		else if (Constants::lengthSet == true) {
			if (word.length() == Constants::length) {
				passwords = passwords + word + "\n";
			}if (Constants::length > i) {
				addToList();
			}
		}
	}
	i--;
}