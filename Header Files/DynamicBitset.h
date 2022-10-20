#pragma once
#include <iostream>
#include <vector>

class DynamicBitset {
public:
	/*
	Creates a dynamic bitset from the given number
	@param int num - The number
	*/
	DynamicBitset(std::int_fast64_t num);

	/*
	Creates a dynamic bitset from the given number
	@param std::vector<bool> &bits - A vector of booleans to be converted to a dynamic bitset
	*/
	DynamicBitset(std::vector<bool> &bits) {
		this->bits = bits;
	}

	void print() const;

private:
	// Create a vector of booleans to hold the bits in the bitset
	std::vector<bool> bits;

	/*
	Calculates the logarithm with the given base of the given value.
	Preconditions: base and value must be greater than 0
	@param const int& base - The base
	@param const int& value - The value of which to calculate the logarithm
	@return const double - The logarithm of the given value calculated to the given base
	*/
	const double smartLog(const std::int_fast64_t& base, const std::int_fast64_t& value) const;
};
