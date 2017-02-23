#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; i--)
        {
            if (dp[i + 1] > 0)
            {
                dp[i] = nums[i] + dp[i + 1];
            }
            else
            {
                dp[i] = nums[i];
            }
        }
        int nMax = dp[0];
        for (int i = 0; i < len; i++)
        {
            if (dp[i] > nMax)
            {
                nMax = dp[i];
            }
        }
        return nMax;
    }
};

int main()
{
    Solution s;
    int a[] = {-2};
    vector<int> nums(a, a + sizeof(a)/sizeof(int));

    // nums.push_back(1);
    cout << s.maxSubArray(nums) << endl;
    return 0;
}
