#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 经典字符串相似度算法，动态规划
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> tmp (m + 1, 0);
        vector<vector<int> > dp(n + 1, tmp);
        for (int i = 0; i <= m; i++)
        {
            dp[n][i] = m - i;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][m] = n - i;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int same = 1;
                if (word1[i] == word2[j])
                {
                    same = 0;
                }
                dp[i][j] = min(min(1 + dp[i + 1][j], 1 + dp[i][j+1]), same + dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution s;
    cout << s.minDistance("park", "spake") << endl;
    return 0;
}
