#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxValue(vector<int> &nums) {
    int n = nums.size();

    vector<int> sufMin(n + 1, INT_MAX);
    for (int i = n - 1; i >= 0; i--)
      sufMin[i] = min(sufMin[i + 1], nums[i]);

    vector<int> ans(n);

    int prefMax = INT_MIN;
    int compMax = INT_MIN;
    int start = 0;

    for (int i = 0; i < n; i++) {
      prefMax = max(prefMax, nums[i]);
      compMax = max(compMax, nums[i]);

      if (prefMax <= sufMin[i + 1]) {
        for (int j = start; j <= i; j++)
          ans[j] = compMax;

        start = i + 1;
        compMax = INT_MIN;
      }
    }

    return ans;
  }
};

int main() { return 0; }
