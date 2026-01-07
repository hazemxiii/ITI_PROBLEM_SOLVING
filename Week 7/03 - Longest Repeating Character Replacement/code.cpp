#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> numCount(26, 0);
        int maxC = 0, left = 0, result = 0;

        for (int right = 0; right < s.size(); right++)
        {
            numCount[s[right] - 'A']++;
            maxC = max(maxC, numCount[s[right] - 'A']);
            if (right - left + 1 - maxC > k)
            {
                numCount[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution().characterReplacement("AABABBA", 1);
    return 0;
}
