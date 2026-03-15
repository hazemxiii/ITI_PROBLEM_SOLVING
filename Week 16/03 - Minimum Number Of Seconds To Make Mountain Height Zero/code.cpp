#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {
        long long left = 1, right = 1e16;

        auto can = [&](long long t)
        {
            long long total = 0;

            for (long long w : workerTimes)
            {
                long long x = (long long)(sqrt((2.0 * t) / w + 0.25) - 0.5);
                total += x;
                if (total >= mountainHeight)
                    return true;
            }

            return total >= mountainHeight;
        };

        while (left < right)
        {
            long long mid = (left + right) / 2;

            if (can(mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main()
{
    return 0;
}
