#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int s = stones.size();
        priority_queue<int> maxHeap = {};
        for (int i = 0; i < s; i++)
        {
            maxHeap.push(stones[i]);
        }
        int max1;
        int max2;
        int newWeight;
        while (maxHeap.size() > 1)
        {
            max1 = maxHeap.top();
            maxHeap.pop();
            max2 = maxHeap.top();
            maxHeap.pop();
            newWeight = abs(max1 - max2);
            if (newWeight != 0)
            {
                maxHeap.push(newWeight);
            }
            else
            {
                if (maxHeap.empty())
                {
                    return 0;
                }
            }
        }
        return maxHeap.top();
    }
};
int main()
{
    return 0;
}