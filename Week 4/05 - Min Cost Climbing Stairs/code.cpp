#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // 10 15 20
        int s = cost.size();
        int i1 = 0;
        int i2 = 0;
        int newV;
        for (int i = 0; i < s; i++)
        {
            newV = min(i1, i2) + cost[i];
            i1 = i2;
            i2 = newV;
        }
        return min(i1, i2);
    }
};
int main()
{
    vector<int> c = {0, 0, 0, 1};
    Solution().minCostClimbingStairs(c);
    return 0;
}