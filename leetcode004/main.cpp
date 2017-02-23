#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 二分查找
        // 中位数满足 (m + n)/2 < median < (m + n)/2
        int m = nums1.size();
        int n = nums2.size();
        int mid;
        bool flag = false;
        if ((m+n) & 1)
        {
            mid = (m + n)/2;
        }
        else
        {
            mid = (m + n)/2 -1;
            flag = true;
        }
        int s = 0;
        int t = m;
        int mmid = (s + t)/2;
        while ( s != t)
        {
            int left;
            int right;
            if (flag) // 偶数个数
            {
                left = mid - mmid - 1;
                right = left + 2;

                if (nums1[mmid] > nums2[left] and nums1[mmid] < nums2[right])
                {
                    return (nums1[mmid] + nums2[mid - mmid]) / 2;
                }
                else if(nums1[mmid] < nums2[left])
                {
                    s = mmid + 1;
                    mmid = (s + t) / 2;
                }
                else
                {
                    t = mmid;
                    mmid = (s + t) / 2;
                }

            }
            else
            {
                left = mid - mmid - 1;
                right = left + 1;
                if (mmid == m-1)
                {
                    if (nums1[mmid] <= nums2[right])
                    {
                        return nums1[mmid];
                    }
                    else
                    {
                        s = t;
                    }
                }
                else if (mmid == 0 )
                {
                    if (nums1[mmid] >= nums2[left])
                    {
                        return nums1[mmid];
                    }
                    else
                    {
                        s = t;
                    }
                }
                else if (nums1[mmid] > nums2[left] and nums1[mmid] < nums2[right])
                {
                    return nums1[mmid];
                }
                else if(nums1[mmid] < nums2[left])
                {
                    s = mmid + 1;
                    mmid = (s + t) / 2;
                }
                else
                {
                    t = mmid;
                    mmid = (s + t) / 2;
                }
            }

        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(1);
    nums1.push_back(2);
    nums2.push_back(2);
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
