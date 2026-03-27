#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int rows_n = mat.size();
        int cols_n = mat[0].size();
        for (int i = 0; i < rows_n; i++)
        {
            for (int j = 0; j < cols_n; j++)
            {
                if ((i % 2) == 0)
                {
                    int new_i = (j + k) % cols_n;
                    if (mat[i][new_i] != mat[i][j])
                    {
                        return false;
                    }
                }
                else
                {
                    int new_i = (j - k) % cols_n;
                    if (new_i < 0)
                    {
                        new_i = cols_n - (abs(new_i) % cols_n);
                    }
                    if (mat[i][new_i] != mat[i][j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
