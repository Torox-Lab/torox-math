#ifndef NUMBERTHEORY_HPP
#define NUMBERTHEORY_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define SOME_UPPER_LIMIT 100000

namespace tmath
{
	namespace cryptography
	{
		struct GCD_RESULT
		{
			int great_common_divisor;
			vector<vector<int>> divisor_list = {};
			bool special_case = false;
			int special_case_number = 0;
		};

		struct LEMMA3_RESULT
		{
			int x;
			int y;
			int gcd;
		};

		struct LEMMA4_RESULT
		{
			bool is_coprime;
			int coprime;
		};

		class NumberTheory
		{
		public:
			NumberTheory(int number1, int number2);

			~NumberTheory();

			void set_number1(int number_1);
			int get_number1() const;
			void set_number2(int number_2);
			int get_number2() const;

			bool is_prime(int number) const;

			bool are_bothNumbers_prime() const;

			bool is_divisible() const;
			bool is_divisible(const int &number1, const int &number2) const;

			/**
			 * @brief Calculate the divisors of a given number and return a list of lists containing the divisors.
			 * 
			 * @param number the number for which to find the divisors
			 * @return a list of lists containing the divisors
			 */
			vector<vector<int>> divisor_list(int number);

			void divisor_calculate(int a, int b);

			/**
			 * @brief Calculate the product of all the divisors in the given list of divisors.
			 * 
			 * @param divisor_list A list of divisors, where each element is a list of integers representing divisors.
			 * @return The product of all the divisors in the list.
			 */
			int gcd_calcule(vector<vector<int>> divisor_list);

			/**
			 * @brief compare the 2 lists and return the final list
			 *
			 * @param divisor_list_1 list of dividers of the first number
			 * @param divisor_list_2 list of dividers of the second number 
			 * @param divisor_list_3 return the final list
			 */
			void compar_lists(const vector<vector<int>>& divisor_list_1, const vector<vector<int>>& divisor_list_2,
			                  vector<vector<int>>& divisor_list_3) const;

			/**
			 * @brief Calculate the greatest common divisor (GCD) of two numbers.
			 *
			 * This function calculates the GCD of two numbers by finding the common divisors of the two numbers
			 * and then computing the product of those common divisors.
			 *
			 * @param gcd_result The struct containing the GCD and the list of divisors.
			 */
			GCD_RESULT great_common_Divisor();

			/**
			 * @brief Calculates the greatest common divisor of two numbers and provides a list of divisors.
			 *
			 * @param number_1 The first number for which to find divisors and calculate GCD.
			 * @param number_2 The second number for which to find divisors and calculate GCD.
			 * @param gcd_result Struct containing the result of GCD calculation and the list of divisors.
			 */
			void great_common_divisor(int& number_1, int& number_2, GCD_RESULT& gcd_result);
			int great_common_divisor(int& number_1, int& number_2);

			/**
			 * @brief Check if the numbers satisfy lemma 1.
			 *
			 * This function checks if the numbers are integers and satisfy the closure properties under addition, subtraction, and multiplication.
			 *
			 * @return true if the numbers satisfy the closure properties, false otherwise
			 */
			bool lemma1();

			LEMMA3_RESULT lemma3();

			/**
			 * @brief Implementing Lemma 4 of number theory.
			 *
			 * This function finds the smallest positive integer i such that i is coprime to both m_number1 and m_number2.
			 *
			 * @return LEMMA4_RESULT A struct containing a boolean indicating if a solution was found and the value of i.
			 */
			LEMMA4_RESULT lemma4();

			void totient(int number);

			bool lemma5();

			

		private:
			int m_number1;
			int m_number2;
			vector<map<string, int>> m_divisor_list;
			GCD_RESULT* m_gcd_result;
		};
	}

};

#endif // NUMBERTHEORY_HPP