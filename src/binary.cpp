#include "binary.hpp"

using namespace::tmath::Binary;


Binary::Binary(){

}

Binary::~Binary(){
	
}

//std::string NumberTheory::convertDecimalToBinary(unsigned int number, Bits bit)
//{
//	std::string binary;
//
//	while (number > 0) {
//		binary = std::to_string(number % 2) + binary;  // Append remainder as binary digit
//		number /= 2;                                   // Divide by 2 for next iteration
//	}
//
//	// Handle zero case separately
//	if (binary.empty()) {
//		binary = "0";
//	}
//
//	return binary;
//}

std::string Binary::convert_decimal_to_Binary(unsigned int number, Bits bit)
{
	std::string strBinary;

	if (number == 0)
		return 0; // Base case: Decimal 0 is binary 0

	unsigned int binaryResult = 0;
	unsigned int powerOfTwo = 1; // Represents 2^0 initially

	while (number > 0) {
		// Extract the rightmost bit of the decimal number
		unsigned int bitValue = number % 2;
		cout << "bit value: " << bitValue << endl;
		strBinary += std::to_string(bitValue);

		// Set the corresponding bit in the binary result
		binaryResult += bitValue * powerOfTwo;
		cout << "binary result: " << binaryResult << endl;

		// Move to the next bit
		powerOfTwo *= 2;
		number /= 2;
	}

	// Apply the bit mask (e.g., BITS_8) if needed
	binaryResult &= bit;

	//strBinary = std::to_string(binaryResult);
	return strBinary;
}

unsigned int Binary::convert_bitwise_not(unsigned int number, Bits bit)
{
	if (number >= 0 && number <= 32)
		return ~number & bit;

	return 0;
}