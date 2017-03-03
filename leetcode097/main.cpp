#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();
        int t = s3.size();
        if (n == 0 and m == 0 and t == 0)
        {
            return true;
        }
        if (n + m != t )
        {
            return false;
        }
        for (int i = 1; i <= n; i++)
        {

            if (s3.compare(0, i, s1, 0 , i) == 0)
            {
               string str1(s1.begin() + i, s1.end());
               string str3(s3.begin() + i, s3.end());
               bool flag = isInterleave(str1, s2, str3);
               if (flag)
               {
                   return true;
               }
            }
            break;
        }
        for (int i = 1; i <= m; i++)
        {

            if (s3.compare(0, i, s2, 0 , i) == 0)
            {
               string str2(s2.begin() + i, s2.end());
               string str3(s3.begin() + i, s3.end());
               bool flag = isInterleave(s1, str2, str3);
               if (flag)
               {
                   return true;
               }
            }
            break;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.isInterleave("", "a", "a") << endl;
    return 0;
}
