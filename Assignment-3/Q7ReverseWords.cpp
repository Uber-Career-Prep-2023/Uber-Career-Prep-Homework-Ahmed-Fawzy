/*
n is number of characters

Time spent:       20 minutes
Technique:        Stack to reverse order
Time complexity:  O(n)
Space complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>

std::string ReverseWords(std::string str)
{

    std::stack<std::string> holder;
    std::string reverse = "";
    std::string word = "";

    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == ' ')
        {

            holder.push(word);
            word = "";
        }

        else if (i == str.size() - 1)
        {

            holder.push(word + str[i]);
        }

        else
        {

            word = word + str[i];
        }
    }

    while (!holder.empty())
    {

        if (reverse == "")
        {
            reverse = holder.top();
        }

        else
        {
            reverse = reverse + " " + holder.top();
        }

        holder.pop();
    }

    return reverse;
}

int main()
{

    // TEST 1: Checking if reverse works with only 3 words with letters only
    // Expected: "Prep Career Uber"
    std::cout << "Reverse of 'Uber Career Prep' is: " << ReverseWords("Uber Career Prep") << "\n";

    // TEST 2: Checking if reverse works with multiple words including other characters.
    // Exptected: "York. New Brooklyn, in lives Emma"
    std::cout << "Reverse of 'Emma lives in Brooklyn, New York.' is: " << ReverseWords("Emma lives in Brooklyn, New York.") << "\n";
}