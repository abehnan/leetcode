/**
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
 * Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 * You may assume that you have an infinite number of each kind of coin.
 * Constraints:
 * 		1 <= coins.length <= 12
 * 		1 <= coins[i] <= 231 - 1
 * 		0 <= amount <= 104
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static int coinChange(vector<int>& /*coins*/, int /*amount*/)
	{
		return 0;
	}
};

int main()
{
	auto input = vector<int> {};
	assert(Solution::coinChange(input, 0) == 0);
	return 0;
}