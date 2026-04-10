#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumDistance(vector<int> &nums) {
    int n = nums.size();
    int distance = -1;
    int newDistance;
    unordered_map<int, vector<int>> occ;
    for (int i = 0; i < n; i++) {
      if (occ.find(nums[i]) == occ.end()) {
        occ[nums[i]] = {};
      }
      occ[nums[i]].push_back(i);
    }

    for (auto &[key, val] : occ) {
      int s = val.size();
      if (s >= 3) {
        for (int i = 0; i < s - 2; i++) {
          newDistance = abs(val[i] - val[i + 1]) + abs(val[i] - val[i + 2]) +
                        abs(val[i + 2] - val[i + 1]);
          if (distance == -1 || newDistance < distance) {
            distance = newDistance;
          }
        }
      }
    }
    return distance;
  }
};

int main() { return 0; }
