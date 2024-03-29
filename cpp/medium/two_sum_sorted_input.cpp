/**
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
 * Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.
 * Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
 * The tests are generated such that there is exactly one solution. You may not use the same element twice.
 * Your solution must use only constant extra space.
 *
 * Constraints:
 *	- 2 <= numbers.length <= 3 * 104
 *	- -1000 <= numbers[i] <= 1000
 *	- numbers is sorted in non-decreasing order.
 *	- -1000 <= target <= 1000
 *	- The tests are generated such that there is exactly one solution.
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static vector<int> twoSum(const vector<int>& numbers, int target)
	{
		auto i = 0;
		auto j = static_cast<int>(numbers.size() - 1);

		while (i < j) {
			auto val = numbers[i] + numbers[j];

			if (val == target) {
				return { i + 1, j + 1 };
			}

			if (val < target) {
				i++;
			} else {
				j--;
			}
		}

		return {};
	}
};

int main()
{
	auto input = vector { 2, 7, 11, 15 };
	auto expected = vector { 1, 2 };
	assert(Solution::twoSum(input, 9) == expected);

	input = vector { 2, 3, 4 };
	expected = vector { 1, 3 };
	assert(Solution::twoSum(input, 6) == expected);

	input = vector { -1, 0 };
	expected = vector { 1, 2 };
	assert(Solution::twoSum(input, -1) == expected);
	return 0;
}
