#ifndef LEETCODE_LIST_HELPER_H
#define LEETCODE_LIST_HELPER_H

#include <cmath>

namespace ListHelper {
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

#endif //LEETCODE_LIST_HELPER_H
