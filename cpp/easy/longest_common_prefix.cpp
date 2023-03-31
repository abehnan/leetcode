/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 */

#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
	// O(n log n)
	static std::string longestCommonPrefix(std::vector<std::string>& strings)
	{
		if (strings.empty()) {
			return {};
		}

		if (strings.size() == 1) {
			return strings[0];
		}

		sort(strings.begin(), strings.end());

		std::string result;
		std::string first = strings.front();
		std::string last = strings.back();
		auto index = 0u;

		while (index < first.size() && index < last.size() && first[index] == last[index]) {
			result.push_back(first[index++]);
		}

		return result;
	}
};

int main()
{
	std::vector<std::string> test = { "blah", "bloh", "blih" };
	assert(Solution::longestCommonPrefix(test) == "bl");

	test = { "blah", "bloh", "apple" };
	assert(Solution::longestCommonPrefix(test).empty());

	test = { "flower", "flow", "flight" };
	assert(Solution::longestCommonPrefix(test) == "fl");

	test = { "dog", "racecar", "car" };
	assert(Solution::longestCommonPrefix(test).empty());

	return 0;
}
