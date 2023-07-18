/**
 * You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
 * You can perform this operation at most k times.
 * Return the length of the longest substring containing the same letter you can get after performing the above operations.
 * Constraints:
 * 	- 1 <= s.length <= 105
 * 	- s consists of only uppercase English letters.
 * 	- 0 <= k <= s.length
 */

#include <cassert>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	static int characterReplacement(const string& s, int k)
	{
		auto n = static_cast<int>(s.length());
		auto result = 0;
		auto left = 0;
		auto maxFrequency = 0;
		auto frequencies = unordered_map<char, int> {};

		for (auto right = 0; right < n; right++) {
			frequencies[s[right]]++;
			maxFrequency = max(maxFrequency, frequencies[s[right]]);

			// window is valid if len-maxFrequency <= k,
			// if invalid, move left pointer once, and recheck
			while (right - left + 1 - maxFrequency > k) {
				frequencies[s[left]]--;
				left++;
			}

			result = max(result, right - left + 1);
		}

		return result;
	}
};

int main()
{
	auto expected = 4;
	auto actual = Solution::characterReplacement("ABAB", 2);
	assert(actual == expected);

	expected = 4;
	actual = Solution::characterReplacement("AABABBA", 1);
	assert(actual == expected);

	expected = 2;
	actual = Solution::characterReplacement("ABAA", 0);
	assert(actual == expected);

	expected = 7;
	actual = Solution::characterReplacement("KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF", 4);
	assert(actual == expected);

	return 0;
}
