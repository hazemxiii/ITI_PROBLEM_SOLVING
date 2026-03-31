#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkStrings(string s1, string s2)
    {
        int s = s1.size();
        if (s2.size() != s)
        {
            return false;
        }
        if (s == 1)
        {
            return s1[0] == s2[0];
        }
        for (int i = 0; i < s; i++)
        {
            if (s1[i] != s2[i])
            {
                bool swapped = false;
                for (int j = i + 2; j < s; j += 2)
                {
                    if (s1[j] == s2[i])
                    {
                        swap(s1[j], s1[i]);
                        swapped = true;
                        break;
                    }
                }
                if (!swapped)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
