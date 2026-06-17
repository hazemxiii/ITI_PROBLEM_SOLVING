#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool isCovered(vector<vector<int>> &ranges, int left, int right) {
    vector<int> difference(53, 0);

    for (auto &r : ranges) {
      difference[r[0]]++;
      difference[r[1] + 1]--;
    }

    int current = 0;

    for (int i = 1; i <= 50; i++) {
      current += difference[i];

      if (i >= left && i <= right && current == 0)
        return false;
    }

    return true;
  }
};

int main() { return 0; }
