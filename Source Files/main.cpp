/*
@author Cameron Marotti
@version 1.0.0
@date 10/19/22

Takes an integer input from the user and converts it to binary using the fewest bits possible, assuming the number is signed
Input must be between -9,223,372,036,854,775,808 and 9,223,372,036,854,775,807
*/

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "DynamicBitset.h"

constexpr char ESC_CHAR = 'x'; // ESC_CHAR should always be lowercase and should not equal any digit or a hyphen

int main() {
	while (true) {
		std::cout << "Input the number you want to convert to binary (or type " << ESC_CHAR << " to stop): ";
		std::string in = "";

		// Take input until something other than a blank string is given
		while (in == "")
			std::getline(std::cin, in);

		// Check for x as an input and close the program if it is found
		if (std::tolower(in.at(0)) == ESC_CHAR) {
			break;
		}

		// Test that the input string contains only digits and negative signs
		if (std::regex_search(in, std::regex("[^\\d-]"))) {
			std::cout << "\nYour input must only contain digits!\n\n";
		}
		else {
			// Create a dynamic bitset from the user's input
			DynamicBitset binary(std::stoll(in));

			// Print the binary representation and loop back to the start of the program
			std::cout << "That number in binary is: ";
			binary.print();
			std::cout << "\n\n";
		}
	}
}
