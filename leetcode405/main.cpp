#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const char base_char[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

class Solution {
public:
    string toHex(int num) {
        string ret;
        unsigned int mask = 0xf;
        unsigned int n = num;
        while (n != 0)
        {
            ret.push_back(base_char[n & mask]);
            n >>= 4;
        }
        reverse(ret.begin(), ret.end());
        return ret.empty() ? "0" : ret;
    }
};


int main()
{
    Solution s;
    cout << s.toHex(-1) << endl;
    return 0;
}
