#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n1 = num1.size();
        int n2 = num2.size();
        int i = 0;
        int j = 0;
        int carry = 0;
        string ret;
        while (i < n1 && j < n2)
        {
            int sum = num1[i] - '0' + num2[i] - '0' + carry;
            if (sum >= 10)
            {
                ret.push_back('0' + sum % 10);
                carry = sum / 10;
            }
            else
            {
                carry = 0;
                ret.push_back('0' + sum);
            }
            ++i;
            ++j;
        }
        while (i < n1)
        {
            int sum = num1[i] - '0' + carry;
            if (sum >= 10)
            {
                ret.push_back('0' + sum % 10);
                carry = sum / 10;
            }
            else
            {
                carry = 0;
                ret.push_back('0' + sum);
            }
            ++i;
        }
        while (j < n2)
        {
            int sum = num2[j] - '0' + carry;
            if (sum >= 10)
            {
                ret.push_back('0' + sum % 10);
                carry = sum / 10;
            }
            else
            {
                carry = 0;
                ret.push_back('0' + sum);
            }
            ++j;
        }
        if (carry)
        {
            ret.push_back('0' + carry);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};



int main()
{
    Solution s;
    cout << s.addStrings("999", "1111") << endl;
    return 0;
}
