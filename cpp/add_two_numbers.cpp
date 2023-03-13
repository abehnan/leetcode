/**
 * (Given) Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include <cmath>
#include <cassert>
#include <vector>

namespace {
    struct ListNode {
        int val = 0;
        ListNode *next = nullptr;

        explicit ListNode() = default;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

    int getNumber(ListNode *list) {
        int exp = 0;
        int result = 0;
        ListNode *node = list;

        while (node != nullptr) {
            result += node->val * static_cast<int>(std::pow(10, exp++));
            node = node->next;
        }

        return result;
    }

    ListNode *buildList(int number) {
        ListNode *result = nullptr;
        ListNode *currentNode, *previousNode = nullptr;

        if (number == 0) {
            return new ListNode();
        }

        while (number > 0) {
            currentNode = new ListNode(number % 10);

            if (previousNode) {
                previousNode->next = currentNode;
            } else {
                result = currentNode;
            }

            previousNode = currentNode;
            number /= 10;
        }

        return result;
    }
}

class Solution {
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0, sum;
        ListNode *current = new ListNode(), *result = current;

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


int main() {
    ListNode *firstNumber = buildList(453);
    int x = getNumber(firstNumber);
    assert(x == 453);

    ListNode *secondNumber = buildList(101);
    int y = getNumber(secondNumber);
    assert(y == 101);

    assert(getNumber(Solution::addTwoNumbers(buildList(342), buildList(465))) == 807);

    assert(getNumber(Solution::addTwoNumbers(
            buildList(5132948),
            buildList(851793462))) == 856926410);

    return 0;
}