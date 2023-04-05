/**
 * Given two integers a and b, return the sum of the two integers without using the operators + and -.
 *
 * Constraints:
 * 		-1000 <= a, b <= 1000
 */

#include <cassert>

using namespace std;

class Solution {
public:
	// O(1)
	static int getSum(int a, int b)
	{
		while (b != 0) {
			unsigned carry = a & b;
			a ^= b;
			b = static_cast<int>(carry << 1);
		}

		return a;
	}
};

int main()
{
	auto expected = 0;
	auto actual = Solution::getSum(0, 0);
	assert(actual == expected);

	expected = 5;
	actual = Solution::getSum(2, 3);
	assert(actual == expected);

	expected = 10;
	actual = Solution::getSum(4, 6);
	assert(actual == expected);

	expected = 4;
	actual = Solution::getSum(-2, 6);
	assert(actual == expected);

	expected = -6;
	actual = Solution::getSum(-2, -4);
	assert(actual == expected);

	expected = 0;
	actual = Solution::getSum(-1, 1);
	assert(actual == expected);

	return 0;
}
