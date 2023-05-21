//Header file in order to use the linkedlist and bst functions to test the problems given.

#ifndef HEADER_H 
#define HEADER_H

struct Node
{

    int data;
    Node *next;
};

struct DoublyNode
{

    int data;
    DoublyNode *next;
    DoublyNode *prev;
};

struct TreeNode
{
    int data;
    TreeNode *left;  // left data is less than current node data
    TreeNode *right; // right data is more than current node data
};

class BinarySearchTree
{

private:
    TreeNode *head;

public:
    BinarySearchTree() { head = nullptr; }
    int min();              // returns the minimum value in the BST
    int max();              // returns the maximum value in the BST
    bool contains(int val); // returns a boolean indicating whether val is present in the BST
    void insert(int val);   // creates a new Node with data val in the appropriate location, no duplicates!

    TreeNode *deleteNode(TreeNode *node, int val); // deletes the Node with data val and returns root
    int DeleteSuccessor(TreeNode *node);       // deletes the successor and returns val

    TreeNode *getHead() { return head; }
    void setHead(TreeNode *n) { head = n; }
    void clearTree(TreeNode *node);
};


Node *insertAtFront(Node *head, int val);
void insertAtBack(Node *head, int val);
void insertAfter(Node *head, int val, Node *loc);
Node *deleteFront(Node *head);
void deleteBack(Node *head);
Node *deleteNode(Node *head, Node *loc);
int length(Node *head);
Node *reverseIterative(Node *head);
Node *reverseRecursive(Node *head);
Node *reverseRecursiveHelper(Node *node, Node **head);
void printList(Node *head);
void clearList(Node *head);

DoublyNode *doublyInsertAtFront(DoublyNode *head, int val);
void doublyInsertAtBack(DoublyNode *head, int val);
void doublyInsertAfter(DoublyNode *head, int val, DoublyNode *loc);
DoublyNode *doublyDeleteFront(DoublyNode *head);
void doublyDeleteBack(DoublyNode *head);
DoublyNode *doublyDeleteNode(DoublyNode *head, DoublyNode *loc);
int doublyLength(DoublyNode *head);
DoublyNode *doublyReverseIterative(DoublyNode *head);
DoublyNode *doublyReverseRecursive(DoublyNode *head);
DoublyNode *doublyReverseRecursiveHelper(DoublyNode *node, DoublyNode **head);
void doublyPrintList(DoublyNode *head);
void doublyClearList(DoublyNode *head);

#endif