/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * For example, 2 is written as II in Roman numeral, just two ones added together.
 * 12 is written as XII, which is simply X + II.
 * The number 27 is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
 * Instead, the number four is written as IV.
 * Because the one is before the five we subtract it making four.
 * The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 */

#include <cassert>
#include <string>
#include <unordered_map>

class Solution {
public:
	static unsigned int romanToInt(const std::string& str)
	{
		const std::unordered_map<char, int> romanToDecimal = {
			{ 'I', 1 },
			{ 'V', 5 },
			{ 'X', 10 },
			{ 'L', 50 },
			{ 'C', 100 },
			{ 'D', 500 },
			{ 'M', 1000 }
		};

		auto result = 0u;

		for (auto i = 0u; i < str.length(); i++) {
			const bool lessThanNext = i < str.length() - 1 && romanToDecimal.at(str[i]) < romanToDecimal.at(str[i + 1]);

			if (lessThanNext) {
				result -= romanToDecimal.at(str[i]);
			} else {
				result += romanToDecimal.at(str[i]);
			}
		}

		return result;
	}
};

int main()
{
	assert(Solution::romanToInt("III") == 3);
	assert(Solution::romanToInt("LVIII") == 58);
	assert(Solution::romanToInt("MCMXCIV") == 1994);
	return 0;
}
