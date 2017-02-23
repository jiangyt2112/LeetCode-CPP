#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int>::iterator iter;
        vector<int> mycan;
        for (iter = candidates.begin(); iter != candidates.end() ;iter++)
        {
            if (*iter <= target)
            {
                mycan.push_back(*iter);
            }
        }
        // cout << mycan.size() << endl;
        int len = mycan.size();
        if (len == 0)
        {
            vector<vector<int > > result;
            return result;
        }
        vector<vector<vector<int> > > A;
        vector<vector<int > > B;
        int index = 0;
        for (int i = 0; i < len; i++)
        {
            vector< vector<int> > tmp;
            for (int j = 0; j < target+1; j++)
            {
                vector<int> tmp2;
                tmp.push_back(tmp2);
            }
            A.push_back(tmp);
        }
        int last = mycan[len-1];
        for (int j = 1; j <= target; j++)
        {
            if (j % last != 0)
            {
                ;// A[len-1][j].push_back(-1);
            }
            else
            {
                A[len-1][j].push_back(index);
                index++;
                vector<int> tmp;
                for (int k = 0; k < j/last; k++)
                {
                    tmp.push_back(last);
                }
                B.push_back(tmp);
            }
        }
        for (int i = len - 2; i >= 0; i--)
        {
            for (int j = 1; j < target+1; j++)
            {
                int max_k = j/mycan[i] + 1;
                for (int k = 0; k < max_k; k++)
                {
                    if ((j - k*mycan[i]) == 0)
                    {
                        A[i][j].push_back(index);
                        index ++;
                        vector<int> tmp;
                        for (int h = 0; h < k; h++)
                        {
                            tmp.push_back(mycan[i]);
                        }
                        B.push_back(tmp);
                    }
                    else
                    {
                        vector<int> tmp;
                        tmp = A[i+1][j-k*mycan[i]];
                        if(tmp.size() == 0)
                        {
                            continue;
                        }
                        else
                        {
                            vector<int>::iterator iter;
                            for (iter = tmp.begin();iter < tmp.end();iter ++)
                            {
                                vector<int> tmp2 = B[*iter];
                                for(int h = 0; h < k; h++)
                                {
                                    tmp2.push_back(mycan[i]);
                                }
                                A[i][j].push_back(index);
                                index++;
                                B.push_back(tmp2);
                            }
                        }
                    }
                }
            }
        }
        vector<int> re = A[0][target];
        vector<vector<int> > result;
        if(re.size() == 0)
        {
            return result;
        }

        // vector<int>::iterator iter;

        for( iter = re.begin(); iter < re.end(); iter++)
        {
            result.push_back(B[*iter]);
        }

        return result;
    }
};
int main()
{
    Solution s;
    vector<int> num;
    num.push_back(2);
    //num.push_back(3);
    //num.push_back(6);
    //num.push_back(7);
    vector<vector<int> > re;
    re = s.combinationSum(num, 1);
    cout << re.size() << endl;
    vector<vector<int> >::iterator iter;
    for (iter = re.begin(); iter < re.end(); iter++)
    {
        vector<int>::iterator iter2;
        for (iter2 = (*iter).begin(); iter2 < (*iter).end(); iter2++)
        {
            cout << *iter2 << " ";
        }
        cout << endl;
    }
    return 0;
}

/* »ØËÝ·¨ */
/*
class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
		if  (!target) {
			res.push_back(combination);
			return;
		}
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
*/
