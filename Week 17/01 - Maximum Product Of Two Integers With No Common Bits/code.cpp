#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long maxProduct(vector<int> &nums)
    {
        int mx = *max_element(nums.begin(), nums.end());

        int m = 1;
        while (m <= mx)
            m <<= 1;

        vector<int> present(m, 0);
        for (int x : nums)
            present[x] = 1;

        long long ans = 0;

        for (int i = m - 1; i > 0; i--)
        {
            if (!present[i])
                continue;

            int inv = (m - 1) ^ i;
            long long limit = ans / i;

            for (int sub = inv; sub > limit; sub = (sub - 1) & inv)
            {
                if (present[sub])
                {
                    ans = 1LL * i * sub;
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}
