/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 *
 * Constraints:
 * 	- n == height.length
 * 	- 1 <= n <= 2 * 104
 * 	- 0 <= height[i] <= 10
 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static int trap(const vector<int>& height)
	{
		auto l = 0u;
		auto r = height.size() - 1;
		auto maxLeft = height[l];
		auto maxRight = height[r];
		auto result = 0;

		while (l < r) {
			if (maxLeft <= maxRight) {
				l++;
				maxLeft = max(maxLeft, height[l]);
				result += maxLeft - height[l];
			} else {
				r--;
				maxRight = max(maxRight, height[r]);
				result += maxRight - height[r];
			}
		}

		return result;
	}
};

int main()
{
	auto input = vector<int> { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	auto output = Solution::trap(input);
	auto expected = 6;
	assert(output == expected);
	input = vector<int> { 4, 2, 0, 3, 2, 5 };
	output = Solution::trap(input);
	expected = 9;
	assert(output == expected);
}
