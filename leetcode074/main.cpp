#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        // ¶þ·Ö²éÕÒ
        int n = matrix.size();
        if (n == 0)
        {
            return false;
        }
        int m = matrix[0].size();
        int end = n * m;
        int start = 0;
        int mid = (end + start) / 2;
        bool flag = false;
        while (start != end)
        {
            int row = mid / m;
            int col = mid - row*m;
            if (matrix[row][col] == target)
            {
                flag = true;
                break;
            }
            else if (matrix[row][col] > target)
            {
                end = mid;
                mid = (start + end) / 2;
            }
            else
            {
                start = mid + 1;
                mid = (start + end) / 2;
            }

        }
        return flag;
    }
};

int main()
{
    Solution s;
    int m = 3, n = 4;
    vector<int> tmp(n, 0);
    vector<vector<int> > matrix;//(m, tmp);
    //matrix[2][1] = 2;
    cout << s.searchMatrix(matrix, 2) << endl;
    return 0;
}
