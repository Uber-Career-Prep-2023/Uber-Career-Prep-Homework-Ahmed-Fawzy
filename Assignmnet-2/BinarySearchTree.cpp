// time: 120 min

#include "header.h"
#include <iostream>

// time complexity: O(n)
void BinarySearchTree::clearTree(TreeNode *node)
{

    if (node == nullptr)
        return;

    clearTree(node->left);
    clearTree(node->right);

    if (node == head)
        head = nullptr;
    delete node;
}

// time complexity: O(n)
int BinarySearchTree::min()
{

    if (head == nullptr)
        throw std::invalid_argument("Tree is empty!");

    TreeNode *node = head;

    while (node->left != nullptr)
    {
        node = node->left;
    }

    return node->data;
}

// time complexity: O(n)
int BinarySearchTree::max()
{

    if (head == nullptr)
        throw std::invalid_argument("Tree is empty!");

    TreeNode *node = head;

    while (node->right != nullptr)
    {
        node = node->right;
    }

    return node->data;
}

// time complexity: O(n)
bool BinarySearchTree::contains(int val)
{

    if (head == nullptr)
        return false;

    TreeNode *node = head;

    while (node->data != val)
    {

        if (val > node->data)
        {
            node = node->right;
        }

        else
        {
            node = node->left;
        }

        if (node == nullptr)
            return false;
    }

    return true;
}

// time complexity: O(n)
void BinarySearchTree::insert(int val)
{

    if (head == nullptr)
    {
        TreeNode *newNode = new TreeNode;
        head = newNode;

        newNode->data = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return;
    }

    TreeNode *node = head;
    bool findSpot = true;

    while (findSpot)
    {

        if (val == node->data)
            return;

        if (val > node->data && node->right != nullptr)
        {
            node = node->right;
        }

        else if (val < node->data && node->left != nullptr)
        {
            node = node->left;
        }

        else
        {
            findSpot = false;
        }
    }

    TreeNode *newNode = new TreeNode;
    newNode->data = val;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (val > node->data)
    {
        node->right = newNode;
    }
    else
    {
        node->left = newNode;
    }
}

// time complexity: O(n)
TreeNode *BinarySearchTree::deleteNode(TreeNode *node, int val)
{

    if (node == nullptr)
        return nullptr;

    else if (val > node->data)
        node->right = deleteNode(node->right, val);

    else if (val < node->data)
        node->left = deleteNode(node->left, val);

    else
    {

        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }

        else if (node->left != nullptr && node->right == nullptr)
        {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }

        else if (node->left == nullptr && node->right != nullptr)
        {
            TreeNode *temp = node->right;
            delete node;
            return temp;
        }

        else
        {

            int successorVal = DeleteSuccessor(node);
            node->data = successorVal;
            return node;
        }
    }

    return node;
}

int BinarySearchTree::DeleteSuccessor(TreeNode *node)
{ // node is guranteed to have 2 childern

    TreeNode *nextNode = node->right;

    while (nextNode != nullptr)
    {

        if (nextNode->left == nullptr)
        {
            node->right = nextNode->right;
            int val = nextNode->data;
            delete nextNode;

            return val;
        }

        node = nextNode;
        nextNode = nextNode->left;
    }

    return 0; // will never occur
}


//Below are some test cases
void test()
{

    // testing

    BinarySearchTree tree;

    tree.insert(7);
    tree.insert(12);
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    tree.insert(13);
    tree.setHead(tree.deleteNode(tree.getHead(), 7));
    tree.setHead(tree.deleteNode(tree.getHead(), 13));

    std::cout << "Inserted: 7, 12, 5, 4, 6, 13" << std::endl;
    std::cout << "Max: " << tree.max() << std::endl;
    std::cout << "Min: " << tree.min() << std::endl;

    std::string containOne = tree.contains(1) ? "true" : "false";
    std::cout << "Contains 1 ? " << containOne << std::endl;

    std::string containFour = tree.contains(4) ? "true" : "false";
    std::cout << "Contains 4 ? " << containFour << std::endl;

    tree.clearTree(tree.getHead());
}
