#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        return search_equal(nums, 0, 0, sum);
    }
private:
    bool search_equal(vector<int>& nums, int start, int left_sum, int right_sum)
    {
        if (left_sum == right_sum)
        {
            return true;
        }
        int n = nums.size();
        if (start == n || left_sum > right_sum)
        {
            return false;
        }
        for (int i = start; i < n; ++i)
        {
            if (left_sum + nums[i] > right_sum - nums[i])
            {
                return false;
            }
            bool flag = search_equal(nums, i + 1, left_sum + nums[i], right_sum - nums[i]);
            if (flag == true)
            {
                return true;
            }
        }
        return false;
    }
};



int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 5};
    cout << s.canPartition(nums) << endl;
    return 0;
}
