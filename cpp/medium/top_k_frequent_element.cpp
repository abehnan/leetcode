/**
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 * Constraints:
 * - 1 <= nums.length <= 105
 * - -10^4 <= nums[i] <= 10^4
 * - k is in the range [1, the number of unique elements in the array].
 * - It is guaranteed that the answer is unique.
 */

#include <algorithm>
#include <cassert>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	// this will fail if values have equal occurrences, e.g. [1, 2]
	static vector<int> topKFrequentFirstAttempt(const vector<int>& nums, const int k)
	{
		if (nums.empty()) {
			return {};
		}

		auto occurrences = unordered_map<int, int> {};

		for (const auto& n : nums) {
			occurrences[n]++;
		}

		auto results = map<int, int> {};

		for (const auto& [key, val] : occurrences) {
			results[val] = key;
		}

		auto result = vector<int> {};
		int i = 0;

		for (auto it = results.rbegin(); it != results.rend() && i < k; i++, ++it) {
			result.emplace_back(it->second);
		}

		return result;
	}

	static vector<int> topKFrequent(const vector<int>& nums, const int k)
	{
		if (nums.empty()) {
			return {};
		}

		auto occurrences = unordered_map<int, int> {};

		for (const auto& n : nums) {
			occurrences[n]++;
		}

		auto results = vector<pair<int, int>> {};

		for (const auto& [key, val] : occurrences) {
			results.emplace_back(val, key);
		}

		sort(results.begin(), results.end());

		auto result = vector<int> {};
		int i = 0;

		for (auto it = results.rbegin(); it != results.rend() && i < k; i++, it++) {
			result.emplace_back(it->second);
		}

		return result;
	}
};

int main()
{
	auto nums = vector { 1, 1, 1, 2, 2, 3 };
	auto k = 2;
	auto result = Solution::topKFrequentFirstAttempt(nums, k);
	auto expected = vector { 1, 2 };
	assert(result == expected);

	nums = vector { 1, 1, 1, 2, 2, 3 };
	k = 1;
	result = Solution::topKFrequentFirstAttempt(nums, k);
	expected = vector { 1 };
	assert(result == expected);

	nums = vector { 1, 1, 1, 2, 2, 3 };
	k = 3;
	result = Solution::topKFrequentFirstAttempt(nums, k);
	expected = vector { 1, 2, 3 };
	assert(result == expected);

	nums = vector { 1, 1, 1, 2, 2, 3 };
	k = 1;
	result = Solution::topKFrequent(nums, k);
	sort(result.begin(), result.end());
	expected = vector { 1 };
	assert(result == expected);

	nums = vector { 1, 1, 1, 2, 2, 3 };
	k = 2;
	result = Solution::topKFrequent(nums, k);
	sort(result.begin(), result.end());
	expected = vector { 1, 2 };
	assert(result == expected);

	nums = vector { 1, 1, 1, 2, 2, 3 };
	k = 3;
	result = Solution::topKFrequent(nums, k);
	sort(result.begin(), result.end());
	expected = vector { 1, 2, 3 };
	assert(result == expected);

	nums = vector { 1, 2 };
	k = 2;
	result = Solution::topKFrequent(nums, k);
	sort(result.begin(), result.end());
	expected = vector { 1, 2 };
	assert(result == expected);

	return 0;
}
