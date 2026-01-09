#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> nums;
        for (string op : tokens)
        {
            int op1;
            int op2;
            switch (op[0])
            {
            case '+':
                op1 = nums.back();
                nums.pop_back();
                op2 = nums.back();
                nums.pop_back();
                nums.push_back(op1 + op2);
                break;
            case '*':
                op1 = nums.back();
                nums.pop_back();
                op2 = nums.back();
                nums.pop_back();
                nums.push_back(op1 * op2);
                break;
            case '/':
                op1 = nums.back();
                nums.pop_back();
                op2 = nums.back();
                nums.pop_back();
                nums.push_back(op2 / op1);
                break;
            case '-':
                if (op.length() == 1)
                {
                    op1 = nums.back();
                    nums.pop_back();
                    op2 = nums.back();
                    nums.pop_back();
                    nums.push_back(op2 - op1);
                    break;
                }
            default:
                nums.push_back(stoi(op));
            }
        }
        return nums.back();
    }
};

int main()
{
    vector<string> v = {"2", "1", "+", "3", "*"};
    cout << Solution().evalRPN(v);
    return 0;
}
