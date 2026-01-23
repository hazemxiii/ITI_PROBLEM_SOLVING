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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> out;
        if (!root)
        {
            return out;
        }
        TreeNode *lastAtLevel = root;
        vector<TreeNode *> bfs = {root};
        out.push_back({});
        while (!bfs.empty())
        {
            TreeNode *n = bfs.front();
            bfs.erase(bfs.begin());
            out.back().push_back(n->val);
            if (n->left)
            {
                bfs.push_back(n->left);
            }
            if (n->right)
            {
                bfs.push_back(n->right);
            }
            if (n == lastAtLevel && !bfs.empty())
            {
                out.push_back({});
                lastAtLevel = bfs.back();
            }
        }
        return out;
    }
};

int main()
{
    return 0;
}
