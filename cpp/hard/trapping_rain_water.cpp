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
	// O(n) with no extra space.
	static int trapOptimized(const vector<int>& height)
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

	// O(n) time and O(n) space, but easier.
	static int trap(const vector<int>& height)
	{
		auto n = height.size();

		if (n < 3) {
			return 0;
		}

		auto result = 0;
		auto maxLeft = vector<int>(n, 0);
		auto maxRight = vector<int>(n, 0);
		auto minBoundary = vector<int>(n, 0);
		auto currentMax = height[0];

		for (auto i = 1u; i < n; i++) {
			currentMax = max(height[i - 1], currentMax);
			maxLeft[i] = currentMax;
		}

		currentMax = height[n - 1];

		for (auto i = static_cast<int>(n - 2); i >= 0; i--) {
			currentMax = max(height[i + 1], currentMax);
			maxRight[i] = currentMax;
		}

		for (auto i = 0u; i < n; i++) {
			minBoundary[i] = min(maxLeft[i], maxRight[i]);
		}

		for (auto i = 0u; i < n; i++) {
			result += max(minBoundary[i] - height[i], 0);
		}

		return result;
	}
};

int main()
{
	auto input = vector<int> { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	auto output = Solution::trapOptimized(input);
	auto expected = 6;
	assert(output == expected);

	Solution::trap(input);
	input = vector<int> { 4, 2, 0, 3, 2, 5 };
	output = Solution::trapOptimized(input);
	expected = 9;
	assert(output == expected);

	input = vector<int> { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	output = Solution::trap(input);
	expected = 6;
	assert(output == expected);

	Solution::trap(input);
	input = vector<int> { 4, 2, 0, 3, 2, 5 };
	output = Solution::trap(input);
	expected = 9;
	assert(output == expected);
}
