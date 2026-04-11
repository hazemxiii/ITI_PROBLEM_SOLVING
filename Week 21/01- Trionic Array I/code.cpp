#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool isTrionic(vector<int> &nums) {
    int n = nums.size();
    bool inc_1 = false, dec = false, inc_2 = false;
    for (int i = 1; i < n; i++) {
      if (nums[i] == nums[i - 1])
        return false;
      if (nums[i] < nums[i - 1]) {
        if (!inc_1)
          return false;
        if (inc_2)
          return false;
        dec = true;
      } else {
        inc_1 = true;
        if (dec) {
          inc_2 = true;
        }
      }
    }
    return inc_1 && inc_2 && dec;
  }
};

int main() { return 0; }
