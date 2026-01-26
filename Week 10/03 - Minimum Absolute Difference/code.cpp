#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int s = arr.size();
        int minD = abs(arr[0] - arr[1]);
        for (int i = 1; i < s - 1; i++)
        {
            int a = abs(arr[i] - arr[i + 1]);
            if (a < minD)
            {
                minD = a;
            }
        }
        vector<vector<int>> out;
        for (int i = 0; i < s - 1; i++)
        {
            if (abs(arr[i] - arr[i + 1]) == minD)
            {
                out.push_back({arr[i], arr[i + 1]});
            }
        }
        return out;
    }
};

int main()
{
    return 0;
}
