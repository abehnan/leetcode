/**
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 * Constraints:
 * 		0 <= s.length <= 100
 * 		0 <= t.length <= 104
 * 		s and t consist only of lowercase English letters.
 */

#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
	static bool isSubsequence(const string& s, const string& t)
	{
		auto pos = 0ULL;

		for (const auto& c : s) {
			auto newPos = t.find(c, pos);

			if (newPos == string::npos) {
				return false;
			}

			pos = newPos + 1;
		}

		return true;
	}
};

int main()
{
	auto s = string { "abc" };
	auto t = string { "ahbgdc" };
	auto actual = Solution::isSubsequence(s, t);
	assert(actual);

	s = "axc";
	t = "ahbgdc";
	actual = Solution::isSubsequence(s, t);
	assert(!actual);

	s = "aaaaaa";
	t = "bbaaaa";
	actual = Solution::isSubsequence(s, t);
	assert(!actual);

	return 0;
}
