#include <cassert>
#include <string>
#include <unordered_map>

class Solution {
public:
    static int romanToInt(const std::string &str) {
        const std::unordered_map<char, int> romanToDecimal = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };

        int result = 0;

        for (auto i = 0; i < str.length(); i++) {
            const bool lessThanNext = i < str.length() - 1
                                      && romanToDecimal.at(str[i]) < romanToDecimal.at(str[i + 1]);

            if (lessThanNext) {
                result -= romanToDecimal.at(str[i]);
            } else {
                result += romanToDecimal.at(str[i]);
            }
        }

        return result;
    }
};

int main() {
    assert(Solution::romanToInt("III") == 3);
    assert(Solution::romanToInt("LVIII") == 58);
    assert(Solution::romanToInt("MCMXCIV") == 1994);
    return 0;
}
