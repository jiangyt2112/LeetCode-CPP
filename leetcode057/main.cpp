#include <iostream>
#include <vector>

using namespace std;


//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int start = newInterval.start;
        int end = newInterval.end;
        int n = intervals.size();
        int from = -1;
        int to = -1;
        for (int i = 0; i < n; i++)
        {
            if (start <= intervals[i].start or (start >= intervals[i].start and start <= intervals[i].end))
            {
                from = i;
                break;
            }
        }
        if (from == -1)
        {
            from = n;
            intervals.push_back(newInterval);
            return intervals;

        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (end >= intervals[i].end or (end <= intervals[i].end and end >= intervals[i].start))
            {
                to = i;
                break;
            }
        }
        if (to == -1)
        {
            to = -1;
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        //merge from - to
        for (int i = 0; i < from; i++)
        {
            res.push_back(intervals[i]);
        }
        Interval in;
        in.start = min(newInterval.start, intervals[from].start);
        in.end = max(newInterval.end, intervals[to].end);
        res.push_back(in);
        for (int i = to + 1; i < n; i++)
        {
            res.push_back(intervals[i]);
        }
        return res;
    }
};

int main()
{
    Interval in1(1, 2), in2(3, 5), in3(6, 7), in4(8, 10), in5(12, 16), in6(4, 9);
    vector<Interval> intervals;
    intervals.push_back(in1);
    intervals.push_back(in2);
    intervals.push_back(in3);
    intervals.push_back(in4);
    intervals.push_back(in5);

    Solution s;
    vector<Interval> res;
    res = s.insert(intervals, in6);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << "("<< res[i].start << "," << res[i].end << ")" << endl;
    }
    return 0;

}
