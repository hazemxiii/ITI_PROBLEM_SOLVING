#include <iostream>
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
    int goodNodes(TreeNode *root)
    {
        return goodNodesR(root, root->val);
    }
    int goodNodesR(TreeNode *root, int maxBefore)
    {
        if (!root)
        {
            return 0;
        }
        if (root->val >= maxBefore)
        {
            return goodNodesR(root->left, root->val) + goodNodesR(root->right, root->val) + 1;
        }
        return goodNodesR(root->left, maxBefore) + goodNodesR(root->right, maxBefore);
    }
};

int main()
{
    return 0;
}
