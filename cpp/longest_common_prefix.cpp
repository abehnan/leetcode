#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    static std::string longestCommonPrefix(std::vector<std::string> &strings) {
        if (strings.empty()) {
            return {};
        }

        if (strings.size() == 1) {
            return strings[0];
        }

        sort(strings.begin(), strings.end());

        std::string result;
        std::string first = strings.front();
        std::string last = strings.back();
        int index = 0;

        while (index < first.size()
               && index < last.size()
               && first[index] == last[index]) {
            result.push_back(first[index++]);
        }

        return result;
    }
};

int main() {
    std::vector<std::string> test = {"blah", "bloh", "blih"};
    assert(Solution::longestCommonPrefix(test) == "bl");

    test = {"blah", "bloh", "apple"};
    assert(Solution::longestCommonPrefix(test).empty());

    test = {"flower", "flow", "flight"};
    assert(Solution::longestCommonPrefix(test) == "fl");

    test = {"dog", "racecar", "car"};
    assert(Solution::longestCommonPrefix(test).empty());

    return 0;
}
