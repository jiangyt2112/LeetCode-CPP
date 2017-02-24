#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int n = a.size();
        int m = b.size();
        int C = 0;
        int i = n - 1;
        int j = m - 1;
        int sum;
        while (true)
        {
            if (j >= 0 and i >= 0)
            {
                sum = (a[i] - '0') + (b[j] - '0') + C;
                int tmp = sum % 2;
                C = sum / 2;
                res.insert(res.begin(), tmp + '0');
                i--;
                j--;
            }
            else if (j >= 0)
            {
                sum = b[j] - '0' + C;
                int tmp = sum % 2;
                C = sum / 2;
                res.insert(res.begin(), tmp + '0');
                j--;
            }
            else if (i >= 0)
            {
                sum = a[i] - '0' + C;
                int tmp = sum % 2;
                C =sum / 2;
                res.insert(res.begin(), tmp + '0');
                i--;
            }
            else
            {
                if (C != 0)
                {
                    res.insert(res.begin(), C + '0');
                }
                break;
            }
        }
        return res;
    }
};

int main()
{
    string n1 = "1";
    string n2 = "1111";
    Solution s;
    cout << s.addBinary(n1, n2) << endl;
    return 0;
}
