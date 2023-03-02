// Simple one pointer forward traversal technique
// Space is O(1), runtime is O(n)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int MissingInteger(std::vector<int> arr, int n)
{

    int before = arr[0];
    if (before != 1)
        return 1;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - before > 1)
            return (arr[i] - 1);

        before = arr[i];
    }

    return n;
}

int main()
{

    std::vector<int> test1 = {1, 2, 3, 4, 6, 7};
    int n1 = 7;

    std::vector<int> test2 = {1};
    int n2 = 2;

    std::vector<int> test3 = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
    int n3 = 12;

    std::cout << "Input array with missing middle value: [1, 2, 3, 4, 6, 7]" << std::endl
              << "Input n: 7" << std::endl
              << "Output: " << MissingInteger(test1, n1) << "\n\n";
    std::cout << "Input array of size 1: [1]" << std::endl
              << "Input n: 2" << std::endl
              << "Output: " << MissingInteger(test2, n2) << "\n\n";
    std::cout << "Input a longer array: [1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12]" << std::endl
              << "Input n: 12" << std::endl
              << "Output: " << MissingInteger(test3, n3) << "\n\n";
}

// Time completed in: 17 minutes