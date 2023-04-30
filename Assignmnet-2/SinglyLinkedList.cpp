// Linked List Functions done in 90 minutes

#include "header.h"
#include <iostream>

// creates new Node with data val at front; returns new head
// time is O(1)
Node *insertAtFront(Node *head, int val)
{

    Node *newHead = new Node;
    newHead->data = val;
    newHead->next = nullptr;

    if (head == nullptr)
    {
        return newHead;
    }

    newHead->next = head;
    return newHead;
}

// creates new Node with data val at end
// time is O(n)
void insertAtBack(Node *head, int val)
{

    Node *newTail = new Node;
    newTail->data = val;
    newTail->next = nullptr;

    if (head == nullptr)
    {
        delete newTail;
        return;
    }

    while (head->next != nullptr)
    {
        head = head->next;
    }

    head->next = newTail;
}

// creates new Node with data val after Node loc
// time is O(1)
void insertAfter(Node *head, int val, Node *loc)
{

    if (loc == nullptr)
        return;

    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = loc->next;

    loc->next = newNode;
}

// removes first Node; returns new head
// time is O(1)
Node *deleteFront(Node *head)
{

    if (head == nullptr)
        return nullptr;

    Node *oldHead = head;
    head = head->next;

    delete oldHead;

    return head;
}

// removes last Node
// time is O(n)
void deleteBack(Node *head)
{
    if (head == nullptr)
        return;

    if (head->next == nullptr)
    {
        delete head;
        return;
    }

    while (head->next->next != nullptr)
    {
        head = head->next;
    }

    delete head->next;
    head->next = nullptr;
}

// deletes Node loc; returns head
// time is O(n)
Node *deleteNode(Node *head, Node *loc)
{

    if (loc == nullptr || head == nullptr)
        return head;

    if (head == loc)
    {
        delete head;
        return nullptr;
    }

    Node *traversal = head;

    while (traversal != nullptr && traversal->next != loc)
    {
        traversal = traversal->next;
    }

    if (traversal->next != loc)
        return head;

    traversal->next = loc->next;

    delete loc;
    return head;
}

// returns length of the list
// time is O(n)
int length(Node *head)
{

    if (head == nullptr)
        return 0;

    int len = 1;

    while (head->next != nullptr)
    {
        head = head->next;
        len++;
    }

    return len;
}

// reverses the linked list iteratively
// time is O(n)
Node *reverseIterative(Node *head)
{

    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;

    Node *first = head;
    Node *second = head->next;
    Node *third = head->next->next;

    head->next = nullptr;

    while (third != nullptr)
    {

        second->next = first;

        first = second;
        second = third;
        third = third->next;
    }

    second->next = first;
    return second;
}

// reverses the linked list recursively (Hint: you will need a helper function)
// time is O(1) + O(n) = O(n)
Node *reverseRecursive(Node *head)
{

    Node **newHead = new Node *;
    reverseRecursiveHelper(head, newHead);

    Node *newHead2 = *newHead;
    delete newHead;

    return newHead2;
}

// O(n)
Node *reverseRecursiveHelper(Node *node, Node **head)
{

    if (node == nullptr)
        return nullptr;
    if (node->next == nullptr)
    {
        *head = node;
        return node;
    }

    Node *temp = reverseRecursiveHelper(node->next, head);

    temp->next = node;
    node->next = nullptr;

    return node;
}

// used for testing
void printList(Node *head)
{

    if (head == nullptr)
        return;

    std::cout << "[ ";

    while (head->next != nullptr)
    {
        std::cout << head->data << ", ";
        head = head->next;
    }

    std::cout << head->data << " ]" << std::endl;
}

// used to deallocate memory
void clearList(Node *head)
{

    if (head == nullptr)
        return;

    while (head != nullptr)
    {

        Node *temp = head;
        head = head->next;

        delete temp;
    }
}

// Below are some test cases
void test()
{

    Node *head = nullptr;

    for (int i = 1; i < 10; i++)
    {
        head = insertAtFront(head, i);
    }

    insertAtBack(head, 0);
    insertAfter(head, 11, head);
    head = deleteFront(head);
    deleteBack(head);
    head = deleteNode(head, head->next);
    head = reverseIterative(head);
    head = reverseRecursive(head);

    std::cout << "Expected list is: [ 11, 7, 6, 5, 4, 3, 2, 1 ] " << std::endl
              << "Actual list is:   ";
    printList(head);
    std::cout << "Length is: " << length(head);

    clearList(head);
}
