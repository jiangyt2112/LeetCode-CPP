#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n)
    {
        if (n < 0)
        {

            return 1 / Pow(x, -n);
        }
        return Pow(x, n);
    }
    double Pow(double x, int n) {
        if (n == 0)
        {
            return 1;
        }
        if (x == 0)
        {
            return 0;
        }
        if ((n & 1) == 1)
        {
            // ÆæÊý
            double re = Pow(x, n/2);
            return re * re * x;
        }
        else
        {
            double re = Pow(x, n/2);
            return re * re;
        }
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2, 2147483647) << endl;
    return 0;
}
