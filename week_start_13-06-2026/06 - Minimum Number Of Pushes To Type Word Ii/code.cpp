#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumPushes(string word) {
    vector<int> occurence(26, 0);

    for (char c : word)
      occurence[c - 'a']++;

    sort(occurence.begin(), occurence.end(), greater<int>());

    long long out = 0;

    for (int i = 0; i < 26; i++) {
      if (occurence[i] == 0)
        break;

      int click = i / 8 + 1;
      out += 1LL * occurence[i] * click;
    }

    return (int)out;
  }
};

int main() { return 0; }
