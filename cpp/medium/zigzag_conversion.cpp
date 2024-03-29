/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string s, int numRows);
 */

#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	// brute force solution - O(stringLength * numRows)
	static string convertBruteForce(const string& str, int numRows)
	{
		if (numRows <= 1 || str.empty()) {
			return str;
		}

		auto result = string {};
		auto newRow = vector<int> {};
		newRow.reserve(str.length());
		auto count = 1;
		auto increasing = true;
		newRow.emplace_back(0);

		for (auto i = 1U; i < str.length(); i++) {
			if (count < numRows - 1 && increasing) {
				newRow.emplace_back(count++);
			} else if (count >= numRows - 1 && increasing) {
				increasing = false;
				newRow.emplace_back(count--);
			} else if (!increasing && count > 0) {
				newRow.emplace_back(count--);
			} else if (!increasing) {
				increasing = true;
				newRow.emplace_back(count++);
			}
		}

		for (auto j = 0; j < numRows; j++) {
			for (auto i = 0U; i < newRow.size(); i++) {
				if (newRow[i] == j) {
					result += str[i];
				}
			}
		}

		return result;
	}

	// O(stringLength) with the trade-off of higher space complexity
	static string convert(const string& str, int numRows)
	{
		if (numRows == 1) {
			return str;
		}

		auto rows = vector<string>(numRows);
		auto currRow = 0;
		auto isGoingDown = false;
		auto result = string {};

		for (const auto& c : str) {
			rows[currRow] += c;

			if (currRow == 0 || currRow == numRows - 1) {
				isGoingDown = !isGoingDown;
			}

			currRow += isGoingDown ? 1 : -1;
		}

		for (const auto& row : rows) {
			result += row;
		}

		return result;
	}
};

int main()
{
	constexpr int MAX_INDEX_FOR_NULL_TESTS = 10;

	for (auto i = 0; i < MAX_INDEX_FOR_NULL_TESTS; i++) {
		assert(Solution::convertBruteForce("", i).empty());
	}

	assert(Solution::convertBruteForce("TEMPA", 1) == "TEMPA");
	assert(Solution::convertBruteForce("ZOOMIE", 1) == "ZOOMIE");
	assert(Solution::convertBruteForce("fOo", 1) == "fOo");
	assert(Solution::convertBruteForce("TEMP", 2) == "TMEP");
	assert(Solution::convertBruteForce("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
	assert(Solution::convertBruteForce("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");

	for (auto i = 0; i < MAX_INDEX_FOR_NULL_TESTS; i++) {
		assert(Solution::convert("", i).empty());
	}

	assert(Solution::convert("TEMPA", 1) == "TEMPA");
	assert(Solution::convert("ZOOMIE", 1) == "ZOOMIE");
	assert(Solution::convert("fOo", 1) == "fOo");
	assert(Solution::convert("TEMP", 2) == "TMEP");
	assert(Solution::convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
	assert(Solution::convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");

	return 0;
}
