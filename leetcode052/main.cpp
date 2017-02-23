#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n){
        int result = 0;
        vector<int> pos(n, 0);
        queen(result, 0, pos, n);
        return result;
    }

    void queen(int& result, int start, vector<int>& pos, int endPos)
    {
        if (start == endPos)
        {
            result++;
            return ;
        }
        for (int i = 0; i < endPos; i++)
        {
            pos[start] = i;
            if (check(pos, start))
            {
                queen(result, start + 1, pos, endPos);
            }
            else
            {
                continue;
            }
        }
        return ;
    }

    inline bool check(vector<int>&pos, int endPos)
    {
        for (int i = 0; i<= endPos; i++)
        {
            for (int j = i+1; j <= endPos; j++)
            {
                if (pos[j] == pos[i])
                {
                    return false;
                }
                if (pos[j] == pos[i] + j - i)
                {
                    return false;
                }
                if (pos[j] == pos[i] - (j - i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.totalNQueens(4) << endl;
    return 0;
}
