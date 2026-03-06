#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        int s_len = s.size();
        bool ones = true;
        for (int i = 1; i < s_len; i++)
        {
            if (s[i] == '1')
            {
                if (!ones)
                {
                    return false;
                }
            }
            else
            {
                ones = false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
