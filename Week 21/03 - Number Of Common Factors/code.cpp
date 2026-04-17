#include <iostream>

using namespace std;

class Solution {
public:
  int commonFactors(int a, int b) {
    int g = gcd(a, b);
    int count = 0;

    for (int i = 1; i <= g; i++) {
      if (g % i == 0) {
        count++;
      }
    }

    return count;
  }

  int gcd(int a, int b) {
    while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }
};

int main() { return 0; }
