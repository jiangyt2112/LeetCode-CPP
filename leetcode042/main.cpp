#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int nInitSum = 0;
        vector<int>::iterator iter;
        for (iter = height.begin(); iter < height.end(); iter++)
        {
            nInitSum += *iter;
        }
        int nLen = height.size();
        int i = 0;
        while (i < nLen)
        {
            int nMax = 0;
            int nIndex = i+1;
            int j;
            for (j = i+1; j < nLen; j++)
            {
                if (height[j] >= height[i])
                {
                    break;
                }
                if (height[j] > nMax)
                {
                    nMax = height[j];
                    nIndex = j;
                }
            }
            if (j == nLen)
            {
                // 未找到比当前值大的数
                if (nIndex == nLen)
                {
                    i++;
                }
                else
                {
                    for (int k = i+1; k < nIndex; k++)
                    {
                        height[k] = height[nIndex];
                    }
                    i = nIndex;
                }

            }
            else
            {
                // 找到了
                for (int k = i+1; k < j; k++)
                {
                    height[k] = height[i];
                }
                i = j;
            }
        }
        int nLastSum = 0;
        for (iter = height.begin(); iter < height.end(); iter++)
        {
            nLastSum += *iter;
        }
        return nLastSum - nInitSum;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    int re = s.trap(nums);
    cout << re << endl;
    return 0;
}
