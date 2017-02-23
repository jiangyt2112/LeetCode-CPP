#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int nMin = abs(target - (nums[0] + nums[1] + nums[2]));
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                for ( int k = j + 1; k < n; k++)
                {
                    int tmp = abs(target - (nums[i] + nums[j] + nums[k]));
                    if (tmp < nMin)
                    {
                        nMin = tmp;
                        res = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    cout << s.threeSumClosest(nums, 1) << endl;
    return 0;
}
