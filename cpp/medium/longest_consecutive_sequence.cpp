/**
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 *
 * Constraints:
 * 	- 0 <= nums.length <= 10^5
 * 	- -10^9 <= nums[i] <= 10^9
 */

#include <cassert>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
	static int longestConsecutive(const vector<int>& nums)
	{
		const auto s = unordered_set(nums.begin(), nums.end());
		auto longest = 0;

		for (const auto& n : s) {
			// return early if this isn't the start of a sequence
			if (s.count(n - 1)) {
				continue;
			}

			auto length = 1;

			while (s.count(n + length) != 0U) {
				length++;
			}

			longest = max(longest, length);
		}

		return longest;
	}
};

int main()
{
	auto input = vector<int> {};
	assert(Solution::longestConsecutive(input) == 0);

	input = { 100, 4, 200, 1, 3, 2 };
	assert(Solution::longestConsecutive(input) == 4);

	input = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
	assert(Solution::longestConsecutive(input) == 9);
	return 0;
}
