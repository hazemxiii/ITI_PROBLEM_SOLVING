#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int size = s.length();
        int start = 0;
        int end = size - 1;
        char startC;
        char endC;

        while (start <= end)
        {
            startC = s.at(start);
            endC = s.at(end);
            if (startC <= 'Z' && startC >= 'A')
            {
                startC += 'a' - 'A';
            }
            if (endC <= 'Z' && endC >= 'A')
            {
                endC += 'a' - 'A';
            }
            while ((startC < 'a' || startC > 'z') && (startC < '0' || startC > '9'))
            {
                start++;
                if (start >= size)
                {
                    return 1;
                }
                startC = s.at(start);
                if (startC <= 'Z' && startC >= 'A')
                {
                    startC += 'a' - 'A';
                }
            }
            if (start >= end)
                return 1;
            while ((endC < 'a' || endC > 'z') && (endC < '0' || endC > '9'))
            {
                end--;
                if (end < 0)
                {
                    return 1;
                }
                endC = s.at(end);
                if (endC <= 'Z' && endC >= 'A')
                {
                    endC += 'a' - 'A';
                }
            }
            if (start >= end)
                return 1;

            if (startC != endC)
                return 0;

            start++;
            end--;
        }

        return 1;
    }
};