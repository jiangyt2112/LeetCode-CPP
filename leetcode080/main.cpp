#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> Map;
        int n = nums.size();
        int res = 0;
        vector<int> vecRes;
        for (int i = 0; i < n; i++)
        {
            if (Map[nums[i]] == 0)
            {
                Map[nums[i]] = 2;
                vecRes.push_back(nums[i]);
                res++;
            }
            else if (Map[nums[i]] == 2)
            {
                Map[nums[i]] = 1;
                vecRes.push_back(nums[i]);
                res++;
            }
        }
        nums = vecRes;
        return res;
    }
};

int main()
{
    int a[] = {0, 0, 0, 1, 2, 2, 3, 2, 1, 2, 0};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    Solution s;
    cout << s.removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
