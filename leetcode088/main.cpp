#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int counter = 0;
        while (counter < m + n)
        {
            if (i == m)
            {
                nums1[counter] = nums2[j];
                counter++;
                j++;
            }
            else if (j == n)
            {
                return ;
            }
            else
            {


                if (nums1[counter] <= nums2[j])
                {
                    counter++;
                    i++;
                }
                else
                {
                    // nums1.insert(nums1.begin() + i, nums2[j]);
                    for (int k = m + n - 2; k >= counter; k--)
                    {
                        nums1[k + 1] = nums1[k];
                    }
                    nums1[counter] = nums2[j];
                    j++;
                    counter++;
                }
            }
        }
    }
};

int main()
{
    int m = 0, n = 3;
    int a[] = {};
    int b[] = {1, 2, 3};
    vector<int> nums1(m + n, 0);
    vector<int> nums2(b, b + sizeof(b) / sizeof(int));
    for (int i = 0; i < m; i++)
    {
        nums1[i] = a[i];
    }
    Solution s;
    s.merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
