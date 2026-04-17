#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int reverseNum(int x) {
    int y = 0;
    while (x > 0) {
      y = y * 10 + (x % 10);
      x /= 10;
    }
    return y;
  }

  int minMirrorPairDistance(vector<int> &nums) {
    unordered_map<int, int> pos;
    int n = nums.size();
    int ans = n + 1;

    for (int i = 0; i < n; i++) {
      if (pos.count(nums[i])) {
        ans = min(ans, i - pos[nums[i]]);
      }
      int rev = reverseNum(nums[i]);
      pos[rev] = i;
    }

    return (ans > n) ? -1 : ans;
  }
};

int main() { return 0; }
