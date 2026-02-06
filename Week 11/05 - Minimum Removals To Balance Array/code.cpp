#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxKeep = 1;
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            while (j < n && (long long)nums[j] <= (long long)k * nums[i])
                j++;
            maxKeep = max(maxKeep, j - i);
        }

        return n - maxKeep;
    }
};

int main()
{
    return 0;
}
