#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfGoodSubarraySplits(vector<int> &nums) {
    const int MOD = 1e9 + 7;

    vector<int> pos;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1)
        pos.push_back(i);
    }

    if (pos.empty())
      return 0;

    long long ans = 1;

    for (int i = 1; i < pos.size(); i++) {
      ans = (ans * (pos[i] - pos[i - 1])) % MOD;
    }

    return (int)ans;
  }
};

int main() { return 0; }
