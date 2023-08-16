/**
 * Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 * Constraints:
 * 		0 <= n <= 105
 */

#include <bitset>
#include <cassert>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
	// O(n)
	static vector<int> countBits(uint32_t n)
	{
		auto result = vector<int> {};

		for (uint32_t i = 0; i <= n; i++) {
			result.emplace_back(bitset<32>(i).count());
		}

		return result;
	}
};

int main()
{
	auto expected = std::vector<int> { 0, 1, 1 };
	auto actual = Solution::countBits(2);
	assert(actual == expected);

	expected = { 0, 1, 1, 2, 1, 2 };
	actual = Solution::countBits(5);
	assert(actual == expected);

	return 0;
}
