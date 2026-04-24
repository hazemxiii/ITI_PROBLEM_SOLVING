#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    vector<bool> seen(k + 1, false);
    int left = k;
    int operations = 0;

    for (int i = nums.size() - 1; i >= 0; i--) {
      operations++;

      if (nums[i] <= k && !seen[nums[i]]) {
        seen[nums[i]] = true;
        left--;
      }

      if (left == 0) {
        return operations;
      }
    }

    return operations;
  }
};

int main() { return 0; }
