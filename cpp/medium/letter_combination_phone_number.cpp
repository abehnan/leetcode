/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
 * A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * 		2 = abc
 * 		3 = def
 * 		4 = ghi
 * 		5 = jkl
 * 		6 = mno
 * 		7 = pqrs
 * 		8 = tuv
 * 		9 = wxyz
 *
 * Constraints:
 * 		0 <= digits.length <= 4
 * 		digits[i] is a digit in the range ['2', '9']
 */

#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	static vector<string> letterCombinations(const string& /*digits*/)
	{
		return {};
	}
};

int main()
{
	assert(Solution::letterCombinations("").empty());
	return 0;
}
