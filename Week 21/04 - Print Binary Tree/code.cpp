#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<vector<string>> printTree(TreeNode *root) {
    int h = height(root);
    int rows = h + 1;
    int cols = (1 << (h + 1)) - 1;

    vector<vector<string>> res(rows, vector<string>(cols, ""));

    fill(root, res, 0, 0, cols - 1);
    return res;
  }

private:
  int height(TreeNode *root) {
    if (!root)
      return -1;
    return 1 + max(height(root->left), height(root->right));
  }

  void fill(TreeNode *node, vector<vector<string>> &res, int r, int l,
            int rBound) {
    if (!node)
      return;

    int mid = (l + rBound) / 2;
    res[r][mid] = to_string(node->val);

    fill(node->left, res, r + 1, l, mid - 1);
    fill(node->right, res, r + 1, mid + 1, rBound);
  }
};

int main() { return 0; }
