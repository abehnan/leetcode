/**
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * Constraints:
 * 	1 <= nums.length <= 105
 * 	-104 <= nums[i] <= 104
 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static int maxSubArray(const std::vector<int>& nums)
	{
		auto currentSum = nums[0];
		auto maxSum = nums[0];

		for (auto i = 1u; i < nums.size(); ++i) {
			currentSum = max(nums[i], currentSum + nums[i]);
			maxSum = max(maxSum, currentSum);
		}

		return maxSum;
	}
};

int main()
{
	auto expected = 1;
	auto input = vector<int> { 1 };
	auto actual = Solution::maxSubArray(input);
	assert(actual == expected);

	expected = 6;
	input = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	actual = Solution::maxSubArray(input);
	assert(actual == expected);

	expected = 23;
	input = { 5, 4, -1, 7, 8 };
	actual = Solution::maxSubArray(input);
	assert(actual == expected);

	expected = 1;
	input = { -2, 1 };
	actual = Solution::maxSubArray(input);
	assert(actual == expected);

	expected = -1;
	input = { -2, -3, -1 };
	actual = Solution::maxSubArray(input);
	assert(actual == expected);

	expected = 3;
	input = { 1, 2 };
	actual = Solution::maxSubArray(input);
	assert(actual == expected);

	expected = 3;
	input = { 1, 2, -1 };
	actual = Solution::maxSubArray(input);
	assert(actual == expected);

	return 0;
}
