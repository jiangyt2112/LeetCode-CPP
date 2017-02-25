#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        // »ØËÝ
        vector<vector<int> > res;
        vector<int> s;
        int end = nums.size();
        traceback(0, end, nums, s, res);
        return res;
    }

    void traceback(int start, int end, vector<int>& nums, vector<int>& s,vector<vector<int> >& res)
        {
            res.push_back(s);
            if (start == end)
            {
                return ;
            }

            for (int i = start; i < end; i++)
            {
                s.push_back(nums[i]);
                traceback(i + 1, end, nums, s, res);
                s.erase(s.end() - 1);
            }
        }
};

int main()
{
    Solution s;
    int a[] = {1, 2};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    vector<vector<int> > res = s.subsets(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
