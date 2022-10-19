#include "DynamicBitset.h"

DynamicBitset::DynamicBitset(int num)
{
	bits = std::vector<bool>(static_cast<std::size_t>(std::trunc(smartLog(2, std::abs(num))) + 2));

	for (auto it = bits.rbegin(); it.base() > bits.begin(); ++it) {
		// Set the rightmost bit in the binary vector to the rightmost bit of the number
		*it = num & 1;
		// Bitwise shift the number to the right by 1 to get the next bit in the sequence as the new rightmost bit
		num = num >> 1;
	}
}

void DynamicBitset::print() const
{
	for (const auto& bit : bits) {
		std::cout << bit;
	}
}

const double DynamicBitset::smartLog(const int& base, const int& value) const
{
	return log10(value) / log10(base);
}
