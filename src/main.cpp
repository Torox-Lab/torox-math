#include <iostream>
#include <string>
#include <vector>

#include "numbertheory.hpp"
#include "binary.hpp"

using namespace std;
using namespace tmath::cryptography;
using namespace tmath::Binary;

void display(const vector<vector<int>>& divisor_list, const int& result)
{
	cout << "Divisors: ";

	for (unsigned int i = 0; i < divisor_list.size(); i++)
	{
		for (unsigned int j = 0; j < divisor_list[i].size(); j++)
		{
			cout << divisor_list[i][j];
			if (!i == (divisor_list.size() - 1))
				cout << " * ";
		}
	}
	cout << " = " << result << "\n";
}

int main()
{

	cout << "============" << " Number Theory " << "============\n";
	//const auto number_theory = new NumberTheory(48, 72);
	const auto number_theory = new NumberTheory(48, 0);

	// check if the number is prime

	if (!number_theory->are_bothNumbers_prime())
	{
		// get the great common divisor
		const GCD_RESULT gcd_result = number_theory->great_common_Divisor();

		// display the result
		display(gcd_result.divisor_list, gcd_result.great_common_divisor);

		if (gcd_result.great_common_divisor == 1)
		{
			cout << "the numbers: " << number_theory->get_number1() << " and " << number_theory->get_number2() << " are coprime\n";

			const LEMMA3_RESULT lemma3Result = number_theory->lemma3();
			// const LEMMA4_RESULT lemma4Result = number_theory->lemma4();

			cout << "Lemma 3: Bezout Coefficients are: x = " << lemma3Result.x << " and y = " << lemma3Result.y << "\n";
			cout << "Lemma 3: Bezout Identifier is: " << number_theory->get_number1() << " * " << lemma3Result.x << " + " << number_theory->get_number2() << " * " << lemma3Result.y << " = " << lemma3Result.gcd << "\n";
			// cout << "Lemma 4: The value of N number is: " << lemma4Result.coprime << "\n";
		}
		else
		{
			cout << "the numbers: " << number_theory->get_number1() << " and " << number_theory->get_number2() << " are not coprime\n";
		}

		// cout << "Lemma 5: The result of GCD is: " << (number_theory->lemma5() ? "true" : "false") << "\n";

	}
	else
	{
		cout << "Hello Mother!\n";
		cout << "The number: " << number_theory->get_number1() << " or " << number_theory->get_number2() << " is a prime\n";
	}

	//numberTheory->lemma1();
	number_theory->totient(216);

	// Binary Manupulation
	const auto binary = new Binary();
	
	unsigned int num = 0;
	cout << "Bitwise NOT of number 3 in BITS_4 (unsigned): " <<  binary->convert_bitwise_not(num, Bits::BITS_4) <<   "\n";
	cout << "Bitwise NOT of number 3 in BITS_8 (unsigned): " <<  binary->convert_bitwise_not(num,  Bits::BITS_8) <<  "\n";
	cout << "Bitwise NOT of number 3 in BITS_16 (unsigned): " << binary->convert_bitwise_not(num, Bits::BITS_16) << "\n";
	cout << "Bitwise NOT of number 3 in BITS_32 (unsigned): " << binary->convert_bitwise_not(num, Bits::BITS_32) << "\n";

	cout << "Binary: " << binary->convert_bitwise_not(14, Bits::BITS_8) << "\n";

	delete number_theory;
	delete binary;

	return 0;
}
