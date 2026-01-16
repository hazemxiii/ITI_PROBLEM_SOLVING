#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int right = matrix.size();
        if (right == 0)
        {
            return false;
        }
        int m = matrix[0].size();
        right = right * m - 1;
        int left = 0, mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            int num = matrix[mid / m][mid % m];
            if (num == target)
            {
                return true;
            }
            else if (num < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}
