/**
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
 */

#include <cassert>
#include "include/list_helper.h"

using namespace ListHelper;

class Solution {
public:
	static ListNode* mergeTwoLists(ListNode* left, ListNode* right)
	{
		auto result = new ListNode();
		auto ans = result;

		while (left || right) {
			if (left && right) {
				if (left->val < right->val) {
					result->next = new ListNode(left->val);
					left = left->next;
				} else {
					result->next = new ListNode(right->val);
					right = right->next;
				}
			} else if (left) {
				result->next = new ListNode(left->val);
				left = left->next;
			} else {
				result->next = new ListNode(right->val);
				right = right->next;
			}

			result = result->next;
		}

		return ans->next;
	}
};

int main()
{
	ListNode* firstNumber = buildList(754);
	int x = getNumber(firstNumber);
	assert(x == 754);

	ListNode* secondNumber = buildList(921);
	int y = getNumber(secondNumber);
	assert(y == 921);

	auto list = Solution::mergeTwoLists(firstNumber, secondNumber);
	auto number = getNumber(list);
	assert(number == 975421); // note that getNumber assumes the list stores a number in reverse order

	return 0;
}