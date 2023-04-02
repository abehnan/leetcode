/**
 * Given an integer array nums, find a subarray that has the largest product, and return the product.
 * The test cases are generated so that the answer will fit in a 32-bit integer.
 * Constraints:
 * 	1 <= nums.length <= 2 * 104
 * 	-10 <= nums[i] <= 10
 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// O(n)
	static int maxProduct(const std::vector<int>& nums)
	{
		auto n = static_cast<int>(nums.size());
		auto currentMax = nums[0];
		auto currentMin = nums[0];
		auto result = currentMax;

		for (int i = 1; i < n; i++) {
			auto current = nums[i];
			auto tempMax = max(current, max(currentMax * current, currentMin * current));
			currentMin = min(current, min(currentMax * current, currentMin * current));
			currentMax = tempMax;
			result = max(result, currentMax);
		}

		return result;
	}
};

int main()
{
	auto expected = 6;
	auto input = vector<int> { 2, 3, -2, 4 };
	auto actual = Solution::maxProduct(input);
	assert(actual == expected);

	expected = 0;
	input = { -2, 0, -1 };
	actual = Solution::maxProduct(input);
	assert(actual == expected);

	expected = 24;
	input = { -2, 3, -4 };
	actual = Solution::maxProduct(input);
	assert(actual == expected);

	return 0;
}
