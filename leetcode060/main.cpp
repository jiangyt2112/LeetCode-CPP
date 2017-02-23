#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> per(n, 0);
        for (int i = 0; i < n; i++)
        {
            per[i] = i + 1;
        }
        for (int i = 1; i < k; i++)
        {
            next(per);
        }
        string res;
        for (int i = 0; i < n; i++)
        {
            res += (char)(per[i] + '0');
        }
        return res;
    }

    void next(vector<int> & per)
    {
        int n = per.size();
        int index;
        for (int i = n - 1; i > 0; i--)
        {
            if (per[i - 1] < per[i])
            {
                index = i - 1;
                break;
            }
        }
        int pos;
        for (int i = n - 1; i > index; i--)
        {
            if (per[i] > per[index])
            {
                pos = i;
                break;
            }
        }
        int tmp;
        tmp = per[index];
        per[index] = per[pos];
        per[pos] = tmp;
        sort(per.begin() + index + 1, per.end());
    }
};

int main()
{
    Solution s;
    cout << s.getPermutation(4, 24) << endl;
    return 0;
}
