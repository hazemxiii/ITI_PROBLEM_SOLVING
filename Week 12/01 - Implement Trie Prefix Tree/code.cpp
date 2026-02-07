#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    char c;
    unordered_map<char, Node *> children;
    Node(char c)
    {
        this->c = c;
    }
};

class Trie
{
public:
    unordered_map<char, Node *> roots;
    Node *terminal;
    Trie()
    {
        terminal = new Node('\0');
    }

    void insert(string word)
    {
        if (roots.find(word[0]) == roots.end())
        {
            roots[word[0]] = new Node(word[0]);
        }
        int s = word.size();
        Node *n = roots[word[0]];
        for (int i = 1; i < s; i++)
        {
            if (n->children.find(word[i]) == n->children.end())
            {
                n->children[word[i]] = new Node(word[i]);
            }
            n = n->children[word[i]];
        }
        n->children['\0'] = terminal;
    }

    bool search(string word)
    {
        if (roots.find(word[0]) == roots.end())
        {
            return 0;
        }
        Node *n = roots[word[0]];
        int s = word.size();
        for (int i = 1; i < s; i++)
        {
            if (n->children.find(word[i]) == n->children.end())
            {
                return 0;
            }
            n = n->children[word[i]];
        }
        if (n->children.find('\0') == n->children.end())
        {
            return 0;
        }
        return 1;
    }

    bool startsWith(string prefix)
    {
        if (roots.find(prefix[0]) == roots.end())
        {
            return 0;
        }
        Node *n = roots[prefix[0]];
        int s = prefix.size();
        for (int i = 1; i < s; i++)
        {
            if (n->children.find(prefix[i]) == n->children.end())
            {
                return 0;
            }
            n = n->children[prefix[i]];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    return 0;
}
