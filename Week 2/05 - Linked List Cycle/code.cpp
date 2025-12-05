#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *last = nullptr;
        while (head != nullptr)
        {
            if (last != nullptr)
            {
                if (head <= last)
                {
                    return 1;
                }
            }
            last = head;
            head = head->next;
        }
        return 0;
    }
};

int main()
{
    return 0;
}