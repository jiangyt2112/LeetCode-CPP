#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return tree(inorder, postorder, 0, n, n);
    }

    TreeNode* tree(vector<int>& inorder, vector<int>& postorder, int s, int t, int index)
    {
        if (s == t)
        {
            return NULL;
        }
        int v = postorder[index - 1];
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
        root -> left = tree(inorder, postorder, s, pos, index - (t - pos));
        root -> right = tree(inorder, postorder, pos + 1, t, index - 1);
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
    int a[] = {4, 5, 2, 6, 3, 1};
    int b[] = {4, 2, 5, 1, 3, 6};
    vector<int> post(a, a + sizeof(a) / sizeof(int));
    vector<int> in(b, b + sizeof(b) / sizeof(int));
    TreeNode* root = s.buildTree(in, post);
    showTree(root);
    return 0;
}
