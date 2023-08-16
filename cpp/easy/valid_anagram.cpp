/**
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 * Constraints:
 *  - 1 <= s.length, t.length <= 5 * 104
 *  - s and t consist of lowercase English letters.
 */

#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
	// O(n log n)
	static int validAnagram(string s, string t)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return static_cast<int>(s == t);
	}
};

int main()
{
	assert(Solution::validAnagram("anagram", "nagaram"));
	assert(!Solution::validAnagram("rat", "car"));
	return 0;
}
