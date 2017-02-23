#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        int start = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                start = i;
                break;
            }
        }
        int len = 0;
        if (start == -1)
        {
            return 0;
        }
        else
        {
            for (int i = start; i >= 0; i--)
            {
                if (s[i] != ' ')
                {
                    len ++;
                }
                else
                {
                    break;
                }
            }
        }

        return len;
    }
};

int main()
{
    string str = "";
    Solution s;
    cout << s.lengthOfLastWord(str) << endl;
    return 0;
}
