/**
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * Constraints:
 * 	2 <= nums.length <= 105
 * 	-30 <= nums[i] <= 30
 * 	The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static vector<int> productExceptSelf(vector<int>& /*nums*/)
	{
		return {};
	}
};
int main()
{
	auto expected = vector<int> {};
	auto result = vector<int> {};
	auto input = vector<int> {};
	auto actual = Solution::productExceptSelf(input);
	assert(actual == expected);

	return 0;
}
