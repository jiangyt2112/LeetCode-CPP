#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        while (start < n)
        {
            if (nums[start] != start + 1)
            {
                if (start < nums[start] - 1)
                {
                    if (nums[start] == nums[nums[start] - 1])
                    {
                        ++start;
                    }
                    else
                    {
                        swap(nums[start], nums[nums[start] - 1]);
                    }
                }
                else
                {
                    nums[nums[start] - 1] = nums[start];
                }
                // swap(nums[start], nums[nums[start] - 1]);
            }
            else
            {
                ++start;
            }
        }
        vector<int> ret;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
