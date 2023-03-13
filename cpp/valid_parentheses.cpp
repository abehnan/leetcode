/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 *  - Open brackets must be closed by the same type of brackets.
 *  - Open brackets must be closed in the correct order.
 *  - Every close bracket has a corresponding open bracket of the same type.
 */

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
