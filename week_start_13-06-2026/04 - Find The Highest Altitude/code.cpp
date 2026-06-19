#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int current = 0, max_altitude = 0;
    for (int &g : gain) {
      current += g;
      max_altitude = max(max_altitude, current);
    }
    return max_altitude;
  }
};

int main() { return 0; }
