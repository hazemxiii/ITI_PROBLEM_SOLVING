#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache
{
    int c;
    int maxC;
    unordered_map<int, Node *> data;
    Node *head;
    Node *tail;

public:
    LRUCache(int capacity)
    {
        c = 0;
        maxC = capacity;
        head = tail = nullptr;
    }

    int get(int key)
    {
        if (data.find(key) == data.end())
        {
            return -1;
        }

        Node *node = data[key];

        if (node == tail)
        {
            return node->val;
        }

        if (node == head)
        {
            head = head->next;
            if (head)
                head->prev = nullptr;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->next = nullptr;
        node->prev = tail;
        if (tail)
            tail->next = node;
        tail = node;

        if (!head)
            head = node;
        return node->val;
    }

    void put(int key, int value)
    {

        if (data.find(key) != data.end())
        {
            data[key]->val = value;
            get(key);
            return;
        }

        Node *node = new Node(key, value);

        if (!head)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        data[key] = node;
        c++;

        if (c > maxC)
        {
            Node *oldHead = head;
            data.erase(oldHead->key);

            head = head->next;
            if (head)
                head->prev = nullptr;
            else
                tail = nullptr;

            delete oldHead;
            c--;
        }
    }
};

int main()
{
    return 0;
}
