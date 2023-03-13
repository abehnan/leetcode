/**
* Given a string s, return the longest palindromic substring in s.
*/

#include <cassert>
#include <string>

class Solution {
public:
    static std::string longestPalindrome(const std::string &/*s*/) {
        return {};
    }
};

int main() {
    assert(Solution::longestPalindrome("babad") == "bab");
    assert(Solution::longestPalindrome("cbbd") == "bb");
    return 0;
}
