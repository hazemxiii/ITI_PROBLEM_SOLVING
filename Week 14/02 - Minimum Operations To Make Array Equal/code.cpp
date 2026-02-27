#include <iostream>
using namespace std;

class Solution
{
public:
    int minOperations(int n)
    {
        if (n % 2 == 0)
            return (n * n) / 4;
        else
            return (n * n - 1) / 4;
    }
};

int main()
{
    return 0;
}
