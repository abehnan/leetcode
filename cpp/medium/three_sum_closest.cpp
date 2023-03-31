/**
 * Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static int threeSumClosest(vector<int>& /*nums*/, int /*target*/)
	{
		return 0;
	}
};

int main()
{
	vector<int> nums;
	int target = 0;
	assert(Solution::threeSumClosest(nums, target) == 0);
	return 0;
}
