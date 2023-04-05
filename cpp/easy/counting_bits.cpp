/**
 * Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
 * Constraints:
 * 		The input must be a binary string of length 32.
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static vector<int> countBits(int /*n*/)
	{
		return {};
	}
};

int main()
{
	auto expected = std::vector<int> { 0, 1, 1 };
	auto actual = Solution::countBits(2);
	assert(actual == expected);

	return 0;
}
