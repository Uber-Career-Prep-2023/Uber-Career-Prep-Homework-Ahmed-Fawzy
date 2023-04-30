/*
n is number of nodes

Time spent:       20 minutes
Technique:        Generic Depth-first traversal
Time complexity:  O(n)
Space complexity: O(1)
*/

#include "header.h"
#include <iostream>

bool IsBST(const TreeNode *node)
{

    if (node == nullptr)
        return true;

    if (node->left != nullptr && node->left->data > node->data)
    { // left node greated than parent
        return false;
    }

    if (node->right != nullptr && node->right->data < node->data)
    { // right node less than parent
        return false;
    }

    bool checkLeft = IsBST(node->left);
    bool checkRight = IsBST(node->right);

    return (checkLeft && checkRight); // both childern must be valid for a valid tree
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

    std::string result = IsBST(test.getHead()) ? "True" : "False";
    std::cout << "Testing IsBST with a valid tree of 6 nodes: " << result << std::endl;

    test.getHead()->left->data = 2;

    result = IsBST(test.getHead()) ? "True" : "False";
    std::cout << "Testing IsBST with a invalid tree of 6 nodes: " << result << std::endl;
}