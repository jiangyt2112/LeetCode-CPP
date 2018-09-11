#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        ret = 0;
        search_slice(A, 0, 0, 0, 0);
        return ret;
    }
private:
    void search_slice(const vector<int>& A, int cnt, int pre, int start, long long diff)
    {
        int n = A.size();
        if (start >= n)
        {
            return;
        }
        if (cnt == 0)
        {
            for (int i = 0; i < n; ++i)
            {
                search_slice(A, 1, A[i], i + 1, 0);
            }
            return;
        }
        else if (cnt == 1)
        {
            for (int i = start; i < n; ++i)
            {
                search_slice(A, 2, A[i], i + 1, (long long)A[i] - pre);
            }
            return;
        }
        else
        {
            for (int i = start; i < n; ++i)
            {
                if ((long long)A[i] - pre == diff)
                {
                    ++ret;
                    search_slice(A, cnt + 1, A[i], i + 1, diff);
                }
            }
            return;
        }
    }
private:
    int ret;
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
