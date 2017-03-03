#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n + 1, 0);
        num[0] = 1;
        num[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int sum = 0;
            for (int j = 1; j <= i; j++)
            {
                sum += num[j - 1] * num[i - j];
            }
            num[i] = sum;
        }
        return num[n];
    }
};

int main()
{
    Solution s;
    cout << s.numTrees(0) << endl;
    return 0;
}
