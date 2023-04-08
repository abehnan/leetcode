/**
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * Constraints:
 * 		1 <= numRows <= 30
 */

#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	// O(numRows^2)
	static vector<vector<int>> generate(int numRows)
	{
		auto pascalsTriangle = vector<vector<int>> {};

		for (auto i = 0; i < numRows; i++) {
			pascalsTriangle.emplace_back(i + 1, 1);
		}

		for (auto i = 2; i < numRows; i++) {
			for (auto j = 1u; j < pascalsTriangle[i].size() - 1; j++) {
				pascalsTriangle[i][j] = pascalsTriangle[i - 1][j - 1] + pascalsTriangle[i - 1][j];
			}
		}

		return pascalsTriangle;
	}
};

int main()
{
	auto expected = vector<vector<int>> { { 1 } };
	auto actual = Solution::generate(1);
	assert(actual == expected);

	expected = { { 1 }, { 1, 1 } };
	actual = Solution::generate(2);
	assert(actual == expected);

	expected = { { 1 }, { 1, 1 }, { 1, 2, 1 } };
	actual = Solution::generate(3);
	assert(actual == expected);

	expected = { { 1 }, { 1, 1 }, { 1, 2, 1 }, { 1, 3, 3, 1 } };
	actual = Solution::generate(4);
	assert(actual == expected);

	return 0;
}
