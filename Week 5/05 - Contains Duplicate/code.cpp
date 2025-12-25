#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        int s = nums.size();
        for (int i = 0; i < s; i++)
        {
            if (seen.count(nums[i]))
            {
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};
int main()
{
    vector<int> n = {1, 1, 2, 3, 4};
    Solution().containsDuplicate(n);
    return 0;
}
