#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        if (nums.size() == 0)
        {
            return res;
        }
        res = premute(nums);

        return res;
    }
    vector<vector<int> > premute(vector<int>& nums)
    {
        vector<vector<int> > res;
        if (nums.size() == 1)
        {
            vector<int> tmp;
            tmp.push_back(nums[0]);
            res.push_back(tmp);
            return res;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> tmpNums;
            for (int j = 0; j < nums.size(); j++)
            {
                if (j == i)
                    continue;
                tmpNums.push_back(nums[j]);
            }

            vector<vector<int> > tmpRes;
            tmpRes = premute(tmpNums);
            for ( int j = 0; j < tmpRes.size(); j++)
            {
                tmpRes[j].push_back(nums[i]);
                res.push_back(tmpRes[j]);
            }
        }
        vector<vector<int> > uniqueRes;
        for (int i = 0; i < res.size(); i++)
        {
            bool flag = true;
            for (int j = i + 1; j < res.size(); j++)
            {
                if (res[i] == res[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                uniqueRes.push_back(res[i]);
            }

        }
        return uniqueRes;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > res;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    res = s.permuteUnique(nums);
    cout << res.size() << endl;
    /*for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }*/
    return 0;
}
