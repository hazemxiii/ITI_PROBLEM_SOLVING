#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest
{
    int k;
    priority_queue<int, vector<int>, greater<int>> minH;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        int s = nums.size();
        for (int i = 0; i < s; i++)
        {
            add(nums[i]);
        }
    }

    int add(int val)
    {
        minH.push(val);
        if (minH.size() > k)
        {
            minH.pop();
        }
        return minH.top();
    }
};
int main()
{
    return 0;
}