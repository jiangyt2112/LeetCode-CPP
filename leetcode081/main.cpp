#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
        {
            return false;
        }
        return binSearch(nums, 0, n, target);
    }

    bool binSearch(vector<int>& nums, int s, int t, int target)
    {
        if ( s == t)
        {
            return false;
        }
        int mid = (s + t) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[s] < nums[mid] and nums[mid] <= nums[t - 1])
        {
            if (nums[mid] < target)
            {
                s = mid + 1;
                return binSearch(nums, s, t, target);
            }
            else
            {
                t = mid;
                return binSearch(nums, s, t, target);
            }
        }
        else if (nums[mid] > nums[s] and nums[mid] >= nums[t - 1])
        {
            if (nums[mid] < target)
            {
                s = mid + 1;
                return binSearch(nums, s, t, target);
            }
            else
            {
                if (nums[s] == target)
                {
                    return true;
                }
                else if (nums[s] < target)
                {
                    s = s + 1;
                    t = mid;
                    return binSearch(nums, s, t, target);
                }
                else
                {
                   s = mid + 1;
                   return binSearch(nums, s, t, target);
                }
            }
        }
        /*
        else if (nums[s] == nums[mid])
        {
            s = mid + 1;
            return binSearch(nums, s, t, target);
        }
        else if (nums[mid] == nums[t])
        {
            t = mid;
            return binSearch(nums, s, t, target);
        }*/
        else if (nums[mid] < nums[s] and nums[mid] <= nums[t - 1])
        {
            if (nums[mid] > target)
            {
                t = mid;
                return binSearch(nums, s, t, target);
            }
            else
            {
                if (target >= nums[s])
                {
                    t = mid;
                    return binSearch(nums, s, t, target);
                }
                else
                {
                   s = mid + 1;
                   return binSearch(nums, s, t, target);
                }
            }
        }
        else
        {
            bool flag;
            flag = binSearch(nums, s, mid, target);
            if (flag)
                return flag;
            return binSearch(nums, mid + 1, t, target);
        }
    }
};

int main()
{
    Solution s;
    int a[] = {4, 4, 5, 5, 6, 1, 2, 3, 3};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    cout << s.search(nums, 0) << endl;
    return 0;
}
