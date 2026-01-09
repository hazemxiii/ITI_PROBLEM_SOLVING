#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<pair<int, int>> temps;
        int s = temperatures.size();
        vector<int> out(s, 0);
        for (int i = 0; i < s; i++)
        {
            pair<int, int> newVal = {temperatures[i], i};
            if (i != 0)
            {
                pair<int, int> back = temps.back();
                while (temperatures[i] > back.first)
                {
                    out[back.second] = (i - back.second);
                    temps.pop_back();
                    if (temps.empty())
                    {
                        break;
                    }
                    back = temps.back();
                }
            }
            temps.push_back(newVal);
        }
        return out;
    }
};

int main()
{
    vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution().dailyTemperatures(v);
    return 0;
}