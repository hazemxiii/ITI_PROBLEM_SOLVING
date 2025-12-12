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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> v1 = {p};
        vector<TreeNode *> v2 = {q};
        while (v1.size() != 0)
        {
            p = v1.back();
            q = v2.back();
            v1.pop_back();
            v2.pop_back();

            if (p && q)
            {
                if (p->val != q->val)
                {
                    return 0;
                }
                v1.push_back(p->left);
                v1.push_back(p->right);
                v2.push_back(q->left);
                v2.push_back(q->right);
            }
            else if (!p && !q)
            {
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    return 0;
}