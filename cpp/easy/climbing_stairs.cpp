/**
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?* Constraints:
 * Constraints:
 * 		1 <= n <= 45
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static int climbStairs(int n)
	{
		if (n <= 1) {
			return 1;
		}

		auto dp = vector<int>(n + 1);
		dp[0] = 1;
		dp[1] = 1;

		for (auto i = 2u; i < dp.size(); i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}
};

int main()
{
	auto expected = 2;
	auto actual = Solution::climbStairs(2);
	assert(actual == expected);

	expected = 3;
	actual = Solution::climbStairs(3);
	assert(actual == expected);

	expected = 1;
	actual = Solution::climbStairs(1);
	assert(actual == expected);

	expected = 5;
	actual = Solution::climbStairs(4);
	assert(actual == expected);

	return 0;
}
