// Hash the elements and two pointer n,n-1,n-2... traversal technique
// Space is O(n), runtime is O(n^2)  [n is the length of the longer input string]

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int ShortestSubstring(std::string input, std::string chars)
{

  int ans = input.length() + 1;

  for (int i = 0; i < input.length(); i++)
  {

    std::map<char, int> m;
    int total = 0;

    for (int i = 0; i < chars.length(); i++)
    {
      m[chars[i]]++;
    }

    for (int k = i; k < input.length(); k++)
    {
      if (m[input[k]] > 0)
      {
        m[input[k]]--;
        total++;
        if (total == chars.length())
        {
          if ((k - i + 1) < ans)
          {
            ans = (k - i + 1);
          }
          k = input.length();
        }
      }
    }
  }

  if (ans == input.length() + 1)
    return -1; // indicate no answer found!
  return ans;
}

int main()
{

  std::string test1[2] = {"abracadabra", "abc"};
  std::string test2[2] = {"zxycbaabcdwxyzzxwdcbxyzabccbazyx", "zzyzx"};
  std::string test3[2] = {"dog", "god"};

  std::cout << "Input string that has multiple valid substrings: \"abracadabra\", \"abc\" " << std::endl
            << "Output: " << ShortestSubstring(test1[0], test1[1]) << std::endl
            << std::endl;
  std::cout << "Input string that contains lots of characters: \"zxycbaabcdwxyzzxwdcbxyzabccbazyx\", \"zzyzx\" " << std::endl
            << "Output: " << ShortestSubstring(test2[0], test2[1]) << std::endl
            << std::endl;
  std::cout << "Input string that contains only 1 valid substring: \"dog\", \"god\" " << std::endl
            << "Output: " << ShortestSubstring(test3[0], test3[1]) << std::endl
            << std::endl;
}

// Time completed in: 40 minutes