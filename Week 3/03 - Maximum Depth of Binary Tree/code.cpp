#include <iostream>
#include <vector>
#include <cmath>
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
    int maxDepth(TreeNode *root)
    {
        return maxDepthR(root, 0);
    }

    int maxDepthR(TreeNode *root, int depth)
    {
        if (root == nullptr)
            return depth;

        return max(maxDepthR(root->left, depth + 1), maxDepthR(root->right, depth + 1));
    }
};

int main()
{
    return 0;
}