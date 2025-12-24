#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum = 0;
        int size = nums.size();
        int total = size * (size + 1) / 2;
        bool foundZero = 0;
        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
            if (nums[i] == 0)
            {
                foundZero = 1;
            }
        }
        if (total == sum)
        {
            return foundZero ? size + 1 : 0;
        }
        return total - sum;
    }
};

int main()
{
    return 0;
}
