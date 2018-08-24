#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        if (n == 0)
        {
            return 0;
        }
        int m = heightMap[0].size();
        if (m == 0)
        {
            return 0;
        }
        int min_v = 2147483647;
        vector<vector<int>> map_(n + 2, vector<int>(m + 2, 1));
        int ret = 0;
        while (true)
        {
            //cout << "bbbb" << endl;
            if (min_v != 2147483647)
            {
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < m; ++j)
                    {
                        if (heightMap[i][j] != 0)
                        {
                            heightMap[i][j] -= min_v;
                        }
                    }
                }
            }
            min_v = 2147483647;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (heightMap[i][j] != 0 && min_v > heightMap[i][j])
                    {
                        min_v = heightMap[i][j];
                    }
                    if (heightMap[i][j] != 0)
                    {
                        map_[i + 1][j + 1] = 1;
                    }
                    else
                    {
                        map_[i + 1][j + 1] = 0;
                    }
                }
            }
            if (min_v == 2147483647)
            {
                break;
            }
//            cout << min_v << endl;
//            for (int i = 0; i < map_.size(); ++i)
//            {
//                for (int j = 0; j < map_[i].size(); ++j)
//                {
//                    cout << map_[i][j] << " ";
//                }
//                cout << endl;
//            }
            ret += volume(map_, min_v);
            //cout << ret << endl;
        }
        return ret;

    }
private:
    int volume(vector<vector<int>>& bit_map, int height)
    {
        // cout << "ccc" << endl;
        int n = bit_map.size();
        int m = bit_map[0].size();
        vector<vector<bool>> found(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i)
        {
            touch(bit_map, i, 0, n, m, found);
            touch(bit_map, i, m - 1, n, m, found);
        }
        for (int j = 0; j < m; ++j)
        {
            touch(bit_map, 0, j, n, m, found);
            touch(bit_map, n - 1, j, n, m, found);
        }
        int area = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (bit_map[i][j] == 0)
                {
                    ++area;
                }
            }
        }
        return area * height;
    }
    void touch(vector<vector<int>>& bit_map, int x, int y, int n, int m, vector<vector<bool>>& found)
    {
        // cout << "aaa" << endl;
        if (x < 0 || x >= n || y < 0 || y >= m || found[x][y])
        {
            return;
        }
        found[x][y] = true;
        if (x != 0 && x != n - 1 && y != 0 && y != m - 1 && bit_map[x][y] == 1)
        {
            return;
        }
        bit_map[x][y] = 1;
        for (int i = 0 ; i < 4; ++i)
        {
            touch(bit_map, x + dx[i], y + dy[i], n , m, found);
        }
    }
};



int main()
{
    vector<vector<int>> heightMap;// = {{1,4,3,1,3,2}, {3,2,1,3,2,4}, {2,3,3,2,3,1}};
    Solution s;
    cout << s.trapRainWater(heightMap) << endl;
    return 0;
}
