#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int out = 0;
        int s = nums.size();
        for (int i = 0; i < s - 1; i += 2)
        {
            out += min(nums[i], nums[i + 1]);
        }
        return out;
    }
};

int main()
{
    return 0;
}
