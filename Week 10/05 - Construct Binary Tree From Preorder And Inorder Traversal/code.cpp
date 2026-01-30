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
    unordered_map<int, int> inorderMap;
    int preIndex;

    TreeNode *buildTreeHelper(vector<int> &preorder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int rootValue = preorder[preIndex++];
        TreeNode *root = new TreeNode(rootValue);
        int mid = inorderMap[rootValue];
        root->left = buildTreeHelper(preorder, left, mid - 1);
        root->right = buildTreeHelper(preorder, mid + 1, right);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        preIndex = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, inorder.size() - 1);
    }
};

int main()
{
    return 0;
}
