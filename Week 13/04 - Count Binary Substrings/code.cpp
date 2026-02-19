#include <iostream>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int s_len = s.size();
        if (s_len <= 1)
        {
            return 0;
        }
        int out = 0;
        int current = s[0];
        int current_repeated = 1;
        for (int i = 1; i < s_len; i++)
        {
            if (s[i] == current)
            {
                current_repeated++;
            }
            else
            {
                int j = 0;
                while (s[i + j] != current && current_repeated > 0)
                {
                    out++;
                    current_repeated--;
                    j++;
                    if (i + j >= s_len)
                    {
                        break;
                    }
                }
                current_repeated = 1;
                current = s[i];
            }
        }
        return out;
    }
};

int main()
{
    return 0;
}
