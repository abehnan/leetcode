/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 *  - Open brackets must be closed by the same type of brackets.
 *  - Open brackets must be closed in the correct order.
 *  - Every close bracket has a corresponding open bracket of the same type.
 */

#include <cassert>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	static int validParentheses(const string& str)
	{
		if (str.empty()) {
			return true;
		}

		auto s = stack<char> {};

		for (const auto& c : str) {
			if (s.empty()) {
				s.push(c);
				continue;
			}

			auto top = s.top();

			switch (top) {
				case '[':
					if (c == ']') {
						s.pop();
						continue;
					}
					break;
				case '{':
					if (c == '}') {
						s.pop();
						continue;
					}
					break;
				case '(':
					if (c == ')') {
						s.pop();
						continue;
					}
					break;
				default:
					break;
			}

			s.push(c);
		}

		return s.empty();
	}
};

int main()
{
	assert(Solution::validParentheses("()"));
	assert(Solution::validParentheses("()[]{}"));
	assert(!Solution::validParentheses("(]"));
	assert(!Solution::validParentheses("({{{{}}}))"));
	return 0;
}
