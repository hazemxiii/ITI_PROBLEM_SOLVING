#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries)
    {
        int m = logs.size(), q = queries.size();
        vector<int> ans(q);
        vector<int> idx(q);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b)
             { return queries[a] < queries[b]; });
        sort(logs.begin(), logs.end(), [&](auto &a, auto &b)
             { return a[1] < b[1]; });
        unordered_map<int, int> count;
        int left = 0, right = 0, active = 0;
        for (int id : idx)
        {
            int endT = queries[id];
            int startT = endT - x;
            while (right < m && logs[right][1] <= endT)
            {
                int sid = logs[right][0];
                if (count[sid]++ == 0)
                    active++;
                right++;
            }
            while (left < m && logs[left][1] < startT)
            {
                int sid = logs[left][0];
                if (--count[sid] == 0)
                    active--;
                left++;
            }
            ans[id] = n - active;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
