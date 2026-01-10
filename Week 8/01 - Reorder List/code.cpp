#include <iostream>
#include <vector>
#include <math.h>
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
    void reorderList(ListNode *head)
    {
        ListNode *cur = head;
        vector<ListNode *> list;
        while (cur != nullptr)
        {
            list.push_back(cur);
            cur = cur->next;
        }
        int size = list.size();
        int halfSize = ceil(size / 2.0);
        for (int i = 0; i < halfSize; i++)
        {
            if (list[i]->next != list[size - i - 1])
            {
                list[size - i - 1]->next = list[i]->next;
            }
            else
            {
                list[size - i - 1]->next = nullptr;
            }
            if (list[i] != list[size - i - 1])
            {
                list[i]->next = list[size - i - 1];
            }
            else
            {
                list[i]->next = nullptr;
            }
        }
    }
};
int main()
{
    ListNode *list1 = new ListNode(1,
                                   new ListNode(2,
                                                new ListNode(3,
                                                             new ListNode(4,
                                                                          new ListNode(5)))));

    Solution()
        .reorderList(list1);
    return 0;
}
