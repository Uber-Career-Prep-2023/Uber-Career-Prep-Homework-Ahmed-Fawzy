// hash the elements technique
// Space is O(n), runtime is O(n)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

int TwoSum(std::vector<int> arr, int k)
{

    std::unordered_map<int, int> m;
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (k - arr[i] == arr[i] && m[arr[i]] > 0)
            ans = ans + m[arr[i]];
        m[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (m[k - arr[i]] > 0 && k - arr[i] != arr[i])
        {
            ans = ans + m[k - arr[i]];
            m[arr[i]]--;
        }
    }

    return ans;
}

int main()
{
    std::vector<int> test1 = {1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
    int k1 = 10;
    int k2 = 8;

    std::vector<int> test2 = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
    int k3 = 6;
    int k4 = 1;

    std::cout << "Input array containing negatives : [1, 10, 8, 3, 2, 5, 7, 2, -2, -1]\n"
              << "Input k: " << k1 << "\n"
              << "Output: " << TwoSum(test1, k1) << "\n\n";
    std::cout << "Input array containing negatives: [1, 10, 8, 3, 2, 5, 7, 2, -2, -1]\n"
              << "Input k: " << k2 << "\n"
              << "Output: " << TwoSum(test1, k2) << "\n\n";
    std::cout << "Input array with no negatives: [4, 3, 3, 5, 7, 0, 2, 3, 8, 6]\n"
              << "Input k: " << k3 << "\n"
              << "Output: " << TwoSum(test2, k3) << "\n\n";
    std::cout << "IInput array with no negatives: [4, 3, 3, 5, 7, 0, 2, 3, 8, 6]\n"
              << "Input k: " << k4 << "\n"
              << "Output: " << TwoSum(test2, k4) << "\n\n";
}

// Time completed in: 32 minutes