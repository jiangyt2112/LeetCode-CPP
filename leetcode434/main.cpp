#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int ret = 0;
        int len = s.size();
        int i = 0;
        while (i < len)
        {
            if (s[i] != ' ')
            {
                ++ret;
                while (i < len && s[i] != ' ')
                {
                    ++i;
                }
            }
            else
            {
                ++i;
            }
        }
        return ret;
    }
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
