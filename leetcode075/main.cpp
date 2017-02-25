#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int pos0 = -1;
        int pos1 = -1;
        int pos2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                pos2++;
                nums[pos2] = 2;
                pos1++;
                nums[pos1] = 1;
                pos0++;
                nums[pos0] = 0;
            }
            else if (nums[i] == 1)
            {
                pos2++;
                nums[pos2] = 2;
                pos1++;
                nums[pos1] = 1;
            }
            else
            {
                pos2++;
            }
        }
    }
};


int main()
{
    Solution s;
    int a[] = {};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    s.sortColors(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
