#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int nSize = nums.size();
        int i = 0;
        if (nSize == 0)
        {
            return 1;
        }
        while (i < nSize)
        {
            if (nums[i] > nSize or nums[i] <= 0)
            {
                nums[i] = 0;
                i++;
            }
            else
            {
                if (nums[i] == i+1)
                {
                    i++;
                }
                else if (nums[i] > i+1)
                {
                    if (nums[nums[i]-1] == nums[i])
                    {
                        nums[i] = 0;
                        i++;
                    }
                    else
                    {
                        int tmp = nums[nums[i]-1];
                        nums[nums[i]-1] = nums[i];
                        nums[i] = tmp;
                    }

                }
                else if (nums[i] < i+1)
                {
                    if (nums[i] == nums[nums[i]-1])
                    {
                        nums[i] = 0;
                        i++;
                    }
                    else
                    {
                        nums[nums[i]-1] = nums[i];
                        nums[i] = 0;
                        i++;
                    }

                }
            }
        }
        for (int i = 0; i < nSize; i++)
        {
            if (nums[i] == 0)
            {
                return i+1;
            }
        }
        return nSize+1;
    }

};
int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(4);
    int res = s.firstMissingPositive(nums);
    cout << res << endl;
    return 0;
}
