#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int pairSum(ListNode *head) {
    int n = 0;
    ListNode *node = head;
    vector<int> v;
    while (node != nullptr) {
      v.push_back(node->val);
      n++;
      node = node->next;
    }
    int i_end = n / 2 - 1;
    int max_sum = 0;
    for (int i = 0; i <= i_end; i++) {
      max_sum = max(max_sum, (v.at(i) + v.at(n - i - 1)));
    }
    return max_sum;
  }
};

int main() { return 0; }
