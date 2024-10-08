#ifndef BINARY_HPP
#define BINARY_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define SOME_UPPER_LIMIT 100000

namespace tmath
{
    namespace Binary
    {
        enum Bits {
			BITS_4 = 0xF,
			BITS_8 = 0xFF,
			BITS_16 = 0xFFFF,
			BITS_32 = 0xFFFFFFFF
		};

        class Binary
        {
        public:
            Binary();
            ~Binary();

            std::string convert_decimal_to_Binary(unsigned int number, Bits bit);
			unsigned int convert_bitwise_not(unsigned int number, Bits bit);
        private:
        };
    }
}

#endif