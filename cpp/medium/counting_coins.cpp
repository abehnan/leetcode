/**
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
 * Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 * You may assume that you have an infinite number of each kind of coin.
 * Constraints:
 * 		1 <= coins.length <= 12
 * 		1 <= coins[i] <= 231 - 1
 * 		0 <= amount <= 104
 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// O(coins.size() * amount)
	static int coinChange(const vector<int>& coins, int amount)
	{
		// dp[i] represents the minimum amount of coins required to each amount i
		auto dp = vector<int>(amount + 1, amount + 1);
		dp[0] = 0;

		for (const auto& coin : coins) {
			for (auto j = coin; j <= amount; j++) {
				/**
				 * We already know how many coins it takes to to get to "j - coin" at this point.
				 * Therefore, adding 1 of the current coin would net us the amount of coins required to get to "j".
				 */
				dp[j] = min(dp[j], dp[j - coin] + 1);
			}
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}
};

int main()
{
	auto coins = vector<int> { 4 };
	auto amount = 0;
	auto actual = Solution::coinChange(coins, amount);
	auto expected = 0;
	assert(actual == expected);

	coins = { 1, 2, 5 };
	amount = 11;
	actual = Solution::coinChange(coins, amount);
	expected = 3;
	assert(actual == expected);

	coins = { 1, 2, 5 };
	amount = 11;
	actual = Solution::coinChange(coins, amount);
	expected = 3;
	assert(actual == expected);

	coins = { 1, 3, 5 };
	amount = 0;
	actual = Solution::coinChange(coins, amount);
	expected = 0;
	assert(actual == expected);

	coins = { 186, 419, 83, 408 };
	amount = 6249;
	actual = Solution::coinChange(coins, amount);
	expected = 20;
	assert(actual == expected);

	return 0;
}