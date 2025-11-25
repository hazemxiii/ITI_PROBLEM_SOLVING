#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            int num = nums.at(i);
            if (m.count(num) > 0)
            {
                vector<int> v = {m[num], i};
                return v;
            }
            else
            {
                m[target - num] = i;
            }
        }
        return nums;
    }
};
int main()
{
    vector<int> v = {2, 7, 11, 15};
    vector<int> v2 = Solution().twoSum(v, 9);
    cout << v2.at(0) << endl;
    cout << v2.at(1) << endl;
    return 0;
}