#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> tmp(n, 0);
        vector<vector<int> > Map(m, tmp);
        for (int i = 0; i < n; i++)
        {
            Map[m - 1][i] = 1;
        }
        for (int j = 0; j < m; j++)
        {
            Map[j][n - 1] = 1;
        }
        // Map[m - 1][n - 1] = 0;

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                Map[i][j] = Map[i + 1][j] + Map[i][j + 1];
            }
        }
        return Map[0][0];
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(50, 100) << endl;
    return 0;
}
