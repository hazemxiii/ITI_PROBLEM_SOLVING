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
    bool out = 1;
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return 1;
        height(root);
        return out;
    }

    int height(TreeNode *r)
    {
        if (r == nullptr)
            return 0;

        int leftH = height(r->left);
        int rightH = height(r->right);

        if (abs(leftH - rightH) > 1)
        {
            out = 0;
        }

        return 1 + max(leftH, rightH);
    }
};

int main()
{
    return 0;
}
