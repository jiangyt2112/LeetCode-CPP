#include <iostream>
#include <vector>

using namespace std;

ostream& operator<< (ostream& out, const vector<int>& v)
{
    for (auto x : v)
    {
        out << x << " ";
    }
    out << endl;
    return out;
}


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(26, 0);
        int s_len = s.size();
        int p_len = p.size();
        vector<int> ret;
        if (p_len > s_len)
        {
            return ret;
        }
        for (int i = 0; i < p_len; ++i)
        {
            ++m[p[i] - 'a'];
        }
        vector<int> trav(26, 0);
        for (int i = 0; i < p_len; ++i)
        {
            ++trav[s[i] - 'a'];
        }
        // cout << m << trav << endl;
        if (m == trav)
        {
            ret.push_back(0);
        }
        for (int i = 1; i <= s_len - p_len; ++i)
        {
            --trav[s[i - 1] - 'a'];
            ++trav[s[i + p_len - 1] - 'a'];
            if (m == trav)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};



int main()
{
    Solution s;
    vector<int> ret = s.findAnagrams("cbaebabacd", "abc");
    for (auto x : ret)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
