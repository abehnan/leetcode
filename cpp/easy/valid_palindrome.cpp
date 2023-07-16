/**
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.
 * Alphanumeric characters include letters and numbers.
 * Given a string s, return true if it is a palindrome, or false otherwise.s.
 *
 * Constraints:
 * 	- 1 <= s.length <= 2 * 105
 * 	- s consists only of printable ASCII characters.
 */

#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
	static bool isPalindrome(const string& s)
	{
		auto newString = string {};

		for (const char& c : s) {
			if (isalnum(c)) {
				newString += isupper(c) ? static_cast<char>(tolower(c)) : c;
			}
		}

		if (newString.empty()) {
			return true;
		}

		auto i = 0u;
		auto j = newString.length() - 1;

		while (i < j) {
			if (newString.at(i) != newString.at(j)) {
				return false;
			}

			i++;
			j--;
		}

		return true;
	}
};

int main()
{
	assert(!Solution::isPalindrome("palindrome"));
	assert(!Solution::isPalindrome("race a car"));
	assert(Solution::isPalindrome("A man, a plan, a canal: Panama"));
	assert(Solution::isPalindrome(" "));
	return 0;
}
