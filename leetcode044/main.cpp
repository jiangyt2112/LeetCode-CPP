#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isMatch(string str1, string str2)
    {
        string::iterator iter;
        bool flag = false;
        string str;
        for (iter = str2.begin(); iter < str2.end(); iter++)
        {
            if (*iter != '*')
            {
                str += *iter;
                flag = false;
                continue;
            }
            else if (flag)
            {
                continue;
            }
            else
            {
                str += *iter;
                flag = true;
            }
        }
        return match(str1, str);
    }

    bool match(string str1, string str2)
    {


        if (str1.length() == 0 and str2.length() == 0)
        {
            return true;
        }
        if (str1.length() == 0 and str2.length() != 0)
        {
            string::iterator iter;
            for (iter = str2.begin(); iter < str2.end(); iter++)
            {
                if (*iter != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (str1.length() != 0 and str2.length() == 0)
        {
            return false;
        }
        if (str2[0] != '?' and str2[0] != '*')
        {
            if (str1[0] == str2[0])
            {
                string strTmp1(str1.begin()+1, str1.end());
                string strTmp2(str2.begin()+1, str2.end());
                return match(strTmp1, strTmp2);
            }
            return false;
        }
        if (str2[0] == '?')
        {
            string strTmp1(str1.begin()+1, str1.end());
            string strTmp2(str2.begin()+1, str2.end());
            return match(strTmp1, strTmp2);
        }
        if (str2[0] == '*')
        {
            if (str2.length() == 1)
            {
                return true;
            }
            else
            {
                int i;
                for (i = 0; i < str1.length(); i++)
                {
                    if (str1[i] == str2[1] or str2[1] == '?')
                    {
                        string strTmp1(str1.begin()+i, str1.end());
                        string strTmp2(str2.begin()+1, str2.end());
                        bool flag = match(strTmp1, strTmp2);
                        if (flag)
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            return false;
        }
    }
};

int main()
{
    Solution s;


    bool flag = s.isMatch("aaaaaaaaaaaaaaaaaaaaaaa",
                           "*a*a*a*a*a*a*a*a*");
    cout << flag << endl;
    return 0;
}
