#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL and q == NULL)
        {
            return true;
        }
        if (p == NULL or q == NULL)
        {
            return false;
        }
        if (p -> val != q -> val)
        {
            return false;
        }
        else
        {
            return isSameTree(p -> left, q -> left) and isSameTree(p ->right , q -> right);
        }
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
