#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        int s = strs.size();
        if (s == 0)
        {
            return "%13";
        }
        string out;
        for (int i = 0; i < s; i++)
        {
            out.append(strs[i]);
            if (i != s - 1)
            {
                out.append("%13");
            }
        }
        return out;
    }

    vector<string> decode(string s)
    {
        vector<string> out;
        if (s.compare("%13") == 0)
        {
            return out;
        }
        int size = s.size();
        out.push_back("");
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '%' && i + 2 < size)
            {
                if (s[i + 1] == '1' && s[i + 2] == '3')
                {
                    cout << "Word found\n";
                    out.push_back("");
                    i = i + 3;
                }
            }
            if (i < size)
            {
                out.back().push_back(s[i]);
            }
        }
        return out;
    }
};

int main()
{
    vector<string> v = {"hello", "world", "hello"};
    string s = Solution().encode(v);
    vector<string> vv = Solution().decode(s);
    for (string ss : vv)
    {
        cout << ss << endl;
    }
    return 0;
}
