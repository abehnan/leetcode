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
		auto l = 0U;
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
		auto n = static_cast<int>(height.size());

		if (n < 3) {
			return 0;
		}

		auto result = 0;
		auto maxLeft = vector(n, 0);
		auto maxRight = vector(n, 0);
		auto minBoundary = vector(n, 0);
		auto currentMax = height[0];

		for (auto i = 1; i < n; i++) {
			currentMax = max(height[i - 1], currentMax);
			maxLeft[i] = currentMax;
		}

		currentMax = height[n - 1];

		for (auto i = n - 2; i >= 0; i--) {
			currentMax = max(height[i + 1], currentMax);
			maxRight[i] = currentMax;
		}

		for (auto i = 0; i < n; i++) {
			minBoundary[i] = min(maxLeft[i], maxRight[i]);
		}

		for (auto i = 0; i < n; i++) {
			result += max(minBoundary[i] - height[i], 0);
		}

		return result;
	}
};

int main()
{
	auto input = vector { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	auto output = Solution::trapOptimized(input);
	auto expected = 6;
	assert(output == expected);

	Solution::trap(input);
	input = vector { 4, 2, 0, 3, 2, 5 };
	output = Solution::trapOptimized(input);
	expected = 9;
	assert(output == expected);

	input = vector { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	output = Solution::trap(input);
	expected = 6;
	assert(output == expected);

	Solution::trap(input);
	input = vector { 4, 2, 0, 3, 2, 5 };
	output = Solution::trap(input);
	expected = 9;
	assert(output == expected);
}
