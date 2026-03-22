#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long numberOfSubstrings(string s)
    {
        int n = s.size();
        vector<int> zeros;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                zeros.push_back(i);
        }

        long long ans = 0;
        int cnt = 0;
        for (char c : s)
        {
            if (c == '1')
                cnt++;
            else
            {
                ans += 1LL * cnt * (cnt + 1) / 2;
                cnt = 0;
            }
        }
        ans += 1LL * cnt * (cnt + 1) / 2;

        int m = zeros.size();
        for (int k = 1; k <= m; k++)
        {
            if (k * k > n)
                break;

            for (int i = 0; i + k - 1 < m; i++)
            {
                int leftZero = zeros[i];
                int rightZero = zeros[i + k - 1];

                int base_len = rightZero - leftZero + 1;
                int need_len = k * k + k;

                int extra = max(0, need_len - base_len);

                int prev = (i == 0 ? -1 : zeros[i - 1]);
                int next = (i + k == m ? n : zeros[i + k]);

                int leftChoices = leftZero - prev;
                int rightChoices = next - rightZero;

                for (int l = 0; l < leftChoices; l++)
                {
                    int min_r = max(0, extra - l);
                    if (min_r < rightChoices)
                    {
                        ans += (rightChoices - min_r);
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}
