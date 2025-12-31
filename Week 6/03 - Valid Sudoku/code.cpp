#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool sub[9][9] = {false};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = board[i][j];
                if (ch != '.')
                {
                    int num = ch - '1';
                    int subI = (i / 3) * 3 + (j / 3);
                    if (row[i][num] || col[j][num] || sub[subI][num])
                    {
                        return false;
                    }
                    row[i][num] = true;
                    col[j][num] = true;
                    sub[subI][num] = true;
                }
            }
        }

        return true;
    }
    bool isValidSudokuAnotherAnswer(vector<vector<char>> &board)
    {
        unordered_set<int> rows;
        unordered_set<int> cols;
        unordered_set<int> sub[3][3];
        for (int i = 0; i < 9; i++)
        {
            rows.clear();
            cols.clear();
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int r = board[i][j] - '0';
                    if (!rows.insert(r).second || !sub[i / 3][j / 3].insert(r).second)
                    {
                        return 0;
                    }
                }
                if (board[j][i] != '.')
                {
                    int r = board[j][i] - '0';
                    if (!cols.insert(r).second)
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
};

int main()
{
    return 0;
}
