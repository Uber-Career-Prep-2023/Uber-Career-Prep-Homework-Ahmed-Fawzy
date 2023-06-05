/*
Time spent:       35 minutes
Technique:        Queue keeping track of ordering
Time complexity:  O(k)
Space complexity: O(k)
*/

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::string> FirstKBinaryNumbers(int k)
{

    if (k == 0)
        return std::vector<std::string>{};

    std::queue<std::string> numbers;
    std::vector<std::string> stringArr;

    stringArr.push_back("0");
    numbers.push("1");

    while (stringArr.size() < k)
    {

        std::string cur = numbers.front();
        stringArr.push_back(cur);

        numbers.pop();
        numbers.push(cur + "0");
        numbers.push(cur + "1");
    }

    return stringArr;
}

void printArr(std::vector<std::string> arr)
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
    std::cout << "]\n";
}

int main()
{
    // TEST 1: Base case, k=1 should output [0]
    std::cout << "Finding first 1 binary numbers : ";
    printArr(FirstKBinaryNumbers(1));

    // TEST 2: K=5 tests the validity of the queue algorithm, should output 5 binary numbers 0 to 4.
    std::cout << "Finding first 5 binary numbers : ";
    printArr(FirstKBinaryNumbers(5));

    // TEST 3: K=10 tests if it works for bigger values, should output 10 binary numbers 0 to 9.
    std::cout << "Finding first 10 binary numbers : ";
    printArr(FirstKBinaryNumbers(10));

    return 0;
}