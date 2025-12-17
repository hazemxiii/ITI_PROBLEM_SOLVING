#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

static const int MOD = 1000000007;
class Solution
{

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<long long> numTillI(n + 1, 0), sumTillI(n + 1, 0), countTillI(n + 1, 0), powers(n + 1);
        powers[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            powers[i] = (powers[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++)
        {
            numTillI[i + 1] = numTillI[i];
            sumTillI[i + 1] = sumTillI[i];
            countTillI[i + 1] = countTillI[i];
            int d = s[i] - '0';
            if (d != 0)
            {
                numTillI[i + 1] = (numTillI[i] * 10 + d) % MOD;
                sumTillI[i + 1] += d;
                countTillI[i + 1]++;
            }
        }

        int qs = queries.size();
        vector<int> ans(qs, 0);

        for (int i = 0; i < qs; i++)
        {
            int l = queries[i][0], r = queries[i][1];

            long long sumDigits = sumTillI[r + 1] - sumTillI[l];

            if (sumDigits == 0)
            {
                ans[i] = 0;
                continue;
            }

            int len = countTillI[r + 1] - countTillI[l];
            long long val = (numTillI[r + 1] - (numTillI[l] * powers[len]) % MOD + MOD) % MOD;
            long long res = (val * (sumDigits % MOD)) % MOD;
            ans[i] = (int)res;
        }
        return ans;
    }
};

int main()
{
    return 0;
}