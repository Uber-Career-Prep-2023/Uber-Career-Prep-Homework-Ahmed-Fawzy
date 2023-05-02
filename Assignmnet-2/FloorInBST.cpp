/*
n is number of nodes

Time spent:       25 minutes
Technique:        In-order traversal while keeping track of closest value so far.
Time complexity:  O(n)
Space complexity: O(1)

Explaination: in-order traversal to get numbers in order, keeping track of any value less than target
              and thats bigger than current value.
*/

#include "header.h"
#include <iostream>

// function decleration
int FloorInBST(const TreeNode *root, int target);
void FloorInBSTHelper(const TreeNode *node, int *value, int target);

int FloorInBST(const TreeNode *root, int target)
{
    if (root == nullptr)
        return -1; // error no tree given

    int value = root->data;

    FloorInBSTHelper(root, &value, target);

    if (value > target)
        return -2; // error all nodes are bigger than targer

    return value;
}

void FloorInBSTHelper(const TreeNode *node, int *value, int target)
{

    if (node == nullptr)
        return;

    FloorInBSTHelper(node->left, value, target);

    if (*value > target && node->data <= target)
    {
        *value = node->data;
    }

    else if ((target - *value > target - node->data) && node->data <= target)
    {
        *value = node->data;
    }

    FloorInBSTHelper(node->right, value, target);
}

// test cases
int main()
{

    BinarySearchTree tree;

    tree.insert(10);
    tree.insert(8);
    tree.insert(16);
    tree.insert(9);
    tree.insert(13);
    tree.insert(17);
    tree.insert(20);

    std::cout << "The following is being used to test:\n";
    std::cout << "Level 1: 10\n";
    std::cout << "Level 2: 8, 16\n";
    std::cout << "Level 3: 9, 13, 17\n";
    std::cout << "Level 4: 20\n\n";

    std::cout << "FloorInBST for target 13 is: " << FloorInBST(tree.getHead(), 13);
    std::cout << "\nFloorInBST for target 15 is: " << FloorInBST(tree.getHead(), 15);

    tree.clearTree(tree.getHead());
}