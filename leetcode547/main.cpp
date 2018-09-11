#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int ret = 0;
        int n = M.size();
        if (n == 0)
        {
            return ret;
        }
        vector<bool> touch(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (touch[i] == false)
            {
                ++ret;
                // search_map()
                // BFS
                touch[i] = true;
                queue<int> q;
                q.push(i);
                while (!q.empty())
                {
                    int cnt = q.size();
                    for (int j = 0; j < cnt; ++j)
                    {
                        int top = q.front();
                        q.pop();
                        for (int x = 0; x < n; ++x)
                        {
                            if (M[top][x] == 1 && touch[x] == false)
                            {
                                q.push(x);
                                touch[x] = true;
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};



int main()
{
    vector<vector<int>> M = {{1}};
    Solution s;
    cout << s.findCircleNum(M) << endl;
    return 0;
}
