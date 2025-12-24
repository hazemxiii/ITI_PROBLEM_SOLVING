#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }

    vector<int> countBitsAnotherSolution(int n)
    {
        vector<int> v(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                v[i] = 0;
            }
            else if (i % 2 == 0)
            {
                int temp = i;
                int ones = 0;
                while (temp > 0)
                {
                    ones++;
                    temp = temp - pow(2, (int)log2(temp));
                }
                v[i] = ones;
            }
            else
            {
                v[i] = v[i - 1] + 1;
            }
        }
        return v;
    }
};

int main()
{
}