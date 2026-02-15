#include <iostream>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int as = a.size();
        int bs = b.size();
        int s = max(as, bs);
        string out = "";
        int carry = 0;

        for (int i = 0; i < s; i++)
        {
            int n1 = 0, n2 = 0;

            if (i < as)
                n1 = a[as - i - 1] - '0';
            if (i < bs)
                n2 = b[bs - i - 1] - '0';

            int sum = n1 + n2 + carry;
            out = char((sum % 2) + '0') + out;
            carry = sum / 2;
        }

        if (carry)
            out = '1' + out;
        return out;
    }
};

int main()
{
    return 0;
}
