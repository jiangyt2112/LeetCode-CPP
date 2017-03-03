#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        // a - 1, b - 2 ,..., z - 26;
        // divide conquer
        // 11 - 19 21 - 26 double decode method
        // 10 20 one decode method
        // other two digits has one decode method
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        if (s[0] == '0')
        {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if ( (s[i - 2] == '1' or s[i - 2] == '2' ) and s[i - 1] == '0')
            {
                dp[i] = dp[i - 2];
            }
            else if (s[i - 1] == '0')
            {
                return 0;
            }
            else if (s[i - 2] == '1' and s[i - 1] >= '1' and s[i - 1] <= '9')
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else if (s[i - 2] == '2' and s[i - 1] >= '1' and s[i - 1] <= '6')
            {

                dp[i] = dp[i - 1] + dp[i - 2];

            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];

    }
};

int main()
{
    string str = "357456456410";
    Solution s;
    cout << s.numDecodings(str) << endl;
    return 0;
}
