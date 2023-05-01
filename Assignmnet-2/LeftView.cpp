/*
n is number of nodes
h is height of tree [note if tree is balanced height is O(logn) ]

Time spent:       40 minutes
Technique:        Pre-order traversal while keeping track of height.
Time complexity:  O(n)
Space complexity: O(h)

Explaination: simple preoder tree traversal while keeping track of the node height, each time a node
              with a new height is reached a 2d array is updated (y value is height, x value is left-most data)
*/

#include "header.h"
#include <iostream>
#include <vector>

// function declerations
void LeftViewHelper(const TreeNode *node, std::vector<std::vector<int>> &arr, int level);
std::vector<int> LeftView(const TreeNode *root);

std::vector<int> LeftView(const TreeNode *root)
{

    std::vector<std::vector<int>> arr;
    std::vector<int> leftArr = {};

    if (root == nullptr)
        return leftArr;

    LeftViewHelper(root, arr, 0); // root height starts at 0

    for (int i = 0; i < arr.size(); i++)
    {
        leftArr.push_back(arr[i][0]);
    }

    return leftArr;
}

void LeftViewHelper(const TreeNode *node, std::vector<std::vector<int>> &arr, int level)
{

    if (node == nullptr)
        return;

    if (arr.size() < level + 1)
    {
        arr.push_back(std::vector<int>{node->data});
    }

    LeftViewHelper(node->left, arr, level + 1);
    LeftViewHelper(node->right, arr, level + 1);
}

// test cases
int main()
{

    TreeNode *node1 = new TreeNode;
    TreeNode *node2 = new TreeNode;
    TreeNode *node3 = new TreeNode;
    TreeNode *node4 = new TreeNode;
    TreeNode *node5 = new TreeNode;
    TreeNode *node6 = new TreeNode;
    TreeNode *node7 = new TreeNode;
    TreeNode *node8 = new TreeNode;

    node1->data = 7;
    node2->data = 8;
    node3->data = 3;
    node4->data = 9;
    node5->data = 13;
    node6->data = 20;
    node7->data = 14;
    node8->data = 15;

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = nullptr;

    node3->left = node5;
    node3->right = nullptr;

    node4->left = node6;
    node4->right = nullptr;

    node5->left = node7;
    node5->right = nullptr;

    node6->left = nullptr;
    node6->right = nullptr;

    node7->left = nullptr;
    node7->right = node8;

    node8->left = nullptr;
    node8->right = nullptr;

    std::vector<int> arr = LeftView(node1);

    std::cout << "Testing the following tree: \n";
    std::cout << "Level 1: 7 \n";
    std::cout << "Level 2: 8, 3 \n";
    std::cout << "Level 3: 9, 13 \n";
    std::cout << "Level 4: 20, 14 \n";
    std::cout << "Level 5: 15 \n\n";
    std::cout << "Array of left view is: ";

    std::cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];

        if (i != arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]\n";

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    delete node8;
}