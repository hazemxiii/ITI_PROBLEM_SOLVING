#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int s = mat.size();
        bool _0 = true;
        bool _90 = true;
        bool _180 = true;
        bool _270 = true;
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < s; j++)
            {
                if (mat[i][j] != target[i][j])
                {
                    _0 = false;
                }
                if (target[i][j] != mat[s - j - 1][i])
                {
                    _90 = false;
                }
                if (target[i][j] != mat[s - i - 1][s - j - 1])
                {
                    _180 = false;
                }
                if (target[i][j] != mat[j][s - i - 1])
                {
                    _270 = false;
                }
                if (!_0 && !_90 && !_180 && !_270)
                {
                    return false;
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
