#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 中根遍历，使用循环
        // 使用栈结构
        stack<TreeNode*> sta;
        map<TreeNode*, int> Map;
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }
        sta.push(root);
        while (!sta.empty())
        {
            TreeNode* tmp = sta.top();
            sta.pop();
            if (Map[tmp] == 0)
            {
                Map[tmp] = 1;
                if (tmp -> right != NULL)
                {
                    sta.push(tmp -> right);
                }
                sta.push(tmp);
                if (tmp -> left != NULL)
                {
                    sta.push(tmp -> left);
                }
            }
            else
            {
                res.push_back(tmp -> val);
            }

        }
        return res;
    }
};
#include "show.h"
int main()
{
    Solution s;
    vector<int> res;
    TreeNode* root = NULL; // new TreeNode(2);
    // root -> left = new TreeNode(1);
    //root -> right = new TreeNode(3);
    res = s.inorderTraversal(root);
    show(res);
    return 0;
}
