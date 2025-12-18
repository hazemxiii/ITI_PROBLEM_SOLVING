#include <iostream>
#include <map>
#include <math.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        map<int, int> v;
        int sum = 0;
        while (sum != 1 && v.find(n) == v.end())
        {
            v[n] = 1;
            sum = 0;
            for (long long mod = 10; mod <= n * 10LL; mod *= 10)
            {
                sum += pow((n % mod) / (mod / 10), 2);
            }
            n = sum;
        }
        return sum == 1;
    }
};

int main()
{
    return 0;
}