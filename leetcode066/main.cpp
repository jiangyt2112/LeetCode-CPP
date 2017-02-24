#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int C = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int sum;
            if (i == n - 1)
            {
                sum = digits[i] + 1 + C;
                digits[i] = sum % 10;
                C = sum / 10;
            }
            else
            {
                sum = digits[i] + C;
                digits[i] = sum % 10;
                C = sum / 10;
            }
        }
        if (C != 0)
        {
            digits.insert(digits.begin(), C);
        }
        return digits;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(0);
    // nums.push_back(9);
    Solution s;
    vector<int> res;
    res = s.plusOne(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    cout << endl;
    return 0;
}
