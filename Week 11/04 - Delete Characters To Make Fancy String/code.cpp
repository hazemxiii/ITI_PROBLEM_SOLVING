#include <iostream>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        string out;
        int repeat = 0;
        char lastC = s[0];
        for (char c : s)
        {
            if (c == lastC)
            {
                repeat++;
            }
            else
            {
                repeat = 1;
            }
            lastC = c;
            if (repeat < 3)
            {
                out += c;
            }
        }
        return out;
    }
};

int main()
{
    return 0;
}
