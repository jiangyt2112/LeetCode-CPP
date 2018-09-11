#include <iostream>
#include <vector>

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
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr)
        {
            return ret;
        }
        find_mode(root, root->val - 1);
        return ret;
    }
private:
    void find_mode(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val == val)
        {
            find_mode(root->left, val);
            find_mode(root->right, val);
            return;
        }
        int cnt = 0;
        cnt += find_val(root->left, root->val);
        cnt += find_val(root->right, root->val);
        if (cnt == mode)
        {
            ret.push_back(root->val);
        }
        else if (cnt > mode)
        {
            ret.clear();
            ret.push_back(root->val);
            mode = cnt;
        }
        find_mode(root->left, root->val);
        find_mode(root->right, root->val);
    }
    int find_val(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->val == val)
        {
            return 1 + find_val(root->left, val) + find_val(root->right, val);
        }
        return 0;
    }
private:
    vector<int> ret;
    int mode;
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
