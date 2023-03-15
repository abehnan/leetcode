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
    static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        return nullptr;
    }
};


int main() {
    ListNode *firstNumber = buildList(457);
    int x = getNumber(firstNumber);
    assert(x == 457);

    ListNode *secondNumber = buildList(129);
    int y = getNumber(secondNumber);
    assert(y == 129);


    return 0;
}