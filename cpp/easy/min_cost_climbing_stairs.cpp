/**
 * You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
 * You can either start from the step with index 0, or the step with index 1.
 * Return the minimum cost to reach the top of the floor.
 * Constraints:
 * 		2 <= cost.length <= 1000
 * 		0 <= cost[i] <= 999
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// O(n)
	static int minCostClimbingStairs(const vector<int>& cost)
	{
		auto n = static_cast<int>(cost.size());
		auto dp = vector<int>(n + 1);
		dp[0] = 0;
		dp[1] = 0;
		dp[2] = min(cost[0], cost[1]);

		for (auto i = 3U; i < dp.size(); i++) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}

		return dp[n];
	}
};

int main()
{
	auto cost = vector<int> { 0, 0 };
	auto expected = 0;
	auto actual = Solution::minCostClimbingStairs(cost);
	assert(actual == expected);

	cost = vector<int> { 10, 15, 20 };
	expected = 15;
	actual = Solution::minCostClimbingStairs(cost);
	assert(actual == expected);

	cost = vector<int> { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	expected = 6;
	actual = Solution::minCostClimbingStairs(cost);
	assert(actual == expected);

	return 0;
}