#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        int max_v = *max_element(nums.begin(), nums.end());
        int ret_v = max_v;
        for (int i = 0; i < 2; ++i)
        {
            int tmp = INT_MIN;
            bool flag = false;
            for (int j = 0; j < n; ++j)
            {
                if (nums[j] < ret_v && nums[j] >= tmp)
                {
                    tmp = nums[j];
                    flag = true;
                }
            }
            if (flag)
            {
               ret_v = tmp;
            }
            else
            {
                return max_v;
            }
        }
        return ret_v;
    }
};



int main()
{
    vector<int> nums = {2, 2, 3};
    Solution s;
    cout << s.thirdMax(nums) << endl;
    return 0;
}
