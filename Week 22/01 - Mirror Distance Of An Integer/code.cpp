#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
  int mirrorDistance(int n) {
    if (n < 10)
      return 0;
    long long modStop = 1L * n * 10;
    long long reverse = 0;
    for (long long mod = 10; mod <= modStop; mod *= 10) {
      reverse = reverse * 10 + (n % mod / (mod / 10));
    }
    return abs(n - reverse);
  }
};

int main() {
  Solution().mirrorDistance(10);
  return 0;
}
