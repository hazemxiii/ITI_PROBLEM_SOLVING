#include <iostream>
using namespace std;

class Solution
{
public:
    int minPartitions(string n)
    {
        int maxx = 0;
        for (char c : n)
        {
            maxx = max(maxx, c - '0');
            if (maxx == 9)
            {
                break;
            }
        }
        return maxx;
    }
};

int main()
{
    return 0;
}
