#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct distanceCalc
{
    bool operator()(const vector<int> &p1, const vector<int> &p2)
    {
        return sqrt(pow(p1[0], 2) + pow(p1[1], 2)) > sqrt(pow(p2[0], 2) + pow(p2[1], 2));
    }
};

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, distanceCalc> minHeap;
        for (vector<int> &point : points)
        {
            minHeap.push(point);
        }
        vector<vector<int>> out;
        for (int i = 0; i < k; i++)
        {
            out.push_back(minHeap.top());
            minHeap.pop();
        }
        return out;
    }
};

int main()
{
    return 0;
}
