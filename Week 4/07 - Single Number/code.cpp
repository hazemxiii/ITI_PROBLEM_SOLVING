#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int bit = 0;
        int s = nums.size();
        for (int i = 0; i < s; i++)
        {
            bit = bit ^ nums[i];
        }
        return bit;
    }
};

int main()
{
    vector<int> v = {4, 4, 5, 2, 2};
    Solution().singleNumber(v);
    return 0;
}