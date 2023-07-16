/**
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 *
 * Constraints:
 * 	- 0 <= nums.length <= 10^5
 * 	- -10^9 <= nums[i] <= 10^9
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static int longestConsecutive(vector<int>& /*nums*/)
	{
		return 0;
	}
};

int main()
{
	auto input = vector<int> {};
	assert(Solution::longestConsecutive(input) == 0);
	return 0;
}
