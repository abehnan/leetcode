/**
 * Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * Constraints:
 * 		3 <= nums.length <= 500
 * 		-1000 <= nums[i] <= 1000
 * 		-104 <= target <= 104
 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// The time complexity of this function is O(n^2), where n is the size of the input vector nums.
	static int threeSumClosest(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());
		auto n = static_cast<int>(nums.size()), result = 0, minDiff = INT_MAX;

		for (auto i = 0; i < n - 2; i++) {
			if (i != 0 && nums[i] == nums[i - 1]) {
				continue; // skip duplicates
			}

			auto l = i + 1, r = n - 1;
			auto remainder = target - nums[i];

			while (l < r) {
				auto sum = nums[i] + nums[l] + nums[r];

				if (sum == target) {
					return sum;
				}

				auto diff = abs(target - sum);

				if (diff < minDiff) {
					minDiff = diff;
					result = sum;
				}

				if (nums[l] + nums[r] < remainder) {
					l++;
				} else if (nums[l] + nums[r] > remainder) {
					r--;
				}
			}
		}

		return result;
	}
};

int main()
{
	auto nums = vector<int> { -1, 2, 1, -4 };
	auto target = 1;
	auto expected = 2;
	auto result = Solution::threeSumClosest(nums, target);
	assert(result == expected);

	nums = { 0, 0, 0 };
	target = 1;
	expected = 0;
	result = Solution::threeSumClosest(nums, target);
	assert(result == expected);

	return 0;
}
