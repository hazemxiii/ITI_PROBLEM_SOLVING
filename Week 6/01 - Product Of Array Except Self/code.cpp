#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int s = nums.size();
        vector<int> out;
        int productBeforeI = 1;
        for (int &n : nums)
        {
            out.push_back(productBeforeI);
            productBeforeI *= n;
        }
        int productAfterI = 1;
        for (int i = s - 1; i >= 0; i--)
        {
            out[i] *= productAfterI;
            productAfterI *= nums[i];
        }
        return out;
    }
};

int main()
{
    return 0;
}
