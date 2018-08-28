#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        // zero one two three four five six seven eight nine
        // o 0 1 2 4
        // n 1 7 9 9
        // e 0 1 3 3 5 7 8 9
        // t 2 3 8
        // w 2
        // h 3 8
        // r 0 3 4
        // e 3 3 5 7 7 8 9
        // f 4 5
        // u 4
        // i 5 6 8 9
        // v 5 8 9
        // s 6 7
        // x 6
        // g 8
        // z 0
        // 2-w 4-u 6-x 8-g
        // 1-o-w-u
        // 3-r-u
        // 5-f-u
        // 7-s-x
        // 9-n-1-7
        vector<int> c(26, 0);
        for (auto x : s)
        {
            ++c[x - 'a'];
        }
        vector<int> n(10, 0);
        n[0] = c['z' - 'a'];
        n[2] = c['w' - 'a'];
        n[4] = c['u' - 'a'];
        n[6] = c['x' - 'a'];
        n[8] = c['g' - 'a'];
        n[1] = c['o' - 'a'] - n[0] - n[2] - n[4];
        n[3] = c['r' - 'a'] - n[0] - n[4];
        n[5] = c['f' - 'a'] - n[4];
        n[7] = c['s' - 'a'] - n[6];
        n[9] = (c['n' - 'a'] - n[1] - n[7]) >> 1;
        string ret;
        for (int i = 0; i < 10; ++i)
        {
            if (n[i] != 0)
            {
                ret.append(n[i], i + '0');
            }
        }
        return ret;
    }
};



int main()
{
    Solution s;
    cout << s.originalDigits("nine") << endl;
    return 0;
}
