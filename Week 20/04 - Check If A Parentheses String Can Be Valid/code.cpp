#include<iostream>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 == 1) return false;
        int minBraces = 0, maxBraces = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    minBraces++;
                    maxBraces++;
                } else {
                    minBraces--;
                    maxBraces--;
                }
            } else {
                minBraces--;
                maxBraces++;
            }

            if (maxBraces < 0) return false;
            if (minBraces < 0) minBraces = 0;
        }

        return minBraces == 0;
    }
};

int main()
{
return 0;
}