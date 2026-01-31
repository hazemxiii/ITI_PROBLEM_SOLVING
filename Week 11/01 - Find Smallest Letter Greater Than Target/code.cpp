#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int letter = -1;
        for (char c : letters)
        {
            if (c > target && (letter == -1 || c < letter))
            {
                letter = c;
            }
        }
        return letter == -1 ? letters[0] : letter;
    }
};

int main()
{
    return 0;
}
