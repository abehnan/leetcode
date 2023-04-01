/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include "../include/list_helper.h"
#include <cassert>
#include <vector>

using namespace ListHelper;

class Solution {
public:
	// O(n)
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int sum;
		auto carry = 0;
		auto *current = new ListNode(), *result = current;

		while (l1 || l2 || carry) {
			sum = carry;

			if (l1) {
				sum += l1->val;
				l1 = l1->next;
			}

			if (l2) {
				sum += l2->val;
				l2 = l2->next;
			}

			carry = sum / 10;
			sum %= 10;

			// Not a huge fan of returning something on the heap, but LeetCode expects it.
			current->next = new ListNode(sum);
			current = current->next;
		}

		return result->next;
	}
};

int main()
{
	ListNode* firstNumber = buildList(453);
	int x = getNumber(firstNumber);
	assert(x == 453);

	ListNode* secondNumber = buildList(101);
	int y = getNumber(secondNumber);
	assert(y == 101);

	assert(getNumber(Solution::addTwoNumbers(buildList(342), buildList(465))) == 807);

	assert(getNumber(Solution::addTwoNumbers(
			   buildList(5132948),
			   buildList(851793462))) == 856926410);

	return 0;
}