#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int i;
        int num;
        while (left <= right)
        {
            i = (right + left) / 2;
            num = nums.at(i);
            if (num == target)
            {
                return i;
            }
            else if (num < target)
            {
                left = i + 1;
            }
            else
            {
                right = i - 1;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}