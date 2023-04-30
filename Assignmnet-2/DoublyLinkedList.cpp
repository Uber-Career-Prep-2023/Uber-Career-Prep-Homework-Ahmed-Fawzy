// Doubly Linked List Functions done in 65 minutes

#include "header.h"
#include <iostream>

// creates new Node with data val at front; returns new head
// time is O(1)
DoublyNode *doublyInsertAtFront(DoublyNode *head, int val)
{

    DoublyNode *newHead = new DoublyNode;
    newHead->data = val;
    newHead->next = nullptr;
    newHead->prev = nullptr;

    if (head == nullptr)
    {
        return newHead;
    }

    newHead->next = head;
    head->prev = newHead;

    return newHead;
}

// creates new Node with data val at end
// time is O(n)
void doublyInsertAtBack(DoublyNode *head, int val)
{

    DoublyNode *newTail = new DoublyNode;
    newTail->data = val;
    newTail->next = nullptr;
    newTail->prev = nullptr;

    if (head == nullptr)
    {
        delete newTail;
        return;
    }

    while (head->next != nullptr)
    {
        head = head->next;
    }

    newTail->prev = head;
    head->next = newTail;
}

// creates new Node with data val after Node loc
// time is O(1)
void doublyInsertAfter(DoublyNode *head, int val, DoublyNode *loc)
{

    if (loc == nullptr)
        return;

    DoublyNode *newNode = new DoublyNode;
    newNode->data = val;
    newNode->next = loc->next;
    newNode->prev = loc;

    if (loc->next != nullptr)
        loc->next->prev = newNode;

    loc->next = newNode;
}

// removes first Node; returns new head
// time is O(1)
DoublyNode *doublyDeleteFront(DoublyNode *head)
{

    if (head == nullptr)
        return nullptr;

    DoublyNode *oldHead = head;
    head = head->next;
    head->prev = nullptr;

    delete oldHead;

    return head;
}

// removes last Node
// time is O(n)
void doublyDeleteBack(DoublyNode *head)
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
// time is O(1)
DoublyNode *doublyDeleteNode(DoublyNode *head, DoublyNode *loc)
{

    if (loc == nullptr || head == nullptr)
        return head;

    DoublyNode *previous = loc->prev;

    if (previous == nullptr)
    { // loc == head case

        DoublyNode *oldHead = head;
        head = head->next;
        head->prev = nullptr;

        delete oldHead;

        return head;
    }

    previous->next = loc->next;
    (loc->next)->prev = previous;

    delete loc;
    return head;
}

// returns length of the list
// time is O(n)
int doublyLength(DoublyNode *head)
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
DoublyNode *doublyReverseIterative(DoublyNode *head)
{

    if (head == nullptr)
        return nullptr;

    while (head->next != nullptr)
    {

        DoublyNode *temp = head->next;
        head->next = head->prev;
        head->prev = temp;

        head = head->prev;
    }

    head->next = head->prev;
    head->prev = nullptr;

    return head;
}

// reverses the linked list recursively (Hint: you will need a helper function)
// time is O(1) + O(n) = O(n)
DoublyNode *doublyReverseRecursive(DoublyNode *head)
{

    DoublyNode **newHead = new DoublyNode *;
    doublyReverseRecursiveHelper(head, newHead);

    DoublyNode *newHead2 = *newHead;
    delete newHead;

    return newHead2;
}

// O(n)
DoublyNode *doublyReverseRecursiveHelper(DoublyNode *node, DoublyNode **head)
{

    if (node == nullptr)
        return nullptr;

    if (node->next == nullptr)
    {
        *head = node;
        return node;
    }

    DoublyNode *temp = doublyReverseRecursiveHelper(node->next, head);

    DoublyNode *temp2 = temp->next;
    temp->next = node;
    temp->prev = temp2;

    if (node->prev == nullptr)
    { // the head (last to finish)
        node->prev = node->next;
        node->next = nullptr;

        return nullptr;
    }

    return node;
}

// used for testing
void doublyPrintList(DoublyNode *head)
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
void doublyClearList(DoublyNode *head)
{

    if (head == nullptr)
        return;

    while (head != nullptr)
    {

        DoublyNode *temp = head;
        head = head->next;

        delete temp;
    }
}

// Below are some test cases
void test()
{

    DoublyNode *head = nullptr;

    for (int i = 1; i < 10; i++)
    {
        head = doublyInsertAtFront(head, i);
    }

    doublyInsertAtBack(head, 0);
    doublyInsertAfter(head, 11, head);
    head = doublyDeleteFront(head);
    doublyDeleteBack(head);
    head = doublyDeleteNode(head, head->next);
    head = doublyReverseIterative(head);
    head = doublyReverseRecursive(head);

    std::cout << "Expected list is: [ 11, 7, 6, 5, 4, 3, 2, 1 ] " << std::endl
              << "Actual list is:   ";
    doublyPrintList(head);
    std::cout << "Length is: " << doublyLength(head);

    doublyClearList(head);
}
