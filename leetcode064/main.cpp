#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> tmp(n, 0);
        vector<vector<int> > Map(m, tmp);
        Map[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 2; i >= 0; i--)
        {
            Map[i][n - 1] = Map[i + 1][n - 1] + grid[i][n - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            Map[m - 1][i] = Map[m - 1][i + 1] + grid[m - 1][i];
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                Map[i][j] = min(grid[i][j] + Map[i + 1][j], grid[i][j] + Map[i][j + 1]);
            }
        }
        return Map[0][0];
    }
};

int main()
{
    Solution s;
    int a[] = {1};//, 2, 3};
    vector<int> tmp(a, a + sizeof(a)/sizeof(int));
    vector<vector<int> > grid;
    grid.push_back(tmp);
    // grid.push_back(tmp);
    cout << s.minPathSum(grid) << endl;
    return 0;
}
