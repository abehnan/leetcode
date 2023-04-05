/**
 * There is an integer array nums sorted in ascending order (with distinct values).
 *
 * Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 *
 * Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Constraints:
 * 		1 <= nums.length <= 5000
 * 		-104 <= nums[i] <= 104
 * 		All values of nums are unique.
 * 		nums is an ascending array that is possibly rotated.
 * 		-104 <= target <= 104
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// O(log n)
	static int search(const vector<int>& nums, int target)
	{
		auto n = static_cast<int>(nums.size());
		return searchInternal(nums, 0, n - 1, target);
	}

	static int searchInternal(const vector<int>& nums, int l, int r, int target)
	{
		if (l == r) {
			return nums[l] == target ? l : -1;
		}

		if (l + 1 == r) {
			if (nums[l] == target) {
				return l;
			} else if (nums[r] == target) {
				return r;
			} else {
				return -1;
			}
		}

		auto m = l + (r - l) / 2;
		auto result = searchInternal(nums, l, m, target);

		if (result != -1) {
			return result;
		}

		result = searchInternal(nums, m + 1, r, target);
		return result;
	}
};

int main()
{
	auto expected = -1;
	auto nums = vector<int> { 1 };
	auto target = 0;
	auto actual = Solution::search(nums, target);
	assert(actual == expected);

	expected = 4;
	nums = { 4, 5, 6, 7, 0, 1, 2 };
	target = 0;
	actual = Solution::search(nums, target);
	assert(actual == expected);

	expected = -1;
	nums = { 4, 5, 6, 7, 0, 1, 2 };
	target = 3;
	actual = Solution::search(nums, target);
	assert(actual == expected);

	return 0;
}
