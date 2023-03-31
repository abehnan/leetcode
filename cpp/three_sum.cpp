/**
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Notice that the solution set must not contain duplicate triplets.
 *
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// Brute force O(n^3), no extra space
	static vector<vector<int>> threeSumBruteForce(const vector<int>& nums)
	{
		vector<vector<int>> results;

		for (const auto& i : nums) {
			for (const auto& j : nums) {
				for (const auto& k : nums) {
					if (i != j && i != k && j != k && i + j + k == 0) {
						results.emplace_back(vector<int> { i, j, k });
					}
				}
			}
		}

		return results;
	}
};

int main()
{
	assert(Solution::threeSumBruteForce({ 0, 1, 1 }).empty());
	vector<vector<int>> expected = { { -1, -1, 2 }, { -1, 0, 1 } };
	assert(Solution::threeSumBruteForce({ -1, 0, 1, 2, -1, -4 }) == expected);
	return 0;
}
