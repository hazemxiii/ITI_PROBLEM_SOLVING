#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>> maxHeap;
        for (int &num : nums)
        {
            maxHeap.push(num);
        }
        int out;
        for (int i = 0; i < k; i++)
        {
            if (i == k - 1)
            {
                out = maxHeap.top();
            }
            maxHeap.pop();
        }
        return out;
    }
};

int main()
{
    return 0;
}
