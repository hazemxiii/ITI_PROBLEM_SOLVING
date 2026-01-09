#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }

        vector<int> s1C(26, 0), window(26, 0);

        for (char c : s1)
        {
            s1C[c - 'a']++;
        }

        int left = 0, right = 0, charsLeft = s1.size();

        while (right < s2.size())
        {
            char c = s2[right++];
            if (s1C[c - 'a'] > 0)
            {
                if (window[c - 'a'] < s1C[c - 'a'])
                {
                    charsLeft--;
                }
                window[c - 'a']++;
            }

            if (right - left == s1.size())
            {
                if (charsLeft == 0)
                {
                    return true;
                }

                char d = s2[left++];
                if (s1C[d - 'a'] > 0)
                {
                    if (window[d - 'a'] <= s1C[d - 'a'])
                    {
                        charsLeft++;
                    }
                    window[d - 'a']--;
                }
            }
        }
        return false;
    }
};

int main()
{
    cout << Solution().checkInclusion("aba", "eidbaooo");
    return 0;
}
