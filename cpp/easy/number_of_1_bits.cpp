/**
 * Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
 * Constraints:
 * 		The input must be a binary string of length 32.
 */

#include <bitset>
#include <cassert>

using namespace std;

class Solution {
public:
	// O(1)
	// Note: could have also just done n & 1, then shifted right to count
	static int hammingWeight(uint32_t n)
	{
		auto bits = bitset<32>(n);
		auto count = 0;

		for (auto i = 0; i < 32; i++) {
			if (bits.test(i)) {
				count++;
			}
		}

		return count;
	}
};

int main()
{
	auto expected = 31;
	auto actual = Solution::hammingWeight(-3);
	assert(actual == expected);

	expected = 2;
	actual = Solution::hammingWeight(5);
	assert(actual == expected);

	return 0;
}
