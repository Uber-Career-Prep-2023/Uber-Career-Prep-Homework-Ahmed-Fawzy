// Growing/Shrinking sliding window technique
// Space is O(1), runtime is O(n)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

void print(std::vector<int> arr)
{
  std::cout << "[";
  for (int i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i];
    if (i != arr.size() - 1)
      std::cout << ", ";
  }
  std::cout << "]"
            << "\n \n";
}

std::vector<int> DedupArray(std::vector<int> arr)
{
  if (arr.size() <= 1)
    return arr;

  int cur = arr[0];
  int pos = 1;

  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i] != cur)
    {
      arr[pos] = arr[i];
      cur = arr[i];
      pos++;
    }
  }

  arr.erase(arr.begin() + pos, arr.end());

  return arr;
}

int main()
{

  std::vector<int> test1 = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  std::vector<int> test2 = {0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
  std::vector<int> test3 = {1, 3, 4, 8, 10, 12};

  std::cout << "Input 1 with repeated digits: [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]" << std::endl
            << "Modified Array: ";
  print(DedupArray(test1));

  std::cout << "Input 2 with digit 0 and repeated nums: [0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15]" << std::endl
            << "Modified Array: ";
  print(DedupArray(test2));

  std::cout << "Input 3 with no repeated digits: [1, 3, 4, 8, 10, 12]" << std::endl
            << "Modified Array: ";
  print(DedupArray(test3));
}

// Time completed in: 15 minutes