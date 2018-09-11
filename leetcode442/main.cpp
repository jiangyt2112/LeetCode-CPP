#include <iostream>
#include <vector>

using namespace std;

ostream& operator<< (ostream& out, vector<int>& nums)
{
    for (auto x : nums)
    {
        out << x << " ";
    }
    out << endl;
    return out;
}

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        int start = 0;
        while (start < n)
        {
            if (nums[start] == start + 1)
            {
                ++start;
            }
            else
            {
                if (nums[nums[start] - 1] == nums[start])
                {
                    ret.push_back(nums[start]);
                    //cout << nums;
                    //cout << start << " " << nums[start] << endl;
                    ++start;
                }
                else
                {
                    if (start < nums[start] - 1)
                    {
                        swap(nums[start], nums[nums[start] - 1]);
                    }
                    else
                    {
                        nums[nums[start] - 1] = nums[start];
                        ++start;
                    }

                }
            }
        }
        return ret;
    }
};



int main()
{
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ret = s.findDuplicates(nums);
    for (auto x : ret)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
