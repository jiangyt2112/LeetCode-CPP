#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int> > combine(int n, int k) {
        // »ØËÝ
        vector<vector<int> > res;
        vector<int> s;
        traceback(n, k, 1, s, res);
        return res;
    }

    void traceback(int n, int k, int start, vector<int>& s, vector<vector<int> > &res)
    {
        if (k == 0)
        {
            res.push_back(s);
        }
        for (int i = start; i <= n; i++)
        {
            s.push_back(i);
            traceback(n, k - 1, i + 1, s, res);
            s.erase(s.end() - 1);
        }
    }
};


int main()
{
    Solution s;
    vector<vector<int> > res;
    res = s.combine(2, 1);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
