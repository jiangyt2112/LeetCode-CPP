#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        // dp[i] = min{dp[j]+1}
        int nSize = nums.size();
        int* dp = new int[nSize];
        dp[nSize - 1] = 0;

        int nGIndex = nSize - 1;
        for (int i = nSize - 2; i >= 0; i--)
        {
            int jumps = nums[i];
            if (i + jumps >= nGIndex)
            {
                dp[i] = 1;
                continue;
            }
            int nMin = nSize;
            for (int j = i+1; j <= i+jumps and j <= nSize-1; j++)
            {
                if (nMin > dp[j]+1)
                {
                    nMin = dp[j]+1;
                }
            }
            dp[i] = nMin;
        }
        return dp[0];
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    for (int i = 25000; i >= 1; i--)
    {
        nums.push_back(i);
    }
    nums.push_back(1);
    nums.push_back(0);
    // cout << nums.size() << endl;
    int j = s.jump(nums);
    cout << j << endl;
    return 0;

}
