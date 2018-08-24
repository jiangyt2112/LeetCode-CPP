#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ret = 0;
        int n = A.size();
        if (n < 3)
        {
            return ret;
        }
        int start = 0;
        while (start < n - 2)
        {
            int diff = A[start + 1] - A[start];
            int stop = start + 1;
            while (stop < n && A[stop] - A[stop - 1] == diff)
            {
                ++stop;
            }
            if (stop - start > 2)
            {
                ret += (1 + stop - start - 2) * (stop - start - 2) / 2;
                start += stop - start - 1;
            }
            else
            {
                ++start;
            }
        }
        return ret;
    }
};



int main()
{
    Solution s;
    vector<int> A = {1, 2, 3, 5, 7, 9};
    cout << s.numberOfArithmeticSlices(A) << endl;
    return 0;
}
