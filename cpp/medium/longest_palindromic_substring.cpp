/**
 * Given a string s, return the longest palindromic substring in s.
 */

#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	// dynamic programming approach, O(n^2)
	static string longestPalindrome(const string& str)
	{
		auto n = str.length();
		auto maxLength = 1U;
		auto start = 0U;

		// results[i][j] is true if str[i..j] is a palindrome
		auto results = vector<vector<bool>>(n, vector<bool>(n, false));

		// All substrings of length 1 are palindromes
		for (auto i = 0U; i < n; i++) {
			results[i][i] = true;
		}

		// Check substrings of length 2
		for (auto i = 0U; i < n - 1; i++) {
			if (str[i] == str[i + 1]) {
				results[i][i + 1] = true;
				maxLength = 2;
				start = i;
			}
		}

		// Check substrings of length > 2
		for (auto len = 3U; len <= n; len++) {
			for (auto i = 0U; i <= n - len; i++) {
				auto j = i + len - 1;

				if (str[i] == str[j] && results[i + 1][j - 1]) {
					results[i][j] = true;

					if (len > maxLength) {
						maxLength = len;
						start = i;
					}
				}
			}
		}

		return str.substr(start, maxLength);
	}

	// O(n^3)
	static string longestPalindromeBruteForce(const string& str)
	{
		auto n = str.length();
		auto maxLength = 1U;
		auto start = 0U;

		// Check all possible substrings
		for (auto i = 0U; i < n; i++) {
			for (auto j = i; j < n; j++) {
				auto len = j - i + 1;

				if (len > maxLength && isPalindrome(str, i, j)) {
					maxLength = len;
					start = i;
				}
			}
		}

		return str.substr(start, maxLength);
	}

	static bool isPalindrome(const string& str, unsigned int left, unsigned int right)
	{
		while (left < right) {
			if (str[left] != str[right]) {
				return false;
			}

			left++;
			right--;
		}

		return true;
	}
};

int main()
{
	assert(Solution::longestPalindromeBruteForce("babad") == "bab");
	assert(Solution::longestPalindromeBruteForce("cbbd") == "bb");
	assert(Solution::longestPalindrome("babad") == "bab");
	assert(Solution::longestPalindrome("cbbd") == "bb");
	return 0;
}
