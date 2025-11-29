#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        long int i = 10;
        long rev = 0;
        while (x > rev)
        {
            int num = (x % i) / (i / 10);
            i *= 10;
            rev = rev * 10 + num;
        }
        return x == rev;
    }
};
int main()
{
    return 0;
}
