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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* del = root;
        TreeNode* parent = root;
        while (del != nullptr)
        {
            if (del->val == key)
            {
                break;
            }
            else if (del->val < key)
            {
                parent = del;
                del = del->right;
            }
            else
            {
                parent = del;
                del = del->left;
            }
        }
        if (del == nullptr)
        {
            return root;
        }
        if (del->left == nullptr && del->right == nullptr)
        {
            if (root == del)
            {
                delete root;
                root = nullptr;
                return root;
            }
            if (parent->left == del)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
            delete del;
            return root;
        }
        if (del->left != nullptr)
        {
            if (del->left->right == nullptr)
            {
                del->val = del->left->val;
                TreeNode* tmp = del->left;
                del->left = del->left->left;
                delete tmp;
            }
            else
            {
                TreeNode* pre = del->left;
                TreeNode* trav = del->left->right;
                while (trav->right != nullptr)
                {
                    pre = trav;
                    trav = trav->right;
                }
                del->val = trav->val;
                pre->right = trav->left;
                delete trav;
            }
            return root;
        }
        if (del->right != nullptr)
        {
            if (del->right->left == nullptr)
            {
                del->val = del->right->val;
                TreeNode* tmp = del->right;
                del->right = del->right->right;
                delete tmp;
            }
            else
            {
                TreeNode* pre = del->right;
                TreeNode* trav = del->right->left;
                while (trav->left != nullptr)
                {
                    pre = trav;
                    trav = trav->left;
                }
                del->val = trav->val;
                pre->left = trav->right;
                delete trav;
            }
            return root;
        }
    }

};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
