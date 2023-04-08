
#ifndef LEETCODE_LIST_HELPER_H
#define LEETCODE_LIST_HELPER_H

#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

namespace ListHelper {
    /* Definition for singly-linked list. */
    struct ListNode {
        int val = 0;
        ListNode *next = nullptr;

        explicit ListNode() = default;

        explicit ListNode(int x) : val(x), next(nullptr) {}
    };

    void trimLeftTrailingSpaces(std::string &input) {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
            return !isspace(ch);
        }));
    }

    void trimRightTrailingSpaces(std::string &input) {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
            return !isspace(ch);
        }).base(), input.end());
    }

    std::vector<int> stringToIntegerVector(std::string input) {
        std::vector<int> output;
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        std::stringstream ss;
        ss.str(input);
        std::string item;
        char delim = ',';
        while (getline(ss, item, delim)) {
            output.push_back(stoi(item));
        }
        return output;
    }

    ListNode *stringToListNode(const std::string &input) {
        // Generate list from the input
        std::vector<int> list = stringToIntegerVector(input);

        // Now convert that list into linked list
        auto *dummyRoot = new ListNode();
        auto *ptr = dummyRoot;
        for (int item: list) {
            ptr->next = new ListNode(item);
            ptr = ptr->next;
        }
        ptr = dummyRoot->next;
        delete dummyRoot;
        return ptr;
    }

    void prettyPrintLinkedList(ListNode *node) {
        while (node && node->next) {
            std::cout << node->val << "->";
            node = node->next;
        }

        if (node) {
            std::cout << node->val << std::endl;
        } else {
            std::cout << "Empty LinkedList" << std::endl;
        }
    }

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
