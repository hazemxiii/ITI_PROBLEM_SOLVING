#include <iostream>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev2 = 0;
        int prev = 1;
        for (int i = 1; i <= n; i++)
        {
            prev = prev2 + prev;
            prev2 = prev - prev2;
        }
        return prev;
    }
};

int main()
{
    return 0;
}