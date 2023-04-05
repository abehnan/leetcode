/**
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
 * Constraints:
 * 		n == nums.length
 * 		1 <= n <= 104
 * 		0 <= nums[i] <= n
 * 		All the numbers of nums are unique.
 *
 * Follow-up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// O(n log n)
	static int missingNumber(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());

		for (auto i = 0; i < static_cast<int>(nums.size()); i++) {
			if (nums[i] != i) {
				return i;
			}
		}

		return static_cast<int>(nums.size());
	}

	// O(n)
	static int missingNumberFollowUp(const vector<int>& nums)
	{
		auto n = static_cast<int>(nums.size());
		auto sum = (n * (n + 1)) / 2; // going to have to remember high school level math for this one

		for (const auto num : nums) {
			sum -= num;
		}

		return sum;
	}
};

int main()
{
	auto expected = 2;
	auto input = std::vector<int> { 3, 0, 1 };
	auto actual = Solution::missingNumber(input);
	assert(actual == expected);

	expected = 2;
	input = { 0, 1 };
	actual = Solution::missingNumber(input);
	assert(actual == expected);

	expected = 8;
	input = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	actual = Solution::missingNumber(input);
	assert(actual == expected);

	expected = 0;
	input = { 1 };
	actual = Solution::missingNumber(input);
	assert(actual == expected);

	expected = 2;
	input = { 3, 0, 1 };
	actual = Solution::missingNumberFollowUp(input);
	assert(actual == expected);

	expected = 2;
	input = { 0, 1 };
	actual = Solution::missingNumberFollowUp(input);
	assert(actual == expected);

	expected = 8;
	input = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	actual = Solution::missingNumberFollowUp(input);
	assert(actual == expected);

	expected = 0;
	input = { 1 };
	actual = Solution::missingNumberFollowUp(input);
	assert(actual == expected);

	return 0;
}
