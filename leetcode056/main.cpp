#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool compare(const Interval & in1, const Interval & in2)
    {
        if (in1.start < in2.start)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        int n = intervals.size();
        cout << "n:" << n << endl;
        for (int i = 0; i < n; i++)
        {
            // cout << "i:" << i << endl;
            // show(intervals);

            int next = i+1;
            if (next == n)
            {
                res.push_back(intervals[i]);
            }
            else if (intervals[next].start <= intervals[i].end)
            {
                intervals[next].start = intervals[i].start;
                intervals[next].end = max(intervals[i].end, intervals[next].end);
            }
            else
            {
                res.push_back(intervals[i]);
            }

        }
        return res;
    }

    void show(vector<Interval>& in)
    {
        for (int j = 0; j < in.size(); j++)
        {
            cout << "(" << in[j].start << "," << in[j].end << ")" ;
        }
    }
};

int main()
{
    Solution s;
    vector<Interval> in;
    Interval i(1, 3);
    // Interval j(2, 6);
    // Interval k(8, 10);
    in.push_back(i);
    // in.push_back(j);
    // in.push_back(k);
    vector<Interval> res;
    res = s.merge(in);
    cout << "res size:" <<res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << "(" << res[i].start << "," << res[i].end << ")" << endl;
    }
    return 0;
}
