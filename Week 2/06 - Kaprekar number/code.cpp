#include <iostream>
#include <string>

using namespace std;
void kaprekarNumbers(int p, int q)
{
    string ns;
    int left;
    int right;
    int d;
    int sLen;
    bool found = 0;
    for (int n = p; n <= q; n++)
    {
        d = to_string(n).length();
        ns = to_string((long long)n * n);
        sLen = ns.length();
        right = stoi(ns.substr(sLen - d));
        left = 0;
        if (sLen != d)
        {
            left = stoi(ns.substr(0, sLen - d));
        }
        if (left + right == n)
        {
            found = 1;
            cout << n << " ";
        }
    }
    if (!found)
    {
        cout << "INVALID RANGE";
    }
}

int main()
{
    return 0;
}
