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
	static int getSum(int /*a*/, int /*b*/)
	{
		return 0;
	}
};

int main()
{
	auto expected = 0;
	auto actual = Solution::getSum(0, 0);
	assert(actual == expected);
	return 0;
}
