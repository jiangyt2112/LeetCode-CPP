#include <iostream>
#include <queue>

using namespace std;
// #include "show.h"
/**/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int counter = 1;
        int counter2 = 0;
        vector<vector<int> > res;
        if (root == NULL)
        {
            return res;
        }
        q.push(root);
        vector<int> level;
        while(!q.empty())
        {
            //cout << counter << " " << counter2 << endl;

            TreeNode* tmp;
            tmp = q.front();
            q.pop();
            level.push_back(tmp -> val);
            // show(level);
            //cout << "res:";
            //show(res);
            if (tmp -> left != NULL)
            {
                q.push(tmp -> left);
                counter2++;
            }
            if (tmp -> right != NULL)
            {
                q.push(tmp -> right);
                counter2++;
            }
            counter--;
            if (counter == 0)
            {
                //cout << "level:";
                //show(level);
                res.push_back(level);
                level.clear();
                counter = counter2;
                counter2 = 0;
            }
        }
        return res;
    }
};
// #include "show.h"
int main()
{
    TreeNode* root;
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    root = &n1;
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    Solution s;
    vector<vector<int> > res = s.levelOrder(root);
    // show(res);
    return 0;
}
