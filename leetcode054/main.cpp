#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        int row = matrix.size();
        if (row == 0)
        {
            return result;
        }
        int col = matrix[0].size();
        int loops = row < col ? (row+1)/2 : (col+1)/2;
        // cout << loops << endl;
        int offset = 0;

        for (int i = 0; i < loops; i++)
        {
            offset = i;
            int nRow = row - 2*i;
            int nCol = col - 2*i;
            int num;
            // cout << i << endl;
            if (nRow == 1)
            {
                num = nCol;
            }
            else if (nCol == 1)
            {
                num = nRow;
            }
            else
            {
                num = nRow*2 + nCol*2 - 4;
            }
            for (int j = 0; j < num; j++)
            {
                if (j < nCol)
                {
                    result.push_back(matrix[offset][offset + j]);
                }
                else if (j < nRow + nCol - 1)
                {
                    result.push_back(matrix[offset + j - nCol + 1][col - offset - 1]);
                }
                else if (j < nRow + 2*nCol - 2)
                {
                    result.push_back(matrix[row - offset - 1][offset + nCol*2 + nRow - 3 - j]);
                }
                else
                {
                    result.push_back(matrix[offset + nRow*2 + nCol*2 - 4 - j][offset]);
                }
            }

        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> res;
    vector<vector<int> > matrix;
    for (int i = 0; i < 5; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < 1; j++)
        {
            tmp.push_back(j);
        }
        matrix.push_back(tmp);
    }
    res = s.spiralOrder(matrix);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
