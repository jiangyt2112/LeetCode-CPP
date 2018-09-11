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
    int diameterOfBinaryTree(TreeNode* root) {
        int high = 0;
        if (root == nullptr)
        {
            return 0;
        }
        return diameter(root, high) - 1;
    }
private:
    int diameter(TreeNode* root, int& high)
    {
        if (root == nullptr)
        {
            high = 0;
            return 0;
        }
        int left_high = 0;
        int right_high = 0;
        int left_val = diameter(root->left, left_high);
        int right_val = diameter(root->right, right_high);
        high = max(left_high, right_high) + 1;
        return max(max(left_val, right_val), left_high + right_high + 1);
    }
};




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
