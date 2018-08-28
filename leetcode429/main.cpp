#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root == nullptr)
        {
            return ret;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int cnt = q.size();
            vector<int> level(cnt);
            for (int i = 0; i < cnt; ++i)
            {
                Node* n = q.front();
                level[i] = n->val;
                for (auto x : n->children)
                {
                    if (x != nullptr)
                    {
                        q.push(x);
                    }
                }
                q.pop();
            }
            ret.push_back(move(level));
        }
        return ret;
    }
};




int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
