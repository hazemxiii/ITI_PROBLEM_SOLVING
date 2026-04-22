#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> twoEditWords(vector<string> &queries,
                              vector<string> &dictionary) {

    vector<string> out;

    for (string &q : queries) {
      int found;
      for (string &d : dictionary) {
        found = true;
        int edits = 0;
        int s = q.size();
        if (s != d.size()) {
          continue;
        }
        for (int i = 0; i < s; i++) {
          if (q[i] != d[i]) {
            edits++;
            if (edits > 2) {
              found = false;
              break;
            }
          }
        }
        if (found)
          break;
      }
      if (found) {
        out.push_back(q);
      }
    }

    return out;
  }
};

int main() { return 0; }
