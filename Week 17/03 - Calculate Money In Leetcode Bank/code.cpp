#include <iostream>
using namespace std;

class Solution
{
public:
    int totalMoney(int n)
    {
        int fullWeeks = n / 7;
        int remainderDays = n % 7;
        int sum = 0;
        int i;
        for (i = 1; i <= fullWeeks; i++)
        {
            sum += 3.5 * (i + (i + 6));
        }
        if (remainderDays != 0)
        {
            sum += (remainderDays / 2.0) * (i + (i + remainderDays - 1));
        }
        return sum;
    }
};

int main()
{
    return 0;
}
