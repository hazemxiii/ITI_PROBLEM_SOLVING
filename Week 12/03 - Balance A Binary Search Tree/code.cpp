#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &vals)
    {
        if (!root)
            return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
    TreeNode *buildBalanced(vector<int> &vals, int l, int r)
    {
        if (l > r)
            return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(vals[mid]);
        node->left = buildBalanced(vals, l, mid - 1);
        node->right = buildBalanced(vals, mid + 1, r);
        return node;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> vals;
        inorder(root, vals);
        return buildBalanced(vals, 0, (int)vals.size() - 1);
    }
};

int main()
{
    return 0;
}
