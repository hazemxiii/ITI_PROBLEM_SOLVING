#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int i = digits.size() - 1;
        int carry = 1;
        while (i >= 0)
        {
            digits[i] += carry;
            if (digits[i] <= 9)
            {
                carry = 0;
            }
            else
            {
                carry = (digits[i] - (digits[i] % 10)) / 10;
                digits[i] %= 10;
            }
            i--;
            if (i == -1 && carry != 0)
            {
                digits.insert(digits.begin(), carry);
            }
        }
        return digits;
    }
};

int main()
{
    cout << (15 % 10) / 1;
    return 0;
}