#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int steps = 0;
        for (string &log : logs)
        {
            if (log == "../")
            {
                if (steps > 0)
                {
                    steps--;
                }
            }
            else if (log != "./")
            {
                steps++;
            }
        }
        return steps;
    }
};

int main()
{
    return 0;
}
