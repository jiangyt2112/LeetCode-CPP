#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void show(vector<vector<int> >& matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
        cout << endl;
        }
    }

    void rotate(vector<vector<int> >& matrix) {
        // ÈýÖØÑ­»·
        int nTmp;
        int nHalfN = matrix.size() / 2;
        int N = matrix.size();
        //cout << "nHalfN" << nHalfN << endl;
        for (int i = 0; i< 3; i++)
        {


        for (int i = 0; i < nHalfN; i++)
        {
            int len = N - 2*i;
            int nRotate = len - 1;
            //cout << "len:" << len << endl;
            //cout << "nRotate:" << nRotate << endl;
            int offset = i;
            //cout << "offset:" << offset << endl;
            int nNum = len*4 - 4;
            //cout << "nNum:" << nNum << endl;
            for (int j = 0; j < nRotate; j++)
            {
                int LeftTop = matrix[i][i];
                for (int k = 0; k < nNum-1; k++)
                {

                    if (k < len - 1)
                    {
                        // cout << matrix[offset][offset + k] << " ";
                        matrix[offset][offset + k] = matrix[offset][offset + k + 1];
                        //cout << "(" << offset << "," <<offset + k << ")";
                        //cout << "-";
                        //cout << "(" << offset << "," <<offset + k + 1 << ")";
                    }
                    else if (k < 2*len - 2)
                    {
                        // cout << matrix[offset + k - len + 1][offset + len - 1] << " ";
                        matrix[offset + k - len + 1][offset + len - 1] =
                        matrix[offset + k - len + 2][offset + len - 1];
                        //cout << "(" << offset + k - len + 1 << "," <<offset + len - 1 << ")";
                        //cout << "-";
                        //cout << "(" << offset + k - len + 2 << "," <<offset + len - 1 << ")";
                    }
                    else if (k < 3*len - 3)
                    {
                        // cout << matrix[len - 1 - offset][3*len - 2 - k - 1 + offset] << " ";
                        matrix[len - 1 + offset][3*len - 3 - k + offset] =
                        matrix[len - 1 + offset][3*len - 4 - k + offset];
                        //cout << "(" << len - 1 - offset << "," <<3*len - 3 - k + offset << ")";
                        //cout << "-";
                        //cout << "(" << len - 1 - offset << "," <<3*len - 4 - k + offset << ")";
                    }
                    else
                    {
                        // cout << matrix[4*len - 4 - k + offset][offset] << " ";
                        matrix[4*len - 4 - k + offset][offset] =
                        matrix[4*len - 5 - k + offset][offset];
                        //cout << "(" << 4*len - 4 - k + offset << "," << offset << ")";
                        //cout << "-";
                        //cout << "(" << 4*len - 5 - k + offset << "," << offset << ")";
                    }
                }
                //cout << endl;
                matrix[i + 1][i] = LeftTop;
                // cout << endl;
                //cout << "i:" << i << "j:" << j << endl;
                //show(matrix);
            }
            //cout << i << endl;
            //show(matrix);
        }
        }

    }
};

int main()
{
    vector<vector<int> > nums;
    for (int i = 0; i < 5; i++)
    {
        vector<int> tmp;
        nums.push_back(tmp);
        for (int j = 0; j < 5; j++)
        {
            nums[i].push_back(j);
        }
    }
    int n = nums.size();
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }*/
    Solution s;
    s.show(nums);
    s.rotate(nums);
    s.show(nums);

    return 0;
}
