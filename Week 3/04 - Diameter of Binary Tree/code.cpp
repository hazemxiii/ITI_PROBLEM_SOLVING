#include <iostream>
#include <vector>
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
    int mm = 0;

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        getMax(root);
        return mm;
    }

    int getMax(TreeNode *r)
    {
        if (r == nullptr)
            return 0;

        int left = getMax(r->left);
        int right = getMax(r->right);

        mm = max(mm, left + right);

        return 1 + max(left, right);
    }
};

int main()
{
    return 0;
}