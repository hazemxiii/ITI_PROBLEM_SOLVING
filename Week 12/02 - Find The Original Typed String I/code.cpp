#include <iostream>
using namespace std;

class Solution
{
public:
    int possibleStringCount(string word)
    {
        int n = 1;
        int s = word.size();
        for (int i = 1; i < s; i++)
        {
            if (word[i] == word[i - 1])
            {
                n++;
            }
        }
        return n;
    }
};

int main()
{
    return 0;
}
