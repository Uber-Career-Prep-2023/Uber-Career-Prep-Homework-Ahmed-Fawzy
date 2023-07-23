/*
n length of word

Time spent:       30 minutes
Technique:        Trie (from before)
Time complexity:  O(n)
Space complexity: O(n)
*/

#include <iostream>
#include <vector>
#include "Trie.h"

using namespace std;

bool WordBreak(vector<string> dict, string word)
{

    Trie trie;
    vector<string> words;

    for (int i = 0; i < dict.size(); i++)
    {

        trie.insert(dict[i]);
    }

    for (int i = 1; i <= word.size(); i++)
    {

        string subWord = word.substr(0, i);
        if (trie.isValidWord(subWord))
        {
            return true;
        }
    }

    return false;
}

void checkResult(bool result, string str)
{

    if (result)
    {
        cout << "The string \"" << str << "\" can be broken into valid words." << endl;
    }
    else
    {
        cout << "The string \"" << str << "\" cannot be broken into valid words." << endl;
    }
}

int main()
{

    string str1 = "mangolf";
    string str2 = "manateenotelf";
    string str3 = "quipig";

    vector<string> dict = {"elf", "go", "golf", "man", "manatee", "not", "note", "pig", "quip", "tee", "teen"};

    checkResult(WordBreak(dict, str1), str1);
    checkResult(WordBreak(dict, str2), str2);
    checkResult(WordBreak(dict, str3), str3);

    return 0;
}