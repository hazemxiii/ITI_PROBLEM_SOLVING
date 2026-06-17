#include <iostream>
using namespace std;

class Solution {
public:
  bool between(int x, int y, int z) { return min(x, y) < z && z < max(x, y); }

  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {

    if (a == e) {
      bool blocked = (c == a && between(b, f, d));
      if (!blocked)
        return 1;
    }

    if (b == f) {
      bool blocked = (d == b && between(a, e, c));
      if (!blocked)
        return 1;
    }

    if (abs(c - e) == abs(d - f)) {
      bool blocked =
          abs(c - a) == abs(d - b) && between(c, e, a) && between(d, f, b);

      if (!blocked)
        return 1;
    }

    return 2;
  }
};

int main() { return 0; }
