#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        unordered_map<Node *, Node *> nodes;
        Node *curr = head;
        while (curr != NULL)
        {
            nodes[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr != NULL)
        {
            nodes[curr]->next = curr->next ? nodes[curr->next] : NULL;
            nodes[curr]->random = curr->random ? nodes[curr->random] : NULL;
            curr = curr->next;
        }
        return nodes[head];
    }
};

int main()
{
    return 0;
}
