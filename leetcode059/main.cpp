#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int counter = 1;
        int loops = (n + 1) / 2;
        int offset = 0;
        vector<int> tmp(n, 0);
        vector<vector<int> > res(n, tmp);

        for (int i = 0; i < loops; i++)
        {
            offset = i;
            int len = n - 2*i;
            int nums;
            if (len == 1)
            {
                nums = 1;
            }
            else
            {
                nums = 4*len - 4;
            }
            for (int j = 0; j < nums; j++)
            {
                if (j < len)
                {
                    res[offset][offset + j] = counter;
                    counter++;
                }
                else if (j < 2*len - 1)
                {
                    res[offset + j - len + 1][n - offset - 1] = counter;
                    counter++;
                }
                else if (j < 3*len - 2)
                {
                    res[n - offset - 1][3*len - 2 - j -1 + offset] = counter;
                    counter++;
                }
                else
                {
                    res[4*len - 4 - j + offset][offset] = counter;
                    counter ++;
                }
            }

        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > res;
    int n = 1;
    res = s.generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
