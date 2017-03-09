#include <iostream>
#include <vector>

using namespace std;

/**/
// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return tree(preorder, inorder, 0, n, 0);
    }

    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int s, int t, int index)
    {
        if (s == t)
        {
            return NULL;
        }
        int v = preorder[index];
        int pos = -1;
        for (int i = s; i < t; i++)
        {
            if (inorder[i] == v)
            {
                pos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(v);
        root -> left = tree(preorder, inorder, s, pos, index + 1);
        root -> right = tree(preorder, inorder, pos + 1, t, index + 1 + pos - s);
        return root;
    }
};

void showTree(TreeNode* root)
{
    if (root == NULL)
    {
        return ;
    }
    cout << root -> val << " ";
    showTree(root -> left);
    showTree(root -> right);
}

int main()
{
    Solution s;
    int a[] = {1, 2, 4, 5, 3, 6};
    int b[] = {4, 2, 5, 1, 3, 6};
    vector<int> pre(a, a + sizeof(a) / sizeof(int));
    vector<int> in(b, b + sizeof(b) / sizeof(int));
    TreeNode* root = s.buildTree(pre, in);
    showTree(root);
    return 0;
}
