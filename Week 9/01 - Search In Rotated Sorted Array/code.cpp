#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (target == nums[mid])
            {
                return mid;
            }
            if (target == nums[left])
                return left;
            if (target == nums[right])
                return right;
            if (nums[mid] > nums[left])
            {
                if (target < nums[mid] && target > nums[left])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target < nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    Solution().search(v, 3);
    return 0;
}
