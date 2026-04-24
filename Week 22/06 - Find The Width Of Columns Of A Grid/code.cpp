#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findColumnWidth(vector<vector<int>> &grid) {
    int n = grid[0].size();
    vector<int> out(n, 0);

    for (auto &row : grid) {
      for (int j = 0; j < n; j++) {
        int len = to_string(row[j]).length();
        out[j] = max(out[j], len);
      }
    }

    return out;
  }
};

int main() { return 0; }
