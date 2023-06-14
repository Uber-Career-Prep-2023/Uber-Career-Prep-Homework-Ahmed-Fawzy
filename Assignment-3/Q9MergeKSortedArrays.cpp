/*
n is total number of elements
k is the number of arrays

Time spent:       35 minutes
Technique:        Min priority Queue (put first element of each array into pq, pop, push first element in the array that the popped value came from..)
Time complexity:  O(nlogk)
Space complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

auto comparator = [](const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.first > b.first;
};

std::vector<int> MergeKSortedArrays(std::vector<std::vector<int>> &arrays)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comparator)> pq(comparator); // min pq

    std::vector<int> arrIndex = {};
    std::vector<int> finalArr = {};

    for (int k = 0; k < arrays.size(); k++)
    {

        pq.push({arrays[k][0], k});
        arrIndex.push_back(1);
    }

    while (!pq.empty())
    {
        std::pair<int, int> top = pq.top();
        pq.pop();

        finalArr.push_back(top.first);

        int k = top.second;
        if (arrIndex[k] <= arrays[k].size() - 1)
        {

            pq.push({arrays[k][arrIndex[k]], k});
            arrIndex[k]++;
        }
    }

    return finalArr;
}

void printArr(std::vector<int> arr)
{

    std::cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];

        if (i != arr.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n\n";
}

int main()
{

    // TEST 1: testing with 2 arrays that have some overlapping intervals
    std::vector<std::vector<int>> input1 = {{1, 2, 3, 4, 5}, {1, 3, 5, 7, 9}};
    std::cout << "Merging the following arrays: [1, 2, 3, 4, 5], [1, 3, 5, 7, 9]\n";
    std::cout << "Output: ";
    printArr(MergeKSortedArrays(input1));

    // TEST 2: testing with 3 bigger arrays that have many overlapping intervals and even duplicate numbers
    std::vector<std::vector<int>> input2 = {{1, 4, 7, 9}, {2, 6, 7, 10, 11, 13, 15}, {3, 8, 12, 13, 16}};
    std::cout << "Merging the following arrays: [1, 4, 7, 9], [2, 6, 7, 10, 11, 13, 15], [3, 8, 12, 13, 16]\n";
    std::cout << "Output: ";
    printArr(MergeKSortedArrays(input2));

    return 0;
}