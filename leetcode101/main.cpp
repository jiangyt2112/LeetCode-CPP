#include <iostream>

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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        return sameTree(root -> left, root -> right);
    }
    bool sameTree(TreeNode* lhs, TreeNode* rhs)
    {
        if (lhs == NULL and rhs == NULL)
        {
            return true;
        }
        else if (lhs == NULL or rhs == NULL)
        {
            return false;
        }
        else if (lhs -> val == rhs -> val)
        {
            return sameTree(lhs -> left, rhs -> right) and sameTree(lhs -> right, rhs -> left);
        }
        else
        {
            return false;
        }
    }

};

int main()
{
    Solution s;

    return 0;
}
