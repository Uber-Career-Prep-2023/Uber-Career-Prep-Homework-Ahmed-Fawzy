#include<string>
#include<vector>
using namespace std;

struct TrieNode
{
    vector<struct TrieNode *> children;
    bool validWord;

    TrieNode() : children(26, nullptr), validWord(false) {}
};

class Trie
{
public:
    Trie();
    ~Trie();
    void insert(string word);
    bool isValidWord(string word);
    void remove(string word);

private:
    struct TrieNode *root;
    TrieNode *findNode(string &word);
    void deleteTrie(TrieNode *node);
    bool removeHelper(TrieNode *node, string &word, int depth);
    int countChildren(TrieNode *node);
};