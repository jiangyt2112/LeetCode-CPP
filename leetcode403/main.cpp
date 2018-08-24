#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> m(n + 1, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i)
        {
            m[i][n - 1] = true;
        }
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = n - 1; j >=0; --j)
            {
                if (j != 0)
                {
                    if (stones[i] + j - 1 == stones[i + 1] && m[j - 1][i + 1])
                    {
                        m[j][i] = true;
                    }
                }

                if (stones[i] + j == stones[i + 1] && m[j][i + 1])
                {
                    m[j][i] = true;
                }
                else if (stones[i] + j + 1 == stones[i + 1] && m[j + 1][i + 1])
                {
                    m[j][i] = true;
                }
            }
        }
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                cout << m[i][j] << " ";
//            }
//            cout << endl;
//        }
        return m[0][0];
    }
};
*/


class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> m(n + 1, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i)
        {
            m[i][n - 1] = true;
        }
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int x = stones[j] - stones[i];
                if (x < n && x >= 0 && m[x][j])
                {
                    if (x - 1 >= 0)
                    {
                        m[x - 1][i] = true;
                    }
                    m[x][i] = true;
                    if (x + 1 < n)
                    {
                        m[x + 1][i] = true;
                    }
                }
            }
        }
        return m[0][0];
    }
};

int main()
{
    Solution s;
    vector<int> stones = {0,1,3,5,6,8,12,17};
    cout << s.canCross(stones) << endl;
    return 0;
}
