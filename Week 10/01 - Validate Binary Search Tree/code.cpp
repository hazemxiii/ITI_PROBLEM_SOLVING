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
    bool isValidBST(TreeNode *root)
    {
        vector<int> ordered;
        return isValidBSTR(root, ordered);
    }
    bool isValidBSTR(TreeNode *root, vector<int> &ordered)
    {
        if (!root)
        {
            return true;
        }
        if (!isValidBSTR(root->left, ordered))
        {
            return false;
        }
        bool out = false;
        if (ordered.empty())
        {
            ordered.push_back(root->val);
            out = true;
        }
        else if (root->val > ordered.back())
        {
            out = true;
        }
        ordered.push_back(root->val);
        return out && isValidBSTR(root->right, ordered);
    }
};

int main()
{
    return 0;
}
