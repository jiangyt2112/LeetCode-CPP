#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};

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
    cout << s.maxDepth(root) << endl;
    return 0;
}
