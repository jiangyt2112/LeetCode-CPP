#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        // 还是回溯
        if (word.size() == 0)
        {
            return true;
        }
        int n = board.size();

        if (n == 0)
        {
            return false;
        }

        int m = board[0].size();

        vector<int> tmp(m, 0);
        vector<vector<int> > visited(n, tmp);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    string tmp(word.begin() + 1, word.end());
                    visited[i][j] = 1;
                    // cout << tmp << endl;
                    if (trace(board, tmp, visited, i, j))
                    {
                        return true;
                    }
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }

    bool trace(vector<vector<char> >& board, string word, vector<vector<int> >& visited,
               int i, int j)
    {
        int n = word.size();

        if (n == 0)
        {
            return true;
        }
        // 向四周查找
        int height = board.size();
        int width = board[0].size();
        string tmpStr(word.begin() + 1, word.end());
        vector<vector<int> > mov;
        int a[] = {1, 0, 0, 1, -1, 0, 0, -1};
        vector<int> tmp2(a, a + sizeof(a) / sizeof(int));
        for (int k = 0; k < sizeof(a) / sizeof(int); k += 2)
        {
            vector<int> tmp(tmp2.begin() + k, tmp2.begin() + k + 2);
            mov.push_back(tmp);
        }

        for (int k = 0; k < mov.size(); k++)
        {
            int index1, index2;
            index1 = i + mov[k][0];
            index2 = j + mov[k][1];
            if (index1 < height and index1 >= 0 and index2 >= 0 and index2 < width
                and visited[index1][index2] == 0 and board[index1][index2] == word[0])
            {
                visited[index1][index2] = 1;
                bool flag = trace(board, tmpStr, visited, index1, index2);
                if (flag)
                {
                    return true;
                }
                visited[index1][index2] = 0;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > board;
    char a[] = {'a'} ;//, 'b', 'b'};
    vector<char> line1(a, a + sizeof(a) / sizeof(char));
    board.push_back(line1);

    string str = "a";
    cout << s.exist(board, str) << endl;
    return 0;
}
