#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        int strs_size = strs.size();
        for (int i = 0; i < strs_size; i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        result.reserve(mp.size());
        for (auto &[key, group] : mp)
        {
            result.push_back(move(group));
        }

        return result;
    }
};

int main()
{
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution().groupAnagrams(v);
    return 0;
}
