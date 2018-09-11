#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);
        if (n == 0)
        {
            return ret;
        }

        vector<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            if (q.empty())
            {
                q.push_back({i, nums[i]});
            }
            else
            {
                pair<int, int> top;// = q.back();
                while (!q.empty())
                {
                    top = q.back();
                    if (top.second < nums[i])
                    {
                        ret[top.first] = nums[i];
                        q.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                q.push_back({i, nums[i]});
            }
        }
        int cnt = q.size();
//        for (int i = 1; i < cnt; ++i)
//        {
//            if (q[0].second > q[i].second)
//            {
//                ret[q[i].first] = q[0].second;
//            }
//
//        }
        int end_index = q[0].first;
        int start = 0;
        int j = cnt - 1;
        while (start <= end_index && j > 0)
        {
            if (nums[start] > q[j].second)
            {
                ret[q[j].first] = nums[start];
                --j;
            }
            else
            {
                ++start;
            }
        }
        return ret;
    }
};


int main()
{
    vector<int> nums = {1, 2, 3, 2, 1};
    Solution s;
    vector<int> ret = s.nextGreaterElements(nums);
    for (auto x : ret)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
