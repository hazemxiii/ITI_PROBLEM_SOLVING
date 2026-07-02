#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numOfStrings(vector<string> &patterns, string word) {
    int ans = 0;
    for (auto &s : patterns) {
      if (word.find(s) != string::npos)
        ans++;
    }
    return ans;
  }
};

int main() { return 0; }
