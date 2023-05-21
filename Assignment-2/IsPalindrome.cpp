/*
n is number of nodes

Time spent:       17 minutes
Technique:        Doubly linked list forward-backward two-pointer
Time complexity:  O(n)
Space complexity: O(1)
*/

#include "header.h"
#include <iostream>
#include <cmath>

bool IsPalindrome(DoublyNode *leftNode)
{
    DoublyNode *rightNode = leftNode;
    double count = 1;

    while (rightNode->next != nullptr)
    { // goes to the last node
        rightNode = rightNode->next;
        count++;
    }

    count = ceil(count / 2); // halfway

    while (count > 0)
    {

        if (rightNode->data != leftNode->data)
        {
            return false;
        }

        rightNode = rightNode->prev;
        leftNode = leftNode->next;
        count--;
    }

    return true;
}

int main()
{

    DoublyNode *head = new DoublyNode;
    head->next = nullptr;
    head->prev = nullptr;
    head->data = 9;

    doublyInsertAtBack(head, 2);
    doublyInsertAtBack(head, 4);
    doublyInsertAtBack(head, 2);
    doublyInsertAtBack(head, 9);

    std::string result = IsPalindrome(head) ? "True" : "False";

    std::cout << "The list is: ";
    doublyPrintList(head);
    std::cout << "Is Palindrome? " << result << std::endl;

    head->next->data = 12; // new test case

    result = IsPalindrome(head) ? "True" : "False";
    std::cout << "The list is: ";
    doublyPrintList(head);
    std::cout << "Is Palindrome? " << result << std::endl;

    doublyClearList(head);
}