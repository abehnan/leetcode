/**
* Given a string s, return the longest palindromic substring in s.
*/

#include <cassert>
#include <string>
#include <vector>

class Solution {
public:
    // dynamic programming approach, O(n^2)
    static std::string longestPalindrome(const std::string &str) {
        auto n = str.length();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        auto maxLength = 1;
        auto start = 0;

        // All substrings of length 1 are palindromes
        for (auto i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check substrings of length 2
        for (auto i = 0; i < n - 1; i++) {
            if (str[i] == str[i + 1]) {
                dp[i][i + 1] = true;
                maxLength = 2;
                start = i;
            }
        }

        // Check substrings of length > 2
        for (auto len = 3; len <= n; len++) {
            for (auto i = 0; i <= n - len; i++) {
                auto j = i + len - 1;

                if (str[i] == str[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;

                    if (len > maxLength) {
                        maxLength = len;
                        start = i;
                    }
                }
            }
        }

        return str.substr(start, maxLength);
    }

    static std::string longestPalindromeBruteForce(const std::string &str) { // O(n^3)
        auto n = str.length();
        auto maxLength = 1;
        auto start = 0;

        // Check all possible substrings
        for (auto i = 0; i < n; i++) {
            for (auto j = i; j < n; j++) {
                auto len = j - i + 1;

                if (len > maxLength && isPalindrome(str, i, j)) {
                    maxLength = len;
                    start = i;
                }
            }
        }

        return str.substr(start, maxLength);
    }

    static bool isPalindrome(const std::string &str, int left, int right) {
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    assert(Solution::longestPalindromeBruteForce("babad") == "bab");
    assert(Solution::longestPalindromeBruteForce("cbbd") == "bb");
    assert(Solution::longestPalindrome("babad") == "bab");
    assert(Solution::longestPalindrome("cbbd") == "bb");
    return 0;
}
