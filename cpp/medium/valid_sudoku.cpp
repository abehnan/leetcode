/**
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 *
 * Note:
 * 	A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * 	Only the filled cells need to be validated according to the mentioned rules.
 *
 * Constraints:
 * 	- board.length == 9
 * 	- board[i].length == 9
 * 	- board[i][j] is a digit 1-9 or '.'.
 */

#include <cassert>
#include <unordered_set>
#include <vector>

using namespace std;

namespace {
	const vector<vector<pair<unsigned int, unsigned int>>> sections = {
		{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 }, { 2, 2 } },
		{ { 0, 3 }, { 0, 4 }, { 0, 5 }, { 1, 3 }, { 1, 4 }, { 1, 5 }, { 2, 3 }, { 2, 4 }, { 2, 5 } },
		{ { 0, 6 }, { 0, 7 }, { 0, 8 }, { 1, 6 }, { 1, 7 }, { 1, 8 }, { 2, 6 }, { 2, 7 }, { 2, 8 } },
		{ { 3, 0 }, { 3, 1 }, { 3, 2 }, { 4, 0 }, { 4, 1 }, { 4, 2 }, { 5, 0 }, { 5, 1 }, { 5, 2 } },
		{ { 3, 3 }, { 3, 4 }, { 3, 5 }, { 4, 3 }, { 4, 4 }, { 4, 5 }, { 5, 3 }, { 5, 4 }, { 5, 5 } },
		{ { 3, 6 }, { 3, 7 }, { 3, 8 }, { 4, 6 }, { 4, 7 }, { 4, 8 }, { 5, 6 }, { 5, 7 }, { 5, 8 } },
		{ { 6, 0 }, { 6, 1 }, { 6, 2 }, { 7, 0 }, { 7, 1 }, { 7, 2 }, { 8, 0 }, { 8, 1 }, { 8, 2 } },
		{ { 6, 3 }, { 6, 4 }, { 6, 5 }, { 7, 3 }, { 7, 4 }, { 7, 5 }, { 8, 3 }, { 8, 4 }, { 8, 5 } },
		{ { 6, 6 }, { 6, 7 }, { 6, 8 }, { 7, 6 }, { 7, 7 }, { 7, 8 }, { 8, 6 }, { 8, 7 }, { 8, 8 } },
	};
}

class Solution {
public:
	static bool checkRowAndColumn(const vector<vector<char>>& board, unsigned int row, unsigned int column)
	{
		auto& val = board[row][column];

		if (val == '.') {
			return true;
		}

		for (auto x = 0u; x < 9u; x++) {
			if (x != row && board[x][column] == val) {
				return false;
			}

			if (x != column && board[row][x] == val) {
				return false;
			}
		}

		return true;
	}

	static bool checkSections(const vector<vector<char>>& board)
	{
		for (const auto& section : sections) {
			auto nums = unordered_set<char> { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

			for (const auto& location : section) {
				auto& val = board[location.first][location.second];

				if (val == '.') {
					continue;
				}

				if (!nums.count(val)) {
					return false;
				}

				nums.erase(val);
			}
		}

		return true;
	}

	static bool isValidSudoku(const vector<vector<char>>& board)
	{
		for (auto i = 0u; i < 9u; i++) {
			for (auto j = 0u; j < 9u; j++) {
				if (!checkRowAndColumn(board, i, j)) {
					return false;
				}
			}
		}

		return checkSections(board);
	}

	static bool check(const vector<vector<char>>& board, unsigned int i, unsigned int j, char val)
	{
		if (val == '.') {
			return true;
		}

		for (auto x = 0u; x < 9u; x++) {
			if (x != i && board[x][j] == val) {
				return false;
			}

			if (x != j && board[i][x] == val) {
				return false;
			}
		}

		auto a = i / 3;
		auto b = j / 3;
		a = a * 3;
		b = b * 3;

		for (auto n = a; n < a + 3; n++) {
			for (auto m = b; m < b + 3; m++) {
				if (n != i || m != j) {
					if (board[n][m] == val) {
						return false;
					}
				}
			}
		}

		return true;
	}

	static bool isValidSudokuOptimized(const vector<vector<char>>& board)
	{
		for (auto i = 0u; i < 9u; i++) {
			for (auto j = 0u; j < 9u; j++) {
				if (!check(board, i, j, board[i][j])) {
					return false;
				}
			}
		}

		return true;
	}
};

int main()
{
	auto input = vector<vector<char>> {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' },
	};
	assert(Solution::isValidSudoku(input));

	input = {
		{ '8', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' },
	};
	assert(!Solution::isValidSudoku(input));

	input = {
		{ '.', '.', '.', '.', '5', '.', '.', '1', '.' },
		{ '.', '4', '.', '3', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '3', '.', '.', '1' },
		{ '8', '.', '.', '.', '.', '.', '.', '2', '.' },
		{ '.', '.', '2', '.', '7', '.', '.', '.', '.' },
		{ '.', '1', '5', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '2', '.', '.', '.' },
		{ '.', '2', '.', '9', '.', '.', '.', '.', '.' },
		{ '.', '.', '4', '.', '.', '.', '.', '.', '.' },
	};
	assert(!Solution::isValidSudoku(input));

	input = {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' },
	};
	assert(Solution::isValidSudokuOptimized(input));

	input = {
		{ '8', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' },
	};
	assert(!Solution::isValidSudokuOptimized(input));

	input = {
		{ '.', '.', '.', '.', '5', '.', '.', '1', '.' },
		{ '.', '4', '.', '3', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '3', '.', '.', '1' },
		{ '8', '.', '.', '.', '.', '.', '.', '2', '.' },
		{ '.', '.', '2', '.', '7', '.', '.', '.', '.' },
		{ '.', '1', '5', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.', '2', '.', '.', '.' },
		{ '.', '2', '.', '9', '.', '.', '.', '.', '.' },
		{ '.', '.', '4', '.', '.', '.', '.', '.', '.' },
	};
	assert(!Solution::isValidSudokuOptimized(input));
	return 0;
}
