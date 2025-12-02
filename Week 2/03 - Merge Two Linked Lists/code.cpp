#include <iostream>
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }
        ListNode *head = list2;
        ListNode *putB4 = list2;
        ListNode *l2Prev = nullptr;
        ListNode *l1Next = nullptr;
        ListNode *l2Next = nullptr;
        while (list1 != nullptr)
        {
            while (putB4 != nullptr)
            {
                if (putB4->val >= list1->val)
                {
                    break;
                }
                l2Prev = putB4;
                putB4 = putB4->next;
            }
            l1Next = list1->next;
            l2Next = putB4;
            if (putB4 == nullptr)
            {
                l2Prev->next = list1;
                return head;
            }
            list1->next = putB4;
            if (l2Prev != nullptr)
            {
                l2Prev->next = list1;
            }
            else
            {
                head = list1;
            }
            l2Prev = list1;
            putB4 = l2Next;
            list1 = l1Next;
        }
        return head;
    }
};

int main()
{
    return 0;
}