/**
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * Constraints:
 * 	2 <= nums.length <= 105
 * 	-30 <= nums[i] <= 30
 * 	The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer
 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	static vector<int> productExceptSelf(vector<int>& nums)
	{
		auto n = static_cast<int>(nums.size());
		auto forwardProduct = 1;
		vector<int> ans(n, 1);

		for (auto i = n - 2; i >= 0; i--) {
			ans[i] = ans[i + 1] * nums[i + 1];
		}

		for (auto i = 0; i < n; i++) {
			ans[i] *= forwardProduct;
			forwardProduct *= nums[i];
		}

		return ans;
	}

	static vector<int> productExceptSelfTheHardWay(vector<int>& nums)
	{
		auto numZeroes = 0;
		std::vector<int> result;

		std::for_each(nums.begin(), nums.end(), [&numZeroes](int num) -> void {
			if (num == 0) {
				numZeroes++;
			}
		});

		auto product = 1;
		std::for_each(nums.begin(), nums.end(), [&product](int num) -> void {
			if (num != 0) {
				product *= num;
			}
		});

		if (numZeroes == 1) {
			std::transform(
				nums.begin(),
				nums.end(),
				std::back_inserter(result),
				[&product](int num) -> int {
					if (num != 0) {
						return 0;
					} else {
						return product;
					}
				});
			return result;
		} else if (numZeroes > 1) {
			result.insert(result.begin(), nums.size(), 0);
			return result;
		}

		std::transform(
			nums.begin(),
			nums.end(),
			std::back_inserter(result),
			[&product](int num) -> int {
				return bitwiseDivide(product, num);
			});

		return result;
	}

	static int bitwiseDivide(int dividend, int divisor)
	{
		if (divisor == 0) {
			return -1; // Error: divide by zero
		}

		auto sign = 1;

		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
			sign = -1;
		}

		dividend = abs(dividend);
		divisor = abs(divisor);
		auto quotient = 0;
		auto remainder = 0u;

		for (int i = 31; i >= 0; i--) {
			remainder <<= 1; // Shift remainder to the left by 1 bit
			auto bit = (dividend & (1 << i)) ? 1 : 0; // Get current bit of dividend
			remainder |= bit; // Add current bit to remainder

			if (remainder >= static_cast<unsigned int>(divisor)) {
				remainder -= divisor;
				quotient |= (1 << i); // Set current bit of quotient to 1
			}
		}

		return quotient * sign;
	}
};

int main()
{
	auto expected = vector<int> {};
	auto result = vector<int> {};
	auto input = vector<int> {};
	auto actual = Solution::productExceptSelfTheHardWay(input);
	assert(actual == expected);

	input = { 1, 2, 3, 4 };
	expected = { 24, 12, 8, 6 };
	actual = Solution::productExceptSelfTheHardWay(input);
	assert(actual == expected);

	input = { -1, 1, 0, -3, 3 };
	expected = { 0, 0, 9, 0, 0 };
	actual = Solution::productExceptSelfTheHardWay(input);
	assert(actual == expected);

	input = { 5, 9, 2, -9, -9, -7, -8, 7, -9, 10 };
	expected = { -51438240, -28576800, -128595600, 28576800, 28576800, 36741600, 32148900, -36741600, 28576800, -25719120 };
	actual = Solution::productExceptSelfTheHardWay(input);
	assert(actual == expected);

	expected = {};
	result = {};
	input = {};
	actual = Solution::productExceptSelf(input);
	assert(actual == expected);

	input = { 1, 2, 3, 4 };
	expected = { 24, 12, 8, 6 };
	actual = Solution::productExceptSelf(input);
	assert(actual == expected);

	input = { -1, 1, 0, -3, 3 };
	expected = { 0, 0, 9, 0, 0 };
	actual = Solution::productExceptSelf(input);
	assert(actual == expected);

	input = { 5, 9, 2, -9, -9, -7, -8, 7, -9, 10 };
	expected = { -51438240, -28576800, -128595600, 28576800, 28576800, 36741600, 32148900, -36741600, 28576800, -25719120 };
	actual = Solution::productExceptSelf(input);
	assert(actual == expected);

	return 0;
}
