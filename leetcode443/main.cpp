#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int pre = 0;
        int start = 0;
        while (start < n)
        {
            int cnt = 1;
            int trav = start + 1;
            while (trav < n && chars[trav] == chars[start])
            {
                ++trav;
                ++cnt;
            }

            if (cnt != 1)
            {
               string tmp = to_string(cnt);
               chars[pre] = chars[start];
               ++pre;
               copy(tmp.begin(), tmp.end(), chars.begin() + pre);
               pre += tmp.size();
            }
            else
            {
                chars[pre] = chars[start];
                ++pre;
            }
            start = trav;
        }
        return pre;
    }
};

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
    Solution s;
    cout << s.compress(chars) << endl;
    for (auto x : chars)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
