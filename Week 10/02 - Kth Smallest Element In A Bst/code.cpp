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
    int k;
    vector<int> nums;
    int kthSmallest(TreeNode *root, int k)
    {
        this->k = k;
        r(root);
        return nums[k - 1];
    }
    void r(TreeNode *root)
    {

        if (!root || nums.size() >= k)
        {
            return;
        }
        r(root->left);
        nums.push_back(root->val);
        r(root->right);
    }
};

int main()
{
    return 0;
}
