#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<int> > res;
        vector<int> pos(n, 0);
        queen(res, 0, pos, n);
        vector<vector<string> > result;
        for (int i = 0; i < res.size(); i++)
        {
            vector<string> oneSol;
            for (int j = 0; j < res[i].size(); j++)
            {
                string tmpStr;
                for (int k = 0; k < n; k++)
                {
                    if (k == res[i][j])
                    {
                        tmpStr += 'Q';
                    }
                    else
                    {
                        tmpStr += '.';
                    }
                }
                oneSol.push_back(tmpStr);
            }
            result.push_back(oneSol);
        }

        return result;
    }

    void queen(vector<vector<int> >& res, int start, vector<int>& pos, int endPos)
    {
        if (start == endPos)
        {
            res.push_back(pos);
            return ;
        }
        for (int i = 0; i < endPos; i++)
        {
            pos[start] = i;
            if (check(pos, start))
            {
                queen(res, start + 1, pos, endPos);
            }
            else
            {
                continue;
            }
        }
        return ;
    }

    bool check(vector<int>&pos, int endPos)
    {
        for (int i = 0; i<= endPos; i++)
        {
            for (int j = i+1; j <= endPos; j++)
            {
                if (pos[j] == pos[i])
                {
                    return false;
                }
                if (pos[j] == pos[i] + j - i)
                {
                    return false;
                }
                if (pos[j] == pos[i] - (j - i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<string> > res;
    res = s.solveNQueens(4);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            for (int k = 0; k < res[i][j].size(); k++)
            {
                cout << res[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
