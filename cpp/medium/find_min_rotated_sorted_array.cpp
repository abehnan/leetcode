/**
 * Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
 *
 * [4,5,6,7,0,1,2] if it was rotated 4 times.
 * [0,1,2,4,5,6,7] if it was rotated 7 times.
 *
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 * Given the sorted rotated array nums of unique elements, return the minimum element of this array.
 *
 * You must write an algorithm that runs in O(log n) time.
 *
 * Constraints:
 * 		n == nums.length
 * 		1 <= n <= 5000
 * 		-5000 <= nums[i] <= 5000
 * 		All the integers of nums are unique.
 * 		nums is sorted and rotated between 1 and n times.
 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// O(log n)
	static int findMin(vector<int>& nums)
	{
		if (nums.size() == 1) {
			return nums[0];
		}

		return findMinInternal(nums, 0, nums.size() - 1);
	}

	static int findMinInternal(vector<int>& nums, unsigned int l, unsigned int r)
	{
		if (l == r) {
			return nums[l];
		}

		if (l + 1 == r) {
			return min(nums[l], nums[r]);
		}

		auto n = l + (r - l) / 2;

		return min(findMinInternal(nums, l, n), findMinInternal(nums, n + 1, r));
	}
};

int main()
{
	auto expected = 0;
	auto input = vector<int> { 0 };
	auto actual = Solution::findMin(input);
	assert(actual == expected);

	expected = 1;
	input = { 3, 4, 5, 1, 2 };
	actual = Solution::findMin(input);
	assert(actual == expected);

	expected = 0;
	input = { 4, 5, 6, 7, 0, 1, 2 };
	actual = Solution::findMin(input);
	assert(actual == expected);

	expected = 11;
	input = { 11, 13, 15, 17 };
	actual = Solution::findMin(input);
	assert(actual == expected);

	return 0;
}
