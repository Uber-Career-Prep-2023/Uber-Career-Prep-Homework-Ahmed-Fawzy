// One pointer technique used to find string after all deletions
// Space is O(1), runtime is O(n)  [n is the length of the longer input string]

/*Explanation:
Loop through the characters if you see "#" delete the char before and current char (#)
Compare both strings to see if they are equal
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

bool BackSpaceStringCompare(std::string firstString, std::string secondString)
{

  for (int i = 0; i < firstString.length(); i++)
  {
    if (i == 0 && firstString[0] == '#')
    {
      firstString.erase(0, 1);
      i--;
    }

    if (i > 0 && firstString[i] == '#')
    {
      firstString.erase(i, 1);
      firstString.erase(i - 1, 1);
      i = i - 2;
    }
  }

  for (int i = 0; i < secondString.length(); i++)
  {
    if (i == 0 && secondString[0] == '#')
    {
      secondString.erase(0, 1);
      i--;
    }

    if (i > 0 && secondString[i] == '#')
    {
      secondString.erase(i, 1);
      secondString.erase(i - 1, 1);
      i = i - 2;
    }
  }
  return (firstString == secondString);
}

int main()
{

  std::string test1[2] = {"abcde", "abcde"};
  std::string test2[2] = {"Uber Career Prep", "u#Uber Careee#r Prep"};
  std::string test3[2] = {"abcdef###xyz", "abcw#xyz"};
  std::string test4[2] = {"abcdef###xyz", "abcdefxyz###"};

  std::cout << std::boolalpha;
  std::cout << "Input strings 1 with no deletes: \"abcde\", \"abcde\" " << std::endl
            << "Output: " << BackSpaceStringCompare(test1[0], test1[1]) << std::endl
            << std::endl;
  std::cout << "Input strings 2 with deletes and spaces: \"Uber Career Prep\", \"u#Uber Careee#r Prep\" " << std::endl
            << "Output: " << BackSpaceStringCompare(test2[0], test2[1]) << std::endl
            << std::endl;
  std::cout << "Input strings 3 with deletes and a match: \"abcdef###xyz\", \"abcw#xyz\" " << std::endl
            << "Output: " << BackSpaceStringCompare(test3[0], test3[1]) << std::endl
            << std::endl;
  std::cout << "Input strings 4 with no match: \"abcdef###xyz\",\"abcdefxyz###\" " << std::endl
            << "Output: " << BackSpaceStringCompare(test4[0], test4[1]) << std::endl
            << std::endl;
}

// Time completed in: 35 minutes