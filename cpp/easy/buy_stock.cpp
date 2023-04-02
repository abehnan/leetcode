/**
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// O(n)
	static int maxProfit(const vector<int>& prices)
	{
		auto result = 0;
		auto min = INT_MAX;

		for (const auto& price : prices) {
			min = std::min(min, price);
			result = std::max(result, price - min);
		}

		return result;
	}
};

int main()
{
	auto input = std::vector<int> {};
	auto expected = 0;
	auto actual = Solution::maxProfit(input);
	assert(actual == expected);

	input = { 7, 1, 5, 3, 6, 4 };
	expected = 5;
	actual = Solution::maxProfit(input);
	assert(actual == expected);

	input = { 3, 2, 6, 5, 0, 3 };
	expected = 4;
	actual = Solution::maxProfit(input);
	assert(actual == expected);

	input = { 4 };
	expected = 0;
	actual = Solution::maxProfit(input);
	assert(actual == expected);

	input = { 1, 2 };
	expected = 1;
	actual = Solution::maxProfit(input);
	assert(actual == expected);

	input = { 1, 2, 4 };
	expected = 3;
	actual = Solution::maxProfit(input);
	assert(actual == expected);

	return 0;
}
