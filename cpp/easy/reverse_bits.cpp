/**
 * Reverse bits of a given 32 bits unsigned integer.
 * Constraints:
 * 		The input must be a binary string of length 32.
 */

#include <bitset>
#include <cassert>
#include <cstdint>

using namespace std;

class Solution {
public:
	static uint32_t reverseBits(uint32_t n)
	{
		auto bits = bitset<32>(n);
		auto result = bitset<32> {};

		for (auto i = 31; i >= 0; i--) {
			result.set(31 - i, bits.test(i));
		}

		return result.to_ulong();
	}
};

int main()
{
	auto expected = 964176192LL;
	auto actual = Solution::reverseBits(43261596);
	assert(actual == expected);

	expected = 3221225471;
	actual = Solution::reverseBits(4294967293);
	assert(actual == expected);

	return 0;
}
