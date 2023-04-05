/**
 * Given a string s, find the length of the longest substring without repeating characters.
 */

#include <cassert>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	// O(n^2)
	static int lengthOfLongestSubstringBruteForce(const string& str)
	{
		auto visited = unordered_set<char> {};
		auto result = 0;

		for (const char* c = str.c_str(); *c != '\0'; c++) {
			visited.clear();
			visited.emplace(*c);

			for (const char* d = c + 1; *d != '\0'; d++) {
				if (visited.find(*d) != visited.end()) {
					break;
				}

				visited.emplace(*d);
			}

			result = max(result, static_cast<int>(visited.size()));
		}

		return result;
	}

	// Note: Using a sliding window to solve this in O(n)
	static int lengthOfLongestSubstring(const string& str)
	{
		auto seen = unordered_set<char> {};
		auto left = 0, right = 0, n = static_cast<int>(str.size()), ans = 0;

		while (left < n && right < n) {
			if (seen.find(str[right]) == seen.end()) {
				seen.insert(str[right++]);
				ans = max(ans, right - left);
			} else {
				seen.erase(str[left++]);
			}
		}

		return ans;
	}
};

int main()
{
	assert(Solution::lengthOfLongestSubstringBruteForce("abcabcbb") == 3);
	assert(Solution::lengthOfLongestSubstringBruteForce("bbbbb") == 1);
	assert(Solution::lengthOfLongestSubstringBruteForce("pwwkew") == 3);

	assert(Solution::lengthOfLongestSubstring("abcabcbb") == 3);
	assert(Solution::lengthOfLongestSubstring("bbbbb") == 1);
	assert(Solution::lengthOfLongestSubstring("pwwkew") == 3);
	return 0;
}
