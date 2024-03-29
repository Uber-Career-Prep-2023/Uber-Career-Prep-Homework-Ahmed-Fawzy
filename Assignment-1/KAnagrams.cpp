// Hash the elements technique (using an array)
// Space is O(1), runtime is O(n)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

std::string KAnagrams(std::string firstString, std::string secondString, int k)
{
    int letters[128] = {0};

    if (firstString.length() != secondString.length())
        return "false";

    for (int i = 0; i < firstString.length(); i++)
    {
        letters[int(firstString[i])]++;
        letters[int(secondString[i])]--;
    }
    int diff = 0;
    for (int i = 0; i < 128; i++)
    {
        if (letters[i] != 0)
            diff++;
    }
    diff = diff / 2;

    if (diff > k)
        return "false";

    return "true";
}

int main()
{

    std::string test1[2] = {"apple", "peach"};
    int k1 = 1;
    int k2 = 2;

    std::string test3[2] = {"cat", "dog"};
    int k3 = 3;

    std::string test4[2] = {"debit curd", "bad credit"};
    int k4 = 1;

    std::string test5[2] = {"baseball", "basketball"};
    int k5 = 2;

    std::cout << std::boolalpha;
    std::cout << "Input Strings that need more than 1 change (invalid): \"apple\", \"peach\" " << std::endl
              << "Input k: 1" << std::endl
              << KAnagrams(test1[0], test1[1], k1) << "\n\n";
    std::cout << "Input Strings that need 2 changes (valid): \"apple\", \"peach\" " << std::endl
              << "Input k: 2" << std::endl
              << KAnagrams(test1[0], test1[1], k2) << "\n\n";
    std::cout << "Input Strings where K is the same as length: \"cat\", \"dog\" " << std::endl
              << "Input k: 3" << std::endl
              << KAnagrams(test3[0], test3[1], k3) << "\n\n";
    std::cout << "Input Strings with mutiple words (valid): \"debit curd\", \"bad credit\" " << std::endl
              << "Input k: 1" << std::endl
              << KAnagrams(test4[0], test4[1], k4) << "\n\n";
    std::cout << "Input Strings with different lengths: \"baseball\", \"basketball\" " << std::endl
              << "Input k: 2" << std::endl
              << KAnagrams(test5[0], test5[1], k5) << "\n\n";
}

// Time completed in: 23 minutes