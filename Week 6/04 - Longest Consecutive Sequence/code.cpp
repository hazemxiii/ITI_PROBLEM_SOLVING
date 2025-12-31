#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> nums_unique;
        for (int n : nums)
        {
            nums_unique[n] = -1;
        }
        int len = 0;
        int lenTemp = 0;
        int tempN;
        auto end = nums_unique.end();
        for (auto [k, v] : nums_unique)
        {
            if (nums_unique[k] == -1)
            {
                lenTemp = 1;
                tempN = k + 1;
                while (nums_unique.find(tempN) != end)
                {
                    lenTemp++;
                    nums_unique[tempN] = 1;
                    tempN++;
                }
                tempN = k - 1;
                while (nums_unique.find(tempN) != end)
                {
                    lenTemp++;
                    nums_unique[tempN] = 1;
                    tempN--;
                }
            }
            if (lenTemp > len)
            {
                len = lenTemp;
            }
        }
        return len;
    }
};

int main()
{
    return 0;
}
