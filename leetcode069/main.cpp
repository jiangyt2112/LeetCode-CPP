#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)
        {
            return -1;
        }
        if (x == 0 or x == 1)
        {
            return x;
        }
        int s = 1;
        int t = min(x/2, 100000);
        int mid = (s + t) / 2;
        double tmp, tmp2;
        double mul, mul2;
        while (s != t)
        {
            tmp = mid;
            mul = tmp * tmp;
            tmp2 = mid + 1;
            mul2 = tmp2 * tmp2;

            if (x >= mul and x < mul2)
            {
                break;
                // return mid;
            }
            else if (x < mul)
            {
                t = mid ;
                mid = (s + t) / 2;
            }
            else
            {
                s = mid + 1;
                mid = (s + t) / 2;
            }
        }
        return mid;
    }

};

int main()
{
    Solution s;
    cout << s.mySqrt(2147395599) << endl;
    // int a = 2147395599; //46399 * 46399
    // cout << a << endl;
    return 0;
}
