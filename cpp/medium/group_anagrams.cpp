#pragma clang diagnostic push
#pragma ide diagnostic ignored "performance-inefficient-vector-operation"
/**
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 * Constraints:
 *  - 1 <= strs.length <= 104
 *  - 0 <= strs[i].length <= 100
 *  - strs[i] consists of lowercase English letters.
 */

#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	static vector<vector<string>> groupAnagrams(const vector<string>& strs)
	{
		unordered_map<string, vector<string>> anagrams;

		for (const auto& str : strs) {
			auto key = str;
			sort(key.begin(), key.end());
			anagrams[key].emplace_back(str);
		}

		vector<vector<string>> result;

		for (const auto& [k, v] : anagrams) {
			result.emplace_back(v);
		}

		return result;
	}
};

int main()
{
	auto input = vector<string> { "eat", "tea", "tan", "ate", "nat", "bat" };
	auto expected = vector<vector<string>> { { "bat" }, { "nat", "tan" }, { "ate", "eat", "tea" } };
	auto result = Solution::groupAnagrams(input);
	assert(result == expected);
	return 0;
}

#pragma clang diagnostic pop