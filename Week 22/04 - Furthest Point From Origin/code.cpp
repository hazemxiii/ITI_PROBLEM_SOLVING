#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
  int furthestDistanceFromOrigin(string moves) {
    int distance = 0;
    int wild = 0;
    for (char &c : moves) {
      if (c == 'L') {
        distance--;
      } else if (c == 'R') {
        distance++;
      } else {
        wild++;
      }
    }
    return max(abs(distance - wild), abs(distance + wild));
  }
};

int main() { return 0; }
