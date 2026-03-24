#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        const int MOD = 12345;
        vector<vector<int>> ans(n, vector<int>(m));
        long long suf = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                ans[i][j] = suf;
                suf = (suf * grid[i][j]) % MOD;
            }
        }
        long long pre = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                ans[i][j] = (ans[i][j] * pre) % MOD;
                pre = (pre * grid[i][j]) % MOD;
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}
