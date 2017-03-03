#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        string::iterator iterBegin = s.begin();
        string::iterator iterEnd = s.end();
        vector<string> res;
        if (n < 4 or n > 12)
        {
            return res;
        }
        // cout << "aaa" << endl;
        for (int i = 1; i <= n - 3; i++)
        {
            for (int j = i + 1; j <= n - 2; j++)
            {
                for (int k = j + 1; k <= n - 1; k++)
                {

                    string str1(iterBegin, iterBegin + i);
                    string str2(iterBegin + i, iterBegin + j);
                    string str3(iterBegin + j, iterBegin + k);
                    string str4(iterBegin + k, iterEnd);
                    // cout << str1 << " " << str2 << " " << str3 << " " << str4 << endl;
                    if (valid(str1) and valid(str2) and valid(str3) and valid(str4))
                    {
                        res.push_back(str1 + "." + str2 + "." + str3 + "." + str4);
                    }
                }
            }
        }
        return res;
    }

    bool valid(string s)
    {
        // 前导0问题
        int n = s.size();
        if (n != 1 and s[0] == '0')
        {
            return false;
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum *= 10;
            sum += s[i] - '0';
        }
        if (sum >= 0 and sum <= 255)
        {
            return true;
        }
        return false;
    }
};

#include "show.h"
int main()
{
    Solution s;
    vector<string> res;
    res = s.restoreIpAddresses("010010");
    show(res);
    // cout << s.valid("255") << endl;
    return 0;
}
