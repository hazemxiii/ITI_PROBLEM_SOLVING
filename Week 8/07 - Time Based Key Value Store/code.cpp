#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
            return "";

        auto &arr = mp[key];

        int low = 0, high = arr.size() - 1;
        string answer = "";

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid].first == timestamp)
            {
                return arr[mid].second;
            }
            else if (arr[mid].first < timestamp)
            {
                answer = arr[mid].second;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return answer;
    }
};
int main()
{
    return 0;
}
