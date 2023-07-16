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
	static int trap(vector<int>& /*height*/)
	{
		return 0;
	}
};

int main()
{
	auto input = vector<int> { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	auto output = Solution::trap(input);
	auto expected = 6;
	assert(output == expected);
}
