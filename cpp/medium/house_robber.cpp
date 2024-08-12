/**
 * You are given an integer array nums where nums[i] represents the amount of money the ith house has.
 * The houses are arranged in a straight line, i.e. the ith house is the neighbor of the (i-1)th and (i+1)th house.
 * You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically alert the police if two adjacent houses were both broken into.
 * Return the maximum amount of money you can rob without alerting the police.
 * Constraints:
 * 	1 <= nums.length <= 100
 * 	0 <= nums[i] <= 100
 */

#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
	static int houseRobber(vector<int>& nums)
	{
		if (nums.size() == 1) {
			return nums[0];
		}

		if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}

		auto dp = vector<int>(nums.size());
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);

		for (auto i = 2; i < nums.size(); ++i) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}

		return dp.back();
	}
};

int main()
{
	auto input = vector<int> { 2, 9, 8, 3, 6 };
	auto expected = 16;
	auto result = Solution::houseRobber(input);
	assert(result == expected);

	input = vector<int> { 5, 1, 2, 10, 6, 2, 7, 9, 3, 1 };
	expected = 27;
	result = Solution::houseRobber(input);
	assert(result == expected);
	return 0;
}