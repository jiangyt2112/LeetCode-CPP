#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] + i >= reach)
            {
                reach = i;
            }
        }
        if (reach == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    Solution s;
    int a[] = {2,3,1,1,4}; //{3,2,1,0,4};
    vector<int> nums(a, a + sizeof(a)/sizeof(int));
    cout << s.canJump(nums) << endl;
    return 0;
}
