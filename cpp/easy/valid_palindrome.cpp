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
	static bool isPalindrome(const string& /*s*/)
	{
		return false;
	}
};

int main()
{
	assert(!Solution::isPalindrome("palindrome"));
	return 0;
}
