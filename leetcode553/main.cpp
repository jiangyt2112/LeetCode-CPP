#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        vector<int> prio(n, 0);
        for (int i = 1; i <= n; ++i)
        {
            prio[i - 1] = i;
        }

    }
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
