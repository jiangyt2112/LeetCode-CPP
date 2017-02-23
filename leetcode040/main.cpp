#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// leetcode 040,combinationSum2;
// [1, 2, 2] 5
// 数组元素可以重复，target只能由数组元素组成，不可任意重复
// 使用回溯法枚举，然后去重复
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        vector<int>::iterator iter;
        vector<int> mycan;
        for (iter = candidates.begin(); iter < candidates.end(); iter++)
        {
            if (*iter <= target)
            {
                mycan.push_back(*iter);
            }
        }
        if (mycan.size() == 0)
        {
            vector<vector<int> > res;
            return res;
        }
        std::sort(mycan.begin(), mycan.end());
        vector<int> mystack;
        vector<vector<int> > res;
        traceback(mycan, target, res, mystack, 0);
        vector<vector<int> >::iterator iter2;
        vector<vector<int> > myres;
        for (iter2 = res.begin(); iter2 < res.end(); iter2++)
        {
            vector<vector<int> >::iterator iter3;
            bool flag = true;
            for (iter3 = res.begin(); iter3 < iter2; iter3++)
            {
                if (iter2 == iter3) continue;
                if (*iter2 == *iter3)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                myres.push_back(*iter2);
            }
        }
        return myres;
    }
    void traceback(vector<int>&mycan, int target, vector<vector<int> >&res, vector<int>& mystack, int start)
    {
        if (target == 0)
        {
            res.push_back(mystack);
        }
        for (int i = start; i < mycan.size(); i++)
        {
            if (mycan[i] > target)
            {
                return ;
            }
            mystack.push_back(mycan[i]);
            traceback(mycan, target-mycan[i], res, mystack, i+1);
            mystack.pop_back();
        }
    }
};
int main()
{
    Solution s;
    vector<int> can;
    can.push_back(1);
    can.push_back(1);
    can.push_back(3);
    vector<vector<int> > res;
    res = s.combinationSum2(can, 1);
    cout << res.size() << endl;
    vector<vector<int> >::iterator iter;
    for (iter = res.begin(); iter < res.end(); iter++)
    {
        vector<int>::iterator iter2;
        for (iter2 = (*iter).begin(); iter2 < (*iter).end(); iter2++)
        {
            cout << *iter2 << " ";
        }
        cout << endl;
    }
    return 0;
}
