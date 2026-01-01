#include <iostream>
using namespace std;

struct StackNode
{
    int val;
    int min;
    StackNode *next;
};

class MinStack
{
    StackNode *topP;

public:
    MinStack()
    {
        topP = nullptr;
    }

    void push(int val)
    {
        StackNode *n = new StackNode;
        if (n)
        {
            n->val = val;
            n->next = topP;
            if (topP)
            {
                n->min = val < topP->min ? val : topP->min;
            }
            else
            {
                n->min = val;
            }
            topP = n;
        }
    }

    void pop()
    {
        if (topP != nullptr)
        {
            StackNode *tempTop = topP;
            topP = topP->next;
            delete tempTop;
        }
    }

    int top()
    {
        if (topP)
        {
            return topP->val;
        }
        return 0;
    }

    int getMin()
    {
        if (topP)
        {
            return topP->min;
        }
        return 0;
    }
};
int main()
{
    return 0;
}
