#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int max_hour_num = 4;
const int max_minute_num = 6;
const int hour_num[] = {8, 4, 2, 1};
const int minute_num[] = {32, 16, 8, 4, 2, 1};

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        if (num >= 10)
        {
            return ret;
        }
        vector<string> hours;
        vector<string> minutes;
        for (int i = 0; i < max_hour_num; ++i)
        {
            if (num - i < max_minute_num)
            {
                hours = hour(i);
                minutes = minute(num - i);
                if (!hours.empty() && !minutes.empty())
                {
                    for (const auto& x : hours)
                    {
                        for (const auto& y : minutes)
                        {
                            if (y.size() == 1)
                            {
                                ret.push_back(x + ":0" + y);
                            }
                            else
                            {
                                 ret.push_back(x + ":" + y);
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
private:
    vector<string> hour(int n)
    {
        vector<int> hours;
        vector<string> ret;
        hour_(0, 0, n, hours);
        for (auto x : hours)
        {
            if (x <= 11)
            {
                ret.push_back(to_string(x));
            }
        }
        return ret;
    }
    vector<string> minute(int n)
    {
        vector<int> minutes;
        vector<string> ret;
        minute_(0, 0, n, minutes);
        for (auto x : minutes)
        {
            if (x <= 59)
            {
                ret.push_back(to_string(x));
            }
        }
        return ret;
    }
    void hour_(int pre, int start, int n, vector<int>& hours)
    {
        if (n == 0)
        {
            hours.push_back(pre);
            return;
        }
        if (start == max_hour_num || max_hour_num - start < n)
        {
            return;
        }
        for (int i = start; i < max_hour_num; ++i)
        {
            hour_(pre + hour_num[i], i + 1, n - 1, hours);
        }
    }
    void minute_(int pre, int start, int n, vector<int>& minutes)
    {
        if (n == 0)
        {
            minutes.push_back(pre);
            return;
        }
        if (start == max_minute_num || max_minute_num - start < n)
        {
            return;
        }
        for (int i = start; i < max_minute_num; ++i)
        {
            minute_(pre + minute_num[i], i + 1, n - 1, minutes);
        }
    }
};




int main()
{
    Solution s;
    vector<string> ret = s.readBinaryWatch(1);
    for (auto x : ret)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
