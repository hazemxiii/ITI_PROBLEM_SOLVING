#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minXor(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] ^ nums[i - 1];
        }

        const int INF = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= min(i, k); j++)
            {
                for (int h = j - 1; h < i; h++)
                {
                    int currXor = prefix[i] ^ prefix[h];
                    dp[i][j] = min(dp[i][j],
                                   max(dp[h][j - 1], currXor));
                }
            }
        }

        return dp[n][k];
    }
};

int main()
{
    return 0;
}
