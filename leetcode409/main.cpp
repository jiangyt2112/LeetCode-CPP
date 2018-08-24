#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unsigned int lower_case[26] = {0};
        unsigned int upper_case[26] = {0};
        for (auto x : s)
        {
            if (x >= 'a' && x <= 'z')
            {
                ++lower_case[x - 'a'];
            }
            else
            {
                ++upper_case[x - 'A'];
            }
        }
        int ret = 0;
        unsigned int mask = 0xfffffffe;
        for (int i = 0 ; i < 26; ++i)
        {
            ret += (lower_case[i] & mask) + (upper_case[i] & mask);
        }
        return ret < s.size() ? ret + 1 : ret;
    }
};



int main()
{
    Solution s;
    cout << s.longestPalindrome("") << endl;
    return 0;
}
