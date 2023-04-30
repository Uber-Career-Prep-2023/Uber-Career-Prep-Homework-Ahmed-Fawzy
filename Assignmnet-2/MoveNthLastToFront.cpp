/*
n is number of nodes

Time spent:       35 minutes
Technique:        Linked list reset/catch-up two-pointer
Time complexity:  O(n)
Space complexity: O(1)
*/

#include "header.h"
#include <iostream>

Node *MoveNthLastToFront(Node *node, int n)
{
    Node *head = node;

    Node *targetPrev = head;
    int count = -1;

    while (node != nullptr)
    {

        node = node->next;

        if (count != n)
        {
            count++;
        }

        else
        {
            targetPrev = targetPrev->next;
        }
    }

    if (n != count || targetPrev->next == nullptr)
    { // n is too big or too small, do nothing.
        return head;
    }

    Node *temp = targetPrev->next;
    targetPrev->next = targetPrev->next->next;

    temp->next = head;

    return temp;
}

int main()
{

    Node *head = new Node;
    head->data = 15;
    head->next = nullptr;

    insertAtBack(head, 2);
    insertAtBack(head, 8);
    insertAtBack(head, 7);
    insertAtBack(head, 20);
    insertAtBack(head, 9);
    insertAtBack(head, 11);
    insertAtBack(head, 6);
    insertAtBack(head, 19);

    std::cout << "Current List: ";
    printList(head);
    std::cout << "Nth value is: 2" << std::endl;
    head = MoveNthLastToFront(head, 2);
    std::cout << "List after the move: ";
    printList(head);

    std::cout << std::endl
              << "Current List: ";
    printList(head);
    std::cout << "Nth value is: 7" << std::endl;
    head = MoveNthLastToFront(head, 7);
    std::cout << "List after the move: ";
    printList(head);

    clearList(head);
}