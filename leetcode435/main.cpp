#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const Interval& lht, const Interval& rht){ return lht.start == rht.start ? lht.end < rht.end : lht.start < rht.start;});
        int n = intervals.size();
        int ret = 0;
        if (n == 0)
        {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        vector<int> max_v(n + 1, 0);
        dp[n - 1] = 1;
        max_v[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            vector<Interval>::iterator iter = lower_bound(intervals.begin(), intervals.end(), intervals[i].end,
                                                          [](const Interval& lht, int val) {return lht.start < val;});
            int index = distance(intervals.begin(), iter);
            dp[i] = (index == n ? 1 : max_v[index] + 1);
            max_v[i] = max(dp[i], max_v[i + 1]);
        }
        return n - max_v[0];
    }
};


int main()
{
    Solution s;
    vector<Interval> intervals = {Interval(1, 2), Interval(2, 3)};
    cout << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
