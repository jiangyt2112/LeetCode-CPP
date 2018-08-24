#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](const pair<int, int>& left, const pair<int, int>& right) {return left < right;});
        int n = people.size();
        vector<pair<int, int>> ret(n);
        vector<bool> flag(n, false);
        int i = 0;
        int h = -1;
        int cnt = 0;
        while (i < n)
        {
            if (h == people[i].first)
            {
                ++cnt;
                place(people[i], ret, flag, people[i].second - cnt);
            }
            else
            {
                cnt = 0;
                h = people[i].first;
                place(people[i], ret, flag, people[i].second);
            }
            ++i;
        }
        return ret;
    }
private:
    void place(const pair<int, int>& people, vector<pair<int, int>>& ret, vector<bool>& flag, int n)
    {
        int num = ret.size();
        int cnt = 0;
        for (int i = 0; i < num; ++i)
        {
            if (flag[i] == false)
            {
                if (cnt == n)
                {
                    ret[i] = people;
                    flag[i] = true;
                    return;
                }
                ++cnt;
            }
        }
        return;
    }
};



int main()
{
    Solution s;
    vector<pair<int, int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<pair<int, int>> ret = s.reconstructQueue(people);
    for (auto x : ret)
    {
        cout << x.first << " " << x.second << "/";
    }
    cout << endl;
    return 0;
}
