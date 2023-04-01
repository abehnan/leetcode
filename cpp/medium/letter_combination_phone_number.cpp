/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
 * A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * 		2 = abc
 * 		3 = def
 * 		4 = ghi
 * 		5 = jkl
 * 		6 = mno
 * 		7 = pqrs
 * 		8 = tuv
 * 		9 = wxyz
 *
 * Constraints:
 * 		0 <= digits.length <= 4
 * 		digits[i] is a digit in the range ['2', '9']
 *
 * Example:
 * 		Input: digits = "23"
 * 		Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 */

#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	// O(4^n) worst case because of "7" and "9", otherwise O(3^n) if the string does not contain either of these.
	static vector<string> letterCombinations(const string& digits)
	{
		const auto map = unordered_map<char, vector<char>> {
			{ '2', { 'a', 'b', 'c' } },
			{ '3', { 'd', 'e', 'f' } },
			{ '4', { 'g', 'h', 'i' } },
			{ '5', { 'j', 'k', 'l' } },
			{ '6', { 'm', 'n', 'o' } },
			{ '7', { 'p', 'q', 'r', 's' } },
			{ '8', { 't', 'u', 'v' } },
			{ '9', { 'w', 'x', 'y', 'z' } },
		};

		auto numPermutations = [&digits, &map](unsigned int index) -> unsigned int {
			auto numPermutations = 1u;

			for (auto i = 0u; i < digits.size(); i++) {
				if (i == index) {
					continue;
				}

				numPermutations *= map.at(digits[i]).size();
			}

			return numPermutations;
		};

		auto results = vector<string> {};

		if (!digits.empty()) {
			for (const auto& c : map.at(digits[0])) {
				for (auto i = 0u; i < numPermutations(0); i++) {
					results.emplace_back(1, c);
				}
			}
		}

		if (digits.size() > 1) {
			auto index = 0u;
			for (auto i = 0u; i < numPermutations(1); i++) {
				for (const auto& c : map.at(digits[1])) {
					results[index++] += c;
				}
			}
		}

		for (auto i = 2u; i < digits.size(); i++) {
			auto index = 0u;
			auto letters = map.at(digits[i]);
			auto it = letters.begin();
			sort(results.begin(), results.end());

			while (index < results.size()) {
				results[index] += *it;

				if (++it == letters.end()) {
					it = letters.begin();
				}

				index++;
			}
		}

		return results;
	}
};

int main()
{
	assert(Solution::letterCombinations("").empty());

	auto input = string { "23" };
	auto expected = vector<string> { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" };
	auto actual = Solution::letterCombinations(input);
	sort(expected.begin(), expected.end());
	sort(actual.begin(), actual.end());
	assert(actual == expected);

	input = string { "2" };
	expected = { "a", "b", "c" };
	actual = Solution::letterCombinations(input);
	sort(expected.begin(), expected.end());
	sort(actual.begin(), actual.end());
	assert(actual == expected);

	input = string { "234" };
	expected = {
		"adg",
		"adh",
		"adi",
		"aeg",
		"aeh",
		"aei",
		"afg",
		"afh",
		"afi",
		"bdg",
		"bdh",
		"bdi",
		"beg",
		"beh",
		"bei",
		"bfg",
		"bfh",
		"bfi",
		"cdg",
		"cdh",
		"cdi",
		"ceg",
		"ceh",
		"cei",
		"cfg",
		"cfh",
		"cfi",
	};
	actual = Solution::letterCombinations(input);
	sort(expected.begin(), expected.end());
	sort(actual.begin(), actual.end());
	assert(actual == expected);

	return 0;
}
