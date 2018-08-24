#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root, 0);
    }
private:
    int sum(TreeNode* root, int flag)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (flag == 0)
        {
            return sum(root->left, -1) + sum(root->right, 1);
        }
        else if (flag == -1)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return root->val;
            }
            else
            {
                return sum(root->left, -1) + sum(root->right, 1);
            }
        }
        else
        {
            return sum(root->left, -1) + sum(root->right, 1);
        }
    }
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
