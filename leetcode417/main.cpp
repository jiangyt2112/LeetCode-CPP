#include <iostream>
#include <vector>

using namespace std;

class Water
{
public:
    Water():left(false), right(false), top(false), bottom(false) {}
    bool is_pacific() { return left || top; }
    bool is_atlantic() { return right || bottom; }
    bool operator ==(const Water& rhl)
    {
        return (left == rhl.left) && (right == rhl.right) && (top == rhl.top) && (bottom == rhl.bottom);
    }
    bool change(const Water& rhl)
    {
        bool flag = false;
        if (rhl.left == true && left == false)
        {
            left = true;
            flag = true;
        }
        if (rhl.right == true && right == false)
        {
            right = true;
            flag = true;
        }
        if (rhl.top == true && top == false)
        {
            top = true;
            flag = true;
        }
        if (rhl.bottom == true && bottom == false)
        {
            bottom = true;
            flag = true;
        }
        return flag;
    }
    bool left;
    bool right;
    bool top;
    bool bottom;
};
ostream& operator <<(ostream& out, const Water& w)
{
    out << w.left << " " << w.right << " " << w.top << " " << w.bottom << endl;
    return out;
}
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ret;
        int n = matrix.size();
        if (n == 0)
        {
            return ret;
        }
        int m = matrix[0].size();
        if (m == 0)
        {
            return ret;
        }
        vector<vector<Water>> w(n, vector<Water>(m));
        for (int i = 0; i < m; ++i)
        {
            w[0][i].top = true;
            w[n - 1][i].bottom = true;
        }
        for (int j = 0; j < n; ++j)
        {
            w[j][0].left = true;
            w[j][m - 1].right = true;
        }
        bool flag = true;
        while (flag)
        {
            flag = false;
            // cout << "aaa" <<endl;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || x >= n || y < 0 || y >= m || (w[i][j] == w[x][y]) || matrix[i][j] < matrix[x][y])
                        {
                            ;
                        }
                        else
                        {
                            //cout << w[i][j] << w[x][y] << endl;
                            //cout << (w[i][j] == w[x][y]) << endl;
                            //w[i][j] = w[x][y];
                            if (w[i][j].change(w[x][y]))
                            {
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (w[i][j].is_pacific() && w[i][j].is_atlantic())
                {
                    ret.push_back({i, j});
                }
            }
        }
        return ret;
    }
};



int main()
{
    vector<vector<int>> w = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    Solution s;
    vector<pair<int, int>> ret = s.pacificAtlantic(w);
    for (const auto& x : ret)
    {
        cout << x.first << ":" << x.second << " ";
    }
    cout << endl;
    return 0;
}
