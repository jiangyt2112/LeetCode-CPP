#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ret(n, vector<int>(m, 10001));
        bool flag = true;
        while (flag)
        {
            flag = false;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (matrix[i][j] == 0)
                    {
                        if (ret[i][j] != 0)
                        {
                            ret[i][j] = 0;
                            flag = true;
                        }
                    }
                    else
                    {
                        int min_v = 10001;
                        for (int k = 0; k < 4; ++k)
                        {
                            int x = dx[k] + i;
                            int y = dy[k] + j;
                            if (x >= 0 && x < n && y >= 0 && y < m)
                            {
                                min_v = min(min_v, ret[x][y] + 1);
                            }
                        }
                        if (ret[i][j] != min_v)
                        {
                            ret[i][j] = min_v;
                            flag = true;
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
    cout << "Hello world!" << endl;
    return 0;
}
