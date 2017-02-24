#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> tmp(n, 0);
        vector<vector<int> > Map(m, tmp);

        for (int i = n - 1; i >= 0; i--)
        {
            if (obstacleGrid[m - 1][i])
            {

                break;
            }
            else
            {
                Map[m - 1][i] = 1;
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            if (obstacleGrid[i][n - 1])
            {

                break;
            }
            else
            {
                Map[i][n - 1] = 1;
            }
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n -2; j >= 0; j--)
            {
                if (obstacleGrid[i][j])
                {
                    continue;
                }
                else
                {
                    Map[i][j] = Map[i + 1][j] + Map[i][j + 1];
                }
            }
        }
        return Map[0][0];
    }
};

int main()
{
    vector<vector<int> > obs;
    int a[] = {0, 1, 0};
    vector<int> tmp(a, a+3);
    obs.push_back(tmp);
    vector<int> tmp2(3, 0);
    //obs.push_back(tmp2);
    //obs.push_back(tmp);
    Solution s;
    cout << s.uniquePathsWithObstacles(obs) << endl;
    return 0;
}
