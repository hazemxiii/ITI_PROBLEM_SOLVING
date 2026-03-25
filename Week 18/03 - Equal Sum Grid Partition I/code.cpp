#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int rows_s = grid.size();
        int cols_s = grid[0].size();
        vector<long long> rows_sum(rows_s, 0);
        vector<long long> cols_sum(cols_s, 0);

        for (int i = 0; i < rows_s; i++)
        {
            for (int j = 0; j < cols_s; j++)
            {
                rows_sum[i] += grid[i][j];
                cols_sum[j] += grid[i][j];
            }
        }
        int i = 0;
        int j = rows_s - 1;
        long long sum_i = 0;
        long long sum_j = 0;
        while (i <= j)
        {
            if (sum_j < sum_i)
            {
                sum_j += rows_sum[j];
                j--;
            }
            else
            {
                sum_i += rows_sum[i];
                i++;
            }
        }
        if (sum_i == sum_j)
        {
            return true;
        }
        i = 0;
        j = cols_s - 1;
        sum_i = 0;
        sum_j = 0;
        while (i <= j)
        {
            if (sum_j < sum_i)
            {
                sum_j += cols_sum[j];
                j--;
            }
            else
            {
                sum_i += cols_sum[i];
                i++;
            }
        }
        if (sum_i == sum_j)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}
