#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int s = numbers.size();
        int l;
        int r;
        int compI;
        vector<int> out;
        for (int i = 0; i < s; i++)
        {
            l = i;
            r = s - 1;
            int comp = target - numbers[i];
            while (l <= r)
            {
                compI = (l + r) / 2;
                if (numbers[compI] == comp)
                {
                    break;
                }
                if (numbers[compI] < comp)
                {
                    l = compI + 1;
                }
                else
                {
                    r = compI - 1;
                }
            }
            if (l <= r)
            {
                if (i == compI)
                {
                    if (compI + 1 < s)
                    {
                        if (numbers[compI + 1] == numbers[compI])
                        {
                            out.push_back(i + 1);
                            out.push_back(compI + 2);
                            break;
                        }
                    }
                }
                else
                {
                    out.push_back(i + 1);
                    out.push_back(compI + 1);
                    break;
                }
            }
        }
        return out;
    }
};

int main()
{
    return 0;
}
