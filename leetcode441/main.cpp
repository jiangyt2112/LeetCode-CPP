#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long start = 0;
        long long N = n;
        long long stop = min(N + 1, (long long)65536);
        while (start < stop)
        {
            long long mid = (start + stop) / 2;
            //cout << start << endl;
            if (sum(mid) <= n)
            {
                start = mid + 1;
            }
            else
            {
                stop = mid;
            }
        }
        //cout << start << endl;
        return start - 1;
    }
private:
    long long sum(long long n)
    {
        return (1 + n) * n / 2;
    }
};


int main()
{
    Solution s;
    cout << s.arrangeCoins(2147483647) << endl;
    return 0;
}
