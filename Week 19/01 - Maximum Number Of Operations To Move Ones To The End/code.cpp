#include <iostream>
using namespace std;

class Solution
{
public:
    int maxOperations(string s)
    {
        int out = 0;
        int count = 0;
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '1')
            {
                count++;
            }
            else if (i > 0 && s[i - 1] == '1')
            {
                out += count;
            }
        }
        return out;
    }
};

int main()
{
    return 0;
}
