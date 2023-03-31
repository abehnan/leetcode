/**
 * You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store.
 * Notice that you may not slant the container.
 *
 * Constraints:
 *	n == height.length
 *	2 <= n <= 105
 *	0 <= height[i] <= 104
 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// Brute Force, O(n^2)
	static int maxAreaBruteForce(const vector<int>& height)
	{
		auto n = static_cast<int>(height.size());
		auto result = 0;

		for (auto l = 0; l < n; ++l) {
			for (auto r = n - 1; r > l; --r) {
				auto area = min(height[l], height[r]) * (r - l);
				result = max(result, area);
			}
		}

		return result;
	}

	// Solution turns into O(n) if you use a sliding window instead.
	static int maxArea(const vector<int>& height)
	{
		auto n = static_cast<int>(height.size());
		auto l = 0;
		auto r = n - 1;
		auto maxArea = 0;

		while (l < r) {
			auto area = min(height[l], height[r]) * (r - l);
			maxArea = max(maxArea, area);

			if (height[l] < height[r]) {
				l++;
			} else {
				r--;
			}
		}

		return maxArea;
	}
};

int main()
{
	vector<int> input;
	int output, expected;

	input = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	output = Solution::maxAreaBruteForce(input);
	expected = 49;
	assert(output == expected);

	input = { 1, 1 };
	output = Solution::maxAreaBruteForce(input);
	expected = 1;
	assert(output == expected);

	input = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	output = Solution::maxArea(input);
	expected = 49;
	assert(output == expected);

	input = { 1, 1 };
	output = Solution::maxArea(input);
	expected = 1;
	assert(output == expected);
}
