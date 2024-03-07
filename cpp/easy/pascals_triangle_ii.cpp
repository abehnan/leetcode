/**
 * Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * Constraints:
 * 		1 <= rowIndex <= 33
 * 	Follow-up:
 * 		 Could you optimize your algorithm to use only O(rowIndex) extra space?
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// O(numRows^2)
	static vector<int> getRow(int rowIndex)
	{
		auto pascalsTriangle = vector<vector<int>> {};

		for (auto i = 0; i <= rowIndex; i++) {
			pascalsTriangle.emplace_back(i + 1, 1);
		}

		for (auto i = 2; i <= rowIndex; i++) {
			for (auto j = 1U; j < pascalsTriangle[i].size() - 1; j++) {
				pascalsTriangle[i][j] = pascalsTriangle[i - 1][j - 1] + pascalsTriangle[i - 1][j];
			}
		}

		return pascalsTriangle.back();
	}

	// O(numRows^2) time, O(numRows) space
	static vector<int> getRowFollowUp(int rowIndex)
	{
		if (rowIndex == 0) {
			return { 1 };
		}

		if (rowIndex == 1) {
			return { 1, 1 };
		}

		auto previous = vector<int> { 1, 1 };
		auto current = vector<int> { 1, 2, 1 };

		for (auto i = 2; i < rowIndex; i++) {
			previous = current;
			current.resize(current.size() + 1, 1);

			for (auto j = 1U; j < current.size() - 1; j++) {
				current[j] = previous[j - 1] + previous[j];
			}
		}

		return current;
	}
};

int main()
{
	auto expected = vector { 1 };
	auto actual = Solution::getRow(0);
	assert(actual == expected);

	expected = { 1, 1 };
	actual = Solution::getRow(1);
	assert(actual == expected);

	expected = { 1, 2, 1 };
	actual = Solution::getRow(2);
	assert(actual == expected);

	expected = { 1, 3, 3, 1 };
	actual = Solution::getRow(3);
	assert(actual == expected);

	expected = { 1 };
	actual = Solution::getRowFollowUp(0);
	assert(actual == expected);

	expected = { 1, 1 };
	actual = Solution::getRowFollowUp(1);
	assert(actual == expected);

	expected = { 1, 2, 1 };
	actual = Solution::getRowFollowUp(2);
	assert(actual == expected);

	expected = { 1, 3, 3, 1 };
	actual = Solution::getRowFollowUp(3);
	assert(actual == expected);

	return 0;
}
