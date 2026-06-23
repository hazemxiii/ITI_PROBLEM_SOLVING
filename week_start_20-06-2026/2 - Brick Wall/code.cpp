#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int leastBricks(vector<vector<int>> &wall) {
    int most = 0;
    unordered_map<int, int> frequency = {};
    for (vector<int> &bricks : wall) {
      long long curr_lengh = 0;
      int s = bricks.size();
      for (int i = 0; i < s - 1; i++) {
        curr_lengh += bricks[i];
        frequency[curr_lengh]++;
        most = max(frequency[curr_lengh], most);
      }
    }
    return wall.size() - most;
  }
};

int main() { return 0; }
