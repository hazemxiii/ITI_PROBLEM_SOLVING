#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> v = {};
        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                v.push_back(c);
                break;
            case ')':
                if (v.size() == 0)
                {
                    return 0;
                }
                if ('(' != v.back())
                {
                    return 0;
                }
                v.pop_back();
                break;
            case ']':
                if (v.size() == 0)
                {
                    return 0;
                }
                if ('[' != v.back())
                {
                    return 0;
                }
                v.pop_back();
                break;
            case '}':
                if (v.size() == 0)
                {
                    return 0;
                }
                if ('{' != v.back())
                {
                    return 0;
                }
                v.pop_back();
                break;
            }
        }
        return v.size() == 0;
    }
};

int main()
{
    cout << Solution().isValid("([)]");
    // cout << (char)(']' - 1);
    return 0;
}