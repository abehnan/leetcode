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

#include <algorithm>
#include <cassert>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
	static vector<vector<int>> threeSumBruteForce(const vector<int>& nums)
	{
		set<vector<int>> temp;

		for (auto i = 0u; i < nums.size(); ++i) {
			for (auto j = 0u; j < nums.size(); ++j) {
				for (auto k = 0u; k < nums.size(); ++k) {
					if (i != j && i != k && j != k && nums[i] + nums[j] + nums[k] == 0) {
						vector<int> newEntry = { nums[i], nums[j], nums[k] };
						sort(newEntry.begin(), newEntry.end());
						temp.emplace(std::move(newEntry));
					}
				}
			}
		}

		if (temp.empty()) {
			return {};
		}

		vector<vector<int>> result;
		result.reserve(temp.size());

		for (const auto& entry : temp) {
			result.emplace_back(entry);
		}

		return result;
	}
};

int main()
{
	vector<vector<int>> expected;
	vector<vector<int>> result;

	result = Solution::threeSumBruteForce({ 0, 1, 1 });
	assert(result.empty());
	expected = { { -1, -1, 2 }, { -1, 0, 1 } };
	result = Solution::threeSumBruteForce({ -1, 0, 1, 2, -1, -4 });
	assert(result == expected);
	expected = { { 0, 0, 0 } };
	result = Solution::threeSumBruteForce({ 0, 0, 0 });
	assert(result == expected);

	return 0;
}
