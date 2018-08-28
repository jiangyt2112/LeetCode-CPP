#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, vector<string>> m;
        int len = bank.size();
        for (int i = 0 ; i < len; ++i)
        {
            if (can_mute(start, bank[i]))
            {
                m[start].push_back(bank[i]);
            }
        }
        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (can_mute(bank[i], bank[j]))
                {
                    //cout << bank[i] << bank[j] << endl;
                    m[bank[i]].push_back(bank[j]);
                    m[bank[j]].push_back(bank[i]);
                }
            }
        }
        queue<string> q;
        q.push(start);
        unordered_set<string> touch;
        touch.insert(start);
        int ret = 0;
        while (!q.empty())
        {
            int cnt = q.size();
            ++ret;
            for (int i = 0; i < cnt; ++i)
            {
                for (const auto& x : m[q.front()])
                {
                    if (touch.find(x) == touch.end())
                    {
                        q.push(x);
                        touch.insert(x);
                        if (x == end)
                        {
                            return ret;
                        }
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
//private:
    bool can_mute(const string& from, const string& to)
    {
        if (from.size() != to.size())
        {
            return false;
        }
        int len = from.size();
        int diff = 0;

        for (int i = 0; i < len; ++i)
        {
            if (from[i] != to[i])
            {
                ++diff;
                if (diff > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};



int main()
{
    Solution s;
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    // cout << s.can_mute("AACCGGTT", "AACCGGTA") << endl;
    cout << s.minMutation("AACCGGTT", "AAACGGTA", bank) << endl;
    return 0;
}
