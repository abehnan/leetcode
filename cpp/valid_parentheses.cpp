#include <cassert>
#include <string>
#include <stack>

class Solution {
public:
    static int validParentheses(const std::string &str) {
        if (str.empty()) {
            return true;
        }

        std::stack<char> stack;

        for (const char *c = str.c_str(); *c != '\0'; c++) {
            if (stack.empty()) {
                stack.push(*c);
                continue;
            }

            char top = stack.top();

            switch (top) {
                case '[':
                    if (*c == ']') {
                        stack.pop();
                        continue;
                    }
                    break;
                case '{':
                    if (*c == '}') {
                        stack.pop();
                        continue;
                    }
                    break;
                case '(':
                    if (*c == ')') {
                        stack.pop();
                        continue;
                    }
                    break;
                default:
                    break;
            }

            stack.push(*c);
        }

        return stack.empty();
    }
};

int main() {
    assert(Solution::validParentheses("()"));
    assert(Solution::validParentheses("()[]{}"));
    assert(!Solution::validParentheses("(]"));
    assert(!Solution::validParentheses("({{{{}}}))"));
    return 0;
}
