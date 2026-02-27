#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {
        int n = nums.size();
        int target = nums[0] + nums[1];
        int operations = 0;

        for (int i = 0; i + 1 < n; i += 2)
        {
            if (nums[i] + nums[i + 1] == target)
                operations++;
            else
                break;
        }

        return operations;
    }
};

int main()
{
    return 0;
}
