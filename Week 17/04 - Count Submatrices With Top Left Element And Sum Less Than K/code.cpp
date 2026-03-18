#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int rows_n = grid.size();
        int cols_n = grid[0].size();

        vector<vector<long long>> prefix(rows_n, vector<long long>(cols_n, 0));
        int count = 0;

        for (int i = 0; i < rows_n; i++)
        {
            for (int j = 0; j < cols_n; j++)
            {
                prefix[i][j] = grid[i][j];

                if (i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];

                if (prefix[i][j] <= k)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    return 0;
}
