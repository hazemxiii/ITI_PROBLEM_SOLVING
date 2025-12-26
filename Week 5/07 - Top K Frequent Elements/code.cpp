#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(const pair<int, int> &a,
                    const pair<int, int> &b)
    {
        return a.second < b.second;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxHeap;
        unordered_map<int, int>
            occ;
        vector<int> out;
        for (int &n : nums)
        {
            occ[n]++;
        }
        for (auto [n, o] : occ)
        {
            maxHeap.push({n, o});
        }
        for (int i = 0; i < k; i++)
        {
            out.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return out;
    }
};

int main()
{
    return 0;
}
