#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumAmount(vector<vector<int>> &coins)
    {
        int n = coins.size();
        int m = coins[0].size();

        const int NEG_INF = -1e9;
        vector<vector<vector<int>>> costs(n, vector<vector<int>>(m, vector<int>(3, NEG_INF)));
        if (coins[0][0] >= 0)
        {
            costs[0][0][0] = costs[0][0][1] = costs[0][0][2] = coins[0][0];
        }
        else
        {
            costs[0][0][0] = coins[0][0];
            costs[0][0][1] = 0;
            costs[0][0][2] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0) continue;

                int val = coins[i][j];

                for (int k = 0; k < 3; k++)
                {
                    int from_up = (i > 0) ? costs[i - 1][j][k] : NEG_INF;
                    int from_left = (j > 0) ? costs[i][j - 1][k] : NEG_INF;
                    int max_prev = max(from_up, from_left);
                    if (max_prev == NEG_INF) continue;
                    costs[i][j][k] = max(costs[i][j][k], max_prev + val);
                    if (val < 0 && k > 0)
                    {
                        int from_up_prev = (i > 0) ? costs[i - 1][j][k - 1] : NEG_INF;
                        int from_left_prev = (j > 0) ? costs[i][j - 1][k - 1] : NEG_INF;
                        int max_prev_skip = max(from_up_prev, from_left_prev);
                        if (max_prev_skip != NEG_INF)
                        {
                            costs[i][j][k] = max(costs[i][j][k], max_prev_skip);
                        }
                    }
                }
            }
        }

        return max({costs[n - 1][m - 1][0],
                    costs[n - 1][m - 1][1],
                    costs[n - 1][m - 1][2]});
    }
};

int main()
{
    return 0;
}
/*

-7,12,12,13
-6,19,19,-6
9,-2,-10,16
-4,14,-10,-9
*/