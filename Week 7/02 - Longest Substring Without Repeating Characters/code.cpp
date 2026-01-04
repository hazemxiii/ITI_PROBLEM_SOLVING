#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() < 2)
        {
            return s.length();
        }
        unordered_map<char, int> occ;
        int startIndex = 0;
        int endIndex = 0;
        int tempStart = 0;
        int tempEnd = 0;
        int i = 0;
        for (char c : s)
        {
            bool found = false;
            if (occ.find(c) != occ.end())
            {
                if (occ[c] >= tempStart)
                {
                    found = true;
                }
            }
            if (found)
            {
                if ((tempEnd - tempStart) > (endIndex - startIndex))
                {
                    endIndex = tempEnd;
                    startIndex = tempStart;
                }
                tempEnd = i;
                tempStart = occ[c] + 1;
                occ[c] = i;
            }
            else
            {
                occ[c] = i;
                tempEnd = i;
            }
            i++;
        }
        return max(tempEnd - tempStart, endIndex - startIndex) + 1;
    }
};

int main()
{
    cout << Solution().lengthOfLongestSubstring("abba");
    return 0;
}