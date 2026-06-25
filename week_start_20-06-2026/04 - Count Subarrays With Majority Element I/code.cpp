#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();
    int out = 0;

    for (int l = 0; l < n; l++) {
      int count = 0;

      for (int r = l; r < n; r++) {
        if (nums[r] == target)
          count++;

        int len = r - l + 1;
        if (2 * count > len) {
          out++;
        }
      }
    }

    return out;
  }
};

int main() { return 0; }
