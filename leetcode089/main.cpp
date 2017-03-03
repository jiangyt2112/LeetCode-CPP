#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        // gray code Gi = Bi xor Bi+1 (0 <= i < n)
        vector<int> res;
        int total = pow(2, n);

        for (int i = 0; i < total; i++)
        {
            int nGray = 0;
            int mask = 1;
            for(int j = 0; j < n; j++)
            {
                if(((i & mask) xor ((i & (mask<<1)) >> 1)) != 0)
                {
                    nGray = nGray | mask;
                }
                mask = mask << 1;
            }
            res.push_back(nGray);
        }
        return res;
    }
};

int main()
{
    // int n = pow(2, 10);
    // cout << n << endl;
    Solution s;
    vector<int> res;
    res = s.grayCode(3);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
