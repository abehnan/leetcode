#pragma clang diagnostic push
#pragma ide diagnostic ignored "performance-inefficient-vector-operation"
/**
* Design an algorithm to encode a list of strings to a single string.
* The encoded string is then decoded back to the original list of strings.
* Please implement encode and decode
 * Constraints:
 *  - 0 <= strs.length < 100
 *  - 0 <= strs[i].length < 200
 *  - strs[i] contains only UTF-8 characters.
 */
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	static string encode(const vector<string>& strs)
	{
		std::string encoded;

		for (const std::string& s : strs) {
			encoded += std::to_string(s.length()) + "#" + s;
		}

		return encoded;
	}

	static vector<string> decode(const string& s)
	{
		std::vector<std::string> decoded;
		int i = 0;

		while (i < s.length()) {
			// Read length
			int j = i;
			while (s[j] != '#') {
				j++;
			}
			const auto len = std::stoi(s.substr(i, j - i));
			i = j + 1; // Skip past '#'

			// Extract the string of that length
			decoded.push_back(s.substr(i, len));
			i += len;
		}

		return decoded;
	}
};

int main()
{
	auto input = vector<string> { "neet", "code", "love", "you" };
	assert(input == Solution::decode(Solution::encode(input)));
	input = vector<string> { "we", "say", ":", "yes" };
	assert(input == Solution::decode(Solution::encode(input)));
	return 0;
}

#pragma clang diagnostic pop