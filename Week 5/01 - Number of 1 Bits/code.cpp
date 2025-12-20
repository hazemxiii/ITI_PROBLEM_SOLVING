#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
public:
    int hammingWeight(int n)
    {
        unsigned int num = 0;
        int sum = 0;
        while (num <= n)
        {
            if ((num & n))
            {
                sum++;
            }
            num = (!num ? 0.5 : num) * 2;
        }
        return sum;
    }
};

int main()
{
    return 0;
}