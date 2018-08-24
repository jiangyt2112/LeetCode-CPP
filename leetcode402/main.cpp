#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int i = 0;
        int len = num.size();
        while (i < len)
        {
            while (k > 0 && !s.empty() && num[i] < s.top())
            {
                s.pop();
                --k;
            }
            s.push(num[i++]);
        }
        while (k > 0)
        {
            s.pop();
            --k;
        }
        //cout << "aaa" << endl;
        string ret(s.size(), '0');
        for (int i = s.size() - 1; i >= 0; --i)
        {
            ret[i] = s.top();
            s.pop();
        }
        int index = 0;
        for (; index < ret.size(); ++index)
        {
            if (ret[index] != '0')
            {
                break;
            }
        }
        if (index == ret.size())
        {
            return "0";
        }
        return ret.substr(index, ret.size() - index);
    }
};



int main()
{
    Solution s;
    cout << s.removeKdigits("10", 0) << endl;
    return 0;
}
