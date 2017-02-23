#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // 字符串相乘，大整数相乘
        if (num1.length() < num2.length())
        {
            string tmp = num2;
            num2 = num1;
            num1 = tmp;
        }
        string res = "";
        if (num1[0] == '0' or num2[0] == '0')
        {
            return "0";
        }
        for (int i = num2.length()-1; i >= 0; i--)
        {
            string strLine;
            multiStrCh(num1, num2[i], strLine);
            addStr(res, strLine, num2.length()-i-1);
        }
        // 去除前导零
        string myres;
        string::iterator iter;
        for (iter = res.begin(); iter < res.end(); iter++)
        {
            if (*iter != '0')
            {
                break;
            }
        }
        for ( ; iter < res.end(); iter++)
        {
            myres += *iter;
        }
        return myres;
    }

    void addStr(string &res, string &line, int start)
    {
        vector<int> vecRes;
        vector<int> vecLine;
        string::iterator iter;
        for (iter = res.begin(); iter < res.end(); iter++)
        {
            vecRes.push_back(*iter - '0');
        }
        for (iter = line.begin(); iter < line.end(); iter++)
        {
            vecLine.push_back(*iter - '0');
        }
        for (int i = 0; i < start; i++)
        {
            vecLine.push_back(0);
        }
        int C = 0;
        int nLen1 = vecRes.size();
        int nLen2 = vecLine.size();
        int i = nLen1 - 1;
        int j = nLen2 - 1;
        vector<int> result;
        while (i >= 0 and j >= 0)
        {
            int tmp = vecRes[i] + vecLine[j] + C;
            C = tmp/10;
            tmp = tmp - C*10;
            result.insert(result.begin(), tmp);
            i--;
            j--;
        }
        if (i == -1 and j == -1)
        {
            result.insert(result.begin(), C);
            // result.push_front(C);
        }
        else
        {
            if (i != -1)
            {
                while(i >= 0)
                {
                    int tmp = vecRes[i] + C;
                    C = tmp/10;
                    tmp = tmp - C*10;
                    result.insert(result.begin(), tmp);
                    // result.push_front(tmp);
                    i--;
                }
                if (C != 0)
                {
                    result.insert(result.begin(), C);
                    // result.push_front(C);
                }
            }
            else
            {
                while(j >= 0)
                {
                    int tmp = vecLine[j] + C;
                    C = tmp/10;
                    tmp = tmp - C*10;
                    result.insert(result.begin(), tmp);
                    // result.push_front(tmp);
                    j--;
                }
                if (C != 0)
                {
                    result.insert(result.begin(), C);
                    // result.push_front(C);
                }
            }
        }
        string strResult = "";
        vector<int>::iterator iter2;
        for (iter2 = result.begin(); iter2 < result.end(); iter2++)
        {
            strResult += (char)(*iter2 + '0');
        }
        res = strResult;
        // cout << res << endl;
    }

    void multiStrCh(string &str, char ch, string & result)
    {
        // 字符ch 与字符串str相乘
        vector<int> nums;
        int n = ch - '0';
        string::iterator iter;
        for (iter = str.begin(); iter < str.end(); iter++)
        {
            nums.push_back(*iter - '0');
        }
        vector<int> res;
        int C = 0;
        vector<int>::reverse_iterator riter;
        for (riter = nums.rbegin(); riter < nums.rend(); riter++)
        {
            int tmp = (*riter) * n;
            tmp += C;
            C = tmp/10;
            tmp = tmp - C*10;
            res.insert(res.begin(), tmp);
            // res.push_front(tmp);
        }
        if (C != 0)
        {
            res.insert(res.begin(), C);
            // res.push_front(C);
        }
        string strRes = "";
        vector<int>::iterator iter2;
        for (iter2 = res.begin(); iter2 < res.end(); iter2++)
        {
            strRes += (char)(*iter2+'0');
        }
        result = strRes;
        // cout << result << endl;
    }
};
int main()
{
    Solution s;
    cout << s.multiply("237", "284") << endl;
    cout << 123*23 << endl;
    return 0;
}
// 精简版本
/*
string multiply(string num1, string num2) {
    string sum(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            sum[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        sum[i] += carry;
    }

    size_t startpos = sum.find_first_not_of("0");
    if (string::npos != startpos) {
        return sum.substr(startpos);
    }
    return "0";
}

*/
