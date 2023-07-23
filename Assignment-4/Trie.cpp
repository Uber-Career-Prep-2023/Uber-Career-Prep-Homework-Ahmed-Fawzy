#include <iostream>
#include <vector>
#include <string>
#include "Trie.h"

using namespace std;



Trie::Trie()
{
    root = new TrieNode();
}

Trie::~Trie()
{
    // Clean up the trie by deleting all nodes
    deleteTrie(root);
}

void Trie::insert(string word)
{
    TrieNode *current = root;
    for (char ch : word)
    {
        int index = ch - 'a';
        if (current->children[index] == nullptr)
        {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->validWord = true;
}

bool Trie::isValidWord(string word)
{
    TrieNode *node = findNode(word);
    return node != nullptr && node->validWord;
}

void Trie::remove(string word)
{
    removeHelper(root, word, 0);
}




TrieNode *Trie::findNode(string &word)
{
    TrieNode *current = root;
    for (char ch : word)
    {
        int index = ch - 'a';
        if (current->children[index] == nullptr)
        {
            return nullptr;
        }
        current = current->children[index];
    }
    return current;
}

void Trie::deleteTrie(TrieNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    for (TrieNode *child : node->children)
    {
        deleteTrie(child);
    }

    delete node;
}

bool Trie::removeHelper(TrieNode *node, string &word, int depth)
{
    if (node == nullptr)
    {
        return false;
    }

    if (depth == word.length())
    {
        if (node->validWord)
        {
            node->validWord = false;
            // Return true if the node has no other children, indicating it can be safely removed.
            return countChildren(node) == 0;
        }
        // Return false if the word does not exist in the trie.
        return false;
    }

    int index = word[depth] - 'a';
    bool shouldRemoveChild = removeHelper(node->children[index], word, depth + 1);

    if (shouldRemoveChild)
    {
        delete node->children[index];
        node->children[index] = nullptr;
    }

    // Return true if the current node can be safely removed (has no other children).
    return countChildren(node) == 0;
}

int Trie::countChildren(TrieNode *node)
{
    int count = 0;
    for (TrieNode *child : node->children)
    {
        if (child != nullptr)
        {
            count++;
        }
    }
    return count;
}

/*
int main()
{
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("orange");

    // Test case 1: Testing for insert and isValid functions on valid words
    std::cout << "Is 'apple' in Trie? " << (trie.isValidWord("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'app' in Trie? " << (trie.isValidWord("app") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'banana' in Trie? " << (trie.isValidWord("banana") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'orange' in Trie? " << (trie.isValidWord("orange") ? "Yes" : "No") << std::endl;

    //Testing case 2: Testing inValid on invalid word
    std::cout << "Is 'grape' in Trie? " << (trie.isValidWord("grape") ? "Yes" : "No") << std::endl;

    // Test case 3: Testing is remove works
    trie.remove("apple");
    trie.remove("orange");

    std::cout << "Is 'apple' in Trie after removal? " << (trie.isValidWord("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'orange' in Trie after removal? " << (trie.isValidWord("orange") ? "Yes" : "No") << std::endl;

    return 0;
}
*/