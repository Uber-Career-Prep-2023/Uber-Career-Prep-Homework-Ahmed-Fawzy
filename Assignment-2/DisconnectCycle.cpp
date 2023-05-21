/*
n is number of nodes

Time spent:       28 minutes
Technique:        Hash linked list nodes
Time complexity:  O(n)
Space complexity: O(n) //probably not the optimal solution
*/

#include "header.h"
#include <iostream>
#include <map>

void DisconnectCycle(Node *node)
{

    if (node == nullptr)
        return;

    std::map<Node *, bool> m;
    m[node] = true;

    while (node->next != nullptr && !m[node->next])
    {
        m[node->next] = true;
        node = node->next;
    }

    node->next = nullptr;
}

int main()
{
    Node *head = new Node;
    head->data = 10;
    head->next = nullptr;

    insertAtBack(head, 18);
    insertAtBack(head, 12);
    insertAtBack(head, 9);
    insertAtBack(head, 11);
    insertAtBack(head, 4);

    head->next->next->next->next->next->next = head->next->next; // 4 points to 12
    DisconnectCycle(head);
    std::cout << "Original List: [10, 18, 12, 9, 11, 4, 12, 9, 11, 4...]\n";
    std::cout << "List after disconnect: ";
    printList(head);

    head->next->next->next->next->next->next = head->next->next->next->next->next; // 4 points to itself
    DisconnectCycle(head);
    std::cout << std::endl
              << "Original List: [10, 18, 12, 9, 11, 4, 4, 4...]\n";
    std::cout << "List after disconnect: ";
    printList(head);

    clearList(head);
}