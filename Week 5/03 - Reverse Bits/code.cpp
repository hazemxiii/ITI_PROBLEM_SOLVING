#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int reverseBits(int n)
    {
        int reversed = 0;
        for (int i = 0; i <= 31; i++)
        {
            if (n & 1)
            {
                reversed += pow(2, 31 - i);
            }
            n = n >> 1;
        }
        return reversed;
    }
};

int main()
{
    return 0;
}