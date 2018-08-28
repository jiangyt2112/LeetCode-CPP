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
    int pathSum(TreeNode* root, int sum) {
        m_sum = sum;
        m_ret = 0;
        find_path(root);
        return m_ret;
    }
private:
    vector<int> find_path(TreeNode* root)
    {
        vector<int> ret;
        if (root == nullptr)
        {
            return ret;
        }
        vector<int> left = find_path(root->left);
        vector<int> right = find_path(root->right);
        ret.push_back(root->val);
        if (root->val == m_sum)
        {
            ++m_ret;
        }
        for (auto x : left)
        {
            if (x + root->val == m_sum)
            {
                ++m_ret;
            }
            ret.push_back(x + root->val);
        }
        for (auto x : right)
        {
            if (x + root->val == m_sum)
            {
                ++m_ret;
            }
            ret.push_back(x + root->val);
        }
        return ret;
    }
private:
    int m_sum;
    int m_ret;
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
