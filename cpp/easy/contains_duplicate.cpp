/**
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 * Constraints:
 * 		1 <= nums.length <= 105
 * 		-109 <= nums[i] <= 109
 */

#include <algorithm>
#include <cassert>
#include <climits>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
	// O(n log n)
	static bool containsDuplicateNoExtraSpace(vector<int>& nums)
	{
		if (nums.size() <= 1) {
			return false;
		}

		sort(nums.begin(), nums.end());
		auto prev = INT_MIN;

		for (const auto& num : nums) {
			if (num == prev) {
				return true;
			}

			prev = num;
		}

		return false;
	}

	// O(n)
	static bool containsDuplicate(const vector<int>& nums)
	{
		auto s = set<int>(nums.begin(), nums.end());
		return s.size() != nums.size();
	}
};

int main()
{
	auto input = std::vector<int> {};
	auto expected = false;
	auto actual = Solution::containsDuplicateNoExtraSpace(input);
	assert(actual == expected);

	input = { 1, 2, 3, 1 };
	expected = true;
	actual = Solution::containsDuplicateNoExtraSpace(input);
	assert(actual == expected);

	input = { 1, 2, 3, 4 };
	expected = false;
	actual = Solution::containsDuplicateNoExtraSpace(input);
	assert(actual == expected);

	input = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
	expected = true;
	actual = Solution::containsDuplicateNoExtraSpace(input);
	assert(actual == expected);

	input = {};
	expected = false;
	actual = Solution::containsDuplicate(input);
	assert(actual == expected);

	input = { 1, 2, 3, 1 };
	expected = true;
	actual = Solution::containsDuplicate(input);
	assert(actual == expected);

	input = { 1, 2, 3, 4 };
	expected = false;
	actual = Solution::containsDuplicate(input);
	assert(actual == expected);

	input = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
	expected = true;
	actual = Solution::containsDuplicate(input);
	assert(actual == expected);

	return 0;
}
