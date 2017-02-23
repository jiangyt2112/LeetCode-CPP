#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > premute(vector<int>& nums)
    {

        vector<vector<int> > res;
        if (nums.size() == 1)
        {
            res.push_back(nums);
            return res;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> vecNum;
            for (int j = 0; j < i; j++)
            {
                vecNum.push_back(nums[j]);
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                vecNum.push_back(nums[j]);
            }
            vector<vector<int> > part = premute(vecNum);
            vector<vector<int> >::iterator iter;
            for (iter = part.begin(); iter < part.end(); iter++)
            {
                (*iter).push_back(nums[i]);
                res.push_back(*iter);
                //res.push_back();
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > res;
    vector<int> nums;
    nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    res = s.premute(nums);
    cout << res.size() <<endl;
    vector<vector<int> >::iterator iter;
    for (iter = res.begin(); iter < res.end(); iter++)
    {
        vector<int>::iterator iter2;
        for (iter2 = (*iter).begin(); iter2 < (*iter).end(); iter2++)
        {
            cout << *iter2;
        }
        cout << endl;
    }
    return 0;
}
