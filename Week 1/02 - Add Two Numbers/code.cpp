#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *list = new ListNode(0);
        ListNode *lP = list;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int l1V = 0;
            int l2V = 0;
            if (l1 != nullptr)
            {
                l1V = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2V = l2->val;
                l2 = l2->next;
            }
            int val = l1V + l2V + carry;
            carry = 0;
            if (val >= 10)
            {
                lP->val += (val % 10);
                carry = (int)(val / 10);
                // ListNode *newNode = new ListNode(0);
                // lP->next = newNode;
            }
            else
            {
                lP->val += val;
            }
            if (l1 != nullptr || l2 != nullptr)
            {
                ListNode *newNode = new ListNode(0);
                lP->next = newNode;
                lP = lP->next;
            }
        }
        if (carry != 0)
        {
            lP->next = new ListNode(carry);
        }
        return list;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printList(ListNode *i)
{
    do
    {
        cout << i->val << endl;
        i = i->next;
    } while (i != nullptr);
    cout << endl;
}

int main()
{
    ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    ListNode *i = Solution().addTwoNumbers(l1, l2);
    printList(i);

    return 0;
}