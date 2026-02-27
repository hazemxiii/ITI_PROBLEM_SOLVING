#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        int evenCount = 0, oddCount = 0;
        int altLen = 0;

        int prevParity = -1;

        for (int num : nums)
        {
            int parity = num % 2;

            if (parity == 0)
                evenCount++;
            else
                oddCount++;

            if (parity != prevParity)
            {
                altLen++;
                prevParity = parity;
            }
        }

        return max({evenCount, oddCount, altLen});
    }
};

int main()
{
    return 0;
}
