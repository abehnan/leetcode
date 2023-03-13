#include <cassert>
#include <string>
#include <stack>
#include <unordered_set>
#include <set>

class Solution {
public:
    static int lengthOfLongestSubstringBruteForce(const std::string& s) {
        std::set<char> visited;
        int result = 0;

        for (const char *c = s.c_str(); *c != '\0'; c++) {
            visited.clear();
            visited.emplace(*c);

            for (const char *d = c + 1; *d != '\0'; d++) {
                if (visited.find(*d) != visited.end()) {
                    break;
                }

                visited.emplace(*d);
            }

            result = std::max(result, static_cast<int>(visited.size()));
        }

        return result;
    }

    // Note: Using a sliding window to solve this in O(n)
    static int lengthOfLongestSubstring(const std::string &s) {
        std::unordered_set<char> seen;
        int left = 0, right = 0, n = static_cast<int>(s.size()), ans = 0;

        while (left < n && right < n) {
            if (seen.find(s[right]) == seen.end())  {
                seen.insert(s[right++]);
                ans = std::max(ans, right - left);
            } else {
                seen.erase(s[left++]);
            }
        }

        return ans;
    }
};

int main() {
    assert(Solution::lengthOfLongestSubstringBruteForce("abcabcbb") == 3);
    assert(Solution::lengthOfLongestSubstringBruteForce("bbbbb") == 1);
    assert(Solution::lengthOfLongestSubstringBruteForce("pwwkew") == 3);

    assert(Solution::lengthOfLongestSubstring("abcabcbb") == 3);
    assert(Solution::lengthOfLongestSubstring("bbbbb") == 1);
    assert(Solution::lengthOfLongestSubstring("pwwkew") == 3);
    return 0;
}
