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
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        TreeNode *temp;
        TreeNode *last;
        vector<TreeNode *> v = {root};
        while (v.size() != 0)
        {
            last = v.back();
            if (last != nullptr)
            {
                temp = last->left;
                last->left = last->right;
                last->right = temp;
                v.pop_back();
                v.push_back(last->left);
                v.push_back(last->right);
            }
            else
            {
                v.pop_back();
            }
        }

        return root;
    }
};

int main()
{
    return 0;
}