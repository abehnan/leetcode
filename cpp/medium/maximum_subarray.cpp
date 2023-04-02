/**
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * Constraints:
 * 	1 <= nums.length <= 105
 * 	-104 <= nums[i] <= 104
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static int maxSubArray(vector<int>& /*nums*/)
	{
		return 0;
	}
};

int main()
{
	auto expected = 0;
	auto result = vector<int> {};
	auto input = vector<int> {};
	auto actual = Solution::maxSubArray(input);
	assert(actual == expected);
	return 0;
}
