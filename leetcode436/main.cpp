#include <iostream>
#include <vector>
#include <algorithm>

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

class Inter
{
public:
    Interval inter;
    int index;
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> ret(n, -1);
        vector<Inter> inters(n);
        for (int i = 0; i < n; ++i)
        {
            inters[i].index = i;
            inters[i].inter = intervals[i];
        }
        // ÅÅÐò¶þ·Ö²éÕÒ
        sort(inters.begin(), inters.end(), [](const Inter& lht, const Inter& rht) {return lht.inter.start < rht.inter.start;});
        for (int i = 0; i < n; ++i)
        {
            vector<Inter>::iterator iter = lower_bound(inters.begin(), inters.end(), intervals[i].end, [](const Inter& lht, int val){return lht.inter.start < val;});
            if (iter != inters.end())
            {
                ret[i] = iter->index;
            }
        }
        return ret;
    }
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
