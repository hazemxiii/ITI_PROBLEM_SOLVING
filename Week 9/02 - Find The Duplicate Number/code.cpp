#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int s = nums.size();
        int *occ = new int[s];
        for (int &i : nums)
        {
            if (occ[i] == 13)
            {
                s = i;
                break;
            }
            else
            {
                occ[i] = 13;
            }
        }
        delete[] occ;
        return s;
    }
};

int main()
{
    return 0;
}
