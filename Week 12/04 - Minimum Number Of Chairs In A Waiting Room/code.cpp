#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumChairs(string s)
    {
        int ppl = 0;
        int maxppl = ppl;
        ;
        for (char &c : s)
        {
            if (c == 'E')
            {
                maxppl = max(maxppl, ++ppl);
            }
            else
            {
                ppl--;
            }
        }
        return maxppl;
    }
};

int main()
{
    return 0;
}
