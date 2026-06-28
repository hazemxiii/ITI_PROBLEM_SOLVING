#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int s = arr.size();
    arr[0] = 1;
    for (int i = 1; i < s; i++) {
      if (arr[i] - arr[i - 1] > 1) {
        arr[i] = arr[i - 1] + 1;
      }
    }
    return arr[s - 1];
  }
};

int main() { return 0; }
