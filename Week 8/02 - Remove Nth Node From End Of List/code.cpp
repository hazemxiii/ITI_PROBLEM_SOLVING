#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> nodes;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            nodes.push_back(cur);
            cur = cur->next;
        }
        int sz = nodes.size();
        if (sz - n == 0)
        {
            return head->next;
        }
        nodes[sz - n - 1]->next = nodes[sz - n]->next;
        return head;
    }
};

int main()
{
    return 0;
}
