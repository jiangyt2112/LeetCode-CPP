#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ret = 0;
        int n = board.size();
        if (n == 0)
        {
            return ret;
        }
        int m = board[0].size();
        if (m == 0)
        {
            return ret;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0 ; j < m; ++j)
            {
                if (board[i][j] == 'X')
                {
                    if (i - 1 >= 0 && board[i - 1][j] == 'X')
                    {
                        continue;
                    }
                    if (j - 1 >= 0 && board[i][j - 1] == 'X')
                    {
                        continue;
                    }
                    ++ret;
                }
            }
        }
        return ret;
    }
};


int main()
{
    Solution s;
    //vector<vector<char>> board = {{'X",".",".","X"],[".",".",".","X"],[".",".",".","X"]};
    //cout << s.countBattleships(board) << endl;
    return 0;
}
