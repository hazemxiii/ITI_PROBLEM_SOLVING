#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int s = arr.size();
        int o = 1;
        int newN;
        int last = arr.at(0);
        float p = 0.25 * s;
        for (int i = 1; i < s; i++)
        {
            newN = arr.at(i);
            if (newN != last)
            {
                o = 1;
                last = newN;
            }
            else if (++o > p)
            {
                return last;
            }
        }
        return last;
    }
};

int main()
{
    return 0;
}