/*
n is number of nodes

Time spent:       40 minutes
Technique:        Generic Depth-first traversal
Time complexity:  O(n)
Space complexity: O(n)
*/

#include "header.h"
#include <iostream>

// function decleration
void CopyTreeHelper(TreeNode *copyNode, const TreeNode *originalNode);
TreeNode *CopyTree(const TreeNode *node);

TreeNode *CopyTree(const TreeNode *node)
{ // node given is the root of the original tree

    if (node == nullptr)
        return nullptr;

    TreeNode *newNode = new TreeNode;
    CopyTreeHelper(newNode, node);

    return newNode;
}

void CopyTreeHelper(TreeNode *copyNode, const TreeNode *originalNode)
{

    copyNode->data = originalNode->data;
    copyNode->left = nullptr;
    copyNode->right = nullptr;

    if (originalNode->left != nullptr)
    {

        copyNode->left = new TreeNode;
        CopyTreeHelper(copyNode->left, originalNode->left);
    }

    if (originalNode->right != nullptr)
    {

        copyNode->right = new TreeNode;
        CopyTreeHelper(copyNode->right, originalNode->right);
    }
}

int main()
{

    BinarySearchTree test;
    test.insert(10);

    test.insert(5);
    test.insert(3);
    test.insert(6);

    test.insert(15);
    test.insert(19);

    TreeNode *newTree = CopyTree(test.getHead());

    std::cout << "In order traveral of original: \n";
    std::cout << "3, 5, 6, 10, 15, 19 \n";

    std::cout << "In order traveral of copy: \n";
    std::cout << newTree->left->left->data << ", " << newTree->left->data << ", " << newTree->left->right->data << ", " << newTree->data << ", " << newTree->right->data << ", " << newTree->right->right->data;

    test.clearTree(test.getHead()); // clears original tree
    test.setHead(newTree);
    test.clearTree(test.getHead()); // clears copy tree
}