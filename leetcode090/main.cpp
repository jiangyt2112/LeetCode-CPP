#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        // traceback and delete duplicates
        vector<int> s;
        int start = 0;
        int end = nums.size();
        vector<vector<int> > res;
        traceback(nums, start, end, s, res);
        vector<vector<int> > norepeat;
        map<int, int> Map;
        for (int i = 0; i < res.size(); i++)
        {
            bool flag = false;
            for (int j = i + 1; j < res.size(); j++)
            {
                if (res[i] == res[j])
                {
                    flag = true;
                    break;
                }
                int n = res[i].size();
                int m = res[j].size();
                if (n != m)
                {
                    // flag = true;
                    continue;
                }
                else
                {
                    Map.clear();
                    bool flag2 = false;
                    for (int k = 0; k < n; k++)
                    {
                        Map[res[i][k]]++;
                    }
                    for (int k = 0; k < m; k++)
                    {
                        if (Map[res[j][k]] != 0)
                        {
                            Map[res[j][k]]--;
                        }
                        else
                        {
                            flag2 = true;
                            break;
                        }
                    }
                    if (!flag2)
                    {
                        flag = true;
                        break;
                    }

                }
            }
            if (!flag)
            {
                norepeat.push_back(res[i]);
            }
        }
        return norepeat;
    }
    void traceback(vector<int>& nums, int start, int end, vector<int>& s, vector<vector<int> >& res)
    {
        res.push_back(s);
        if (start == end)
        {
            return ;
        }
        for (int i = start; i < end; i++)
        {
            s.push_back(nums[i]);
            traceback(nums, i + 1, end, s, res);
            s.erase(s.end() - 1);
        }
    }
};

int main()
{
    int a[] = {4, 4, 4, 1, 4};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    Solution s;
    vector<vector<int> > res;
    res = s.subsetsWithDup(nums);
    for (int i = 0; i < res.size() ; i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
