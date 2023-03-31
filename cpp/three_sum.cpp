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
	// O(n^3)
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

	// The time complexity of this function is O(n^2), where n is the size of the input vector nums.
	// The outer for loop will iterate n-2 times, and the inner while loop will run a maximum of n times for each iteration of the outer loop.
	// Resulting in a total worst-case time complexity of O(n^2).
	static vector<vector<int>> threeSum(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		auto n = nums.size();

		for (auto i = 0u; i < n - 2; i++) {
			if (i != 0u && nums[i] == nums[i - 1]) {
				continue; // skip duplicates
			}

			auto l = i + 1;
			auto r = n - 1;
			auto sum = -nums[i];

			while (l < r) {
				if (nums[l] + nums[r] < sum) {
					l++;
					continue;
				} else if (nums[l] + nums[r] > sum) {
					r--;
					continue;
				}

				res.push_back({ nums[i], nums[l], nums[r] });

				while (l < r && nums[l] == nums[l + 1]) {
					l++; // skip duplicates
				}

				while (l < r && nums[r] == nums[r - 1]) {
					r--; // skip duplicates
				}

				l++;
				r--;
			}
		}

		return res;
	}
};

int main()
{
	vector<vector<int>> expected;
	vector<vector<int>> result;
	vector<int> input;

	input = { 0, 1, 1 };
	result = Solution::threeSumBruteForce(input);
	assert(result.empty());
	input = { -1, 0, 1, 2, -1, -4 };
	expected = { { -1, -1, 2 }, { -1, 0, 1 } };
	result = Solution::threeSumBruteForce(input);
	assert(result == expected);
	input = { 0, 0, 0 };
	expected = { { 0, 0, 0 } };
	result = Solution::threeSumBruteForce(input);
	assert(result == expected);

	input = { 0, 1, 1 };
	result = Solution::threeSum(input);
	assert(result.empty());
	input = { -1, 0, 1, 2, -1, -4 };
	expected = { { -1, -1, 2 }, { -1, 0, 1 } };
	result = Solution::threeSum(input);
	assert(result == expected);
	input = { 0, 0, 0 };
	expected = { { 0, 0, 0 } };
	result = Solution::threeSum(input);
	assert(result == expected);

	return 0;
}
