#include <iostream>

using namespace std;
/**/
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool isValidBST(TreeNode* root) {
        return valid(root, 0, 0, false, false);
    }

    bool valid(TreeNode* root, int minValue, int maxValue, bool minFlag, bool maxFlag)
    {
        bool flag;
        if (root == NULL)
        {
            return true;
        }

        if (!minFlag and !maxFlag)
        {
            flag = true;
        }
        else if (!minFlag and maxFlag)
        {
            if (root -> val < maxValue)
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
        else if (minFlag and !maxFlag)
        {
            if (root -> val > minValue)
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
        else
        {
            if (root -> val > minValue and root -> val < maxValue)
            {
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
        if (!minFlag and !maxFlag)
        {
            return flag and valid(root -> left, 0, root -> val, false, true)
            and valid(root -> right, root -> val, 0, true, false);
        }
        else if (!minFlag and maxFlag)
        {
            return flag and valid(root -> left, 0, root ->val, false, true)
            and valid(root -> right, root -> val, maxValue, true, true);
        }
        else if (minFlag and !maxFlag)
        {
            return flag and valid(root -> left, minValue, root -> val, true, true)
            and valid(root -> right, root -> val, 0, true, false);
        }
        else
        {
            return flag and valid(root -> left, minValue, root -> val, true, true)
            and valid(root -> right, root -> val, maxValue, true, true);
        }
    }
};
int main()
{
    TreeNode* root;
    TreeNode n1(3), n2(1), n3(3), n4(4), n5(5);
    // TreeNode n6()
    root = &n1;
    root -> left = &n2;
    root -> left -> right = &n3;
    root -> right = &n4;
    root -> right -> right = &n5;
    Solution s;
    cout << s.isValidBST(root) << endl;
    return 0;
}
