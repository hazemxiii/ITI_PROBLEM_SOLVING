#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int s = nums.size();
        if (s == 1)
        {
            return nums;
        }
        vector<int> out(s, 0);
        for (int i = 0; i < s; i++)
        {
            int j = i + nums[i];
            if (j > 0)
            {
                j = j % s;
            }
            else
            {
                j = (s - (abs(j) % s)) % s;
            }
            out[i] = nums[j];
        }
        return out;
    }
};

int main()
{
    vector<int> v = {3, -2, 1, 1};
    Solution().constructTransformedArray(v);
    return 0;
}
