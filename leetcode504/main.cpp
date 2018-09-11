#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        int n = abs(num);
        if (n == 0)
        {
            return "0";
        }
        string ret;
        while (n != 0)
        {
            ret += to_string(n % 7);
            n /= 7;
        }
        if (num < 0)
        {
            ret += '-';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};


int main()
{
    Solution s;
    cout << s.convertToBase7(-7) << endl;
    return 0;
}
