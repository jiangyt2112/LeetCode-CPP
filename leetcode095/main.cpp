#include <iostream>
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
    vector<TreeNode*> generateTrees(int n) {
        // 生成所有的二分查找树
        vector<TreeNode*> res;
        res = tree(1, n);
        return res;
    }

    vector<TreeNode*> tree(int s, int t)
    {
        // s - t 的二分查找树
        vector<TreeNode*> res;
        if (s > t)
        {
            return res;
        }
        else if (s == t)
        {
            TreeNode* tmp = new TreeNode(s);
            res.push_back(tmp);
            return res;
        }
        for (int i = s; i <= t; i++)
        {

            vector<TreeNode*> leftTree = tree(s, i - 1);

            vector<TreeNode*> rightTree = tree(i + 1, t);
            // cout << i << endl;
            int n = leftTree.size();
            int m = rightTree.size();
            // cout << m << n<< endl;
            if (n == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    TreeNode* r = new TreeNode(i);

                    r -> right = copyTree(rightTree[j]);

                    res.push_back(r);
                }

            }

            else if (m == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    TreeNode* r = new TreeNode(i);
                    r -> left = copyTree(leftTree[k]);
                    res.push_back(r);
                }
            }
            else
            {
                for (int k = 0; k < n; k++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        TreeNode* r = new TreeNode(i);
                        r -> left = copyTree(leftTree[k]);
                        r -> right = copyTree(rightTree[j]);
                        res.push_back(r);
                    }
                }
            }
            /*
            for (int k = 0; k < n; i++)
            {
                deleteTree(leftTree[k]);
            }

            for (int j = 0; j < m; j++)
            {
                deleteTree(rightTree[j]);
            }*/

        }
        return res;
    }
    TreeNode* copyTree(TreeNode* root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        TreeNode* myroot;
        myroot = new TreeNode(root -> val);
        myroot -> left = copyTree(root -> left);
        myroot -> right = copyTree(root -> right);
        return myroot;
    }
    void deleteTree(TreeNode* root)
    {
        if (root == NULL)
        {
            return ;
        }
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        delete root;
        deleteTree(left);
        deleteTree(right);

    }
};

void showTree(TreeNode* root)
{
    if (root == NULL)
    {
       return;
    }
    cout << root -> val << " ";
    showTree(root -> left);
    showTree(root -> right);
}

int main()
{
    Solution s;
    vector<TreeNode*> res;
    res = s.generateTrees(3);
    // cout << "aaa" << endl;
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
       showTree(res[i]);
    }
    //s.deleteTree(res[0]);
    //cout << "bbb" << endl;
    return 0;
}
