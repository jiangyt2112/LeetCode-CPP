#include <iostream>
#include <string>
#include <queue>

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ret;
        while (!q.empty())
        {
            int cnt = q.size();
            for (int i = 0; i < cnt; ++i)
            {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp == nullptr)
                {
                    ret += "NULL ";
                }
                else
                {
                    ret += to_string(tmp->val) + " ";
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        queue<TreeNode**> q;
        q.push(&root);
        int start = 0;
        while (!q.empty())
        {
            int cnt = q.size();
            for (int i = 0; i < cnt; ++i)
            {
                TreeNode** cur = q.front();
                q.pop();
                int blank = data.find(' ', start);
                //cout << blank << endl;
                string tmp = data.substr(start, blank - start);
                //cout << tmp.size() << endl;
                start = blank + 1;
                if (tmp == "NULL")
                {
                    *cur = nullptr;
                }
                else
                {
                    *cur = new TreeNode(stoi(tmp));
                    q.push(&((*cur)->left));
                    q.push(&((*cur)->right));
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));




int main()
{
    Codec codec;
    TreeNode* root = nullptr;
    cout << codec.serialize(root) << endl;
    cout << codec.deserialize("NULL ") << endl;
    return 0;
}
