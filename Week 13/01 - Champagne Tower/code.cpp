#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1, 0.0));

        dp[0][0] = poured;

        for (int r = 0; r < query_row; ++r)
        {
            for (int c = 0; c <= r; ++c)
            {
                if (dp[r][c] > 1.0)
                {
                    double overflow = (dp[r][c] - 1.0) / 2.0;
                    dp[r + 1][c] += overflow;
                    dp[r + 1][c + 1] += overflow;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};

int main()
{
    return 0;
}

/*
         x             24
        x x            22
       x x x           19
      x x x x          15
     x x x x x         10
    x x x x x x        4
   x x x x x x x       0
*/
