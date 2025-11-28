#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int diff = 0;
        int min = prices.at(0);
        for (int n : prices)
        {
            int newDiff = n - min;
            if (newDiff > diff)
            {
                diff = newDiff;
            }
            if (n < min)
            {
                min = n;
            }
        }
        return diff;
    }
};
