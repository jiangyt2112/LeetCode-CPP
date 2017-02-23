#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> Map;
        vector<int> res;
        int N = words.size();
        if (N == 0)
        {
            return res;
        }
        int WordLen = words[0].size();
        if (s.size() < N*WordLen)
        {
            return res;
        }
        for (int i = 0; i < N; i++)
        {
            Map[words[i]]++;
        }
        for (int i = 0; i < s.size() - N*WordLen + 1; i++)
        {
            string::iterator start;
            start = s.begin() + i;
            map<string, int> tmp = Map;
            for ( int j = 0; j < N; j++)
            {
                string str(start + j*WordLen, start + (j+1)*WordLen);
                tmp[str] --;
            }
            map<string, int>::iterator mapIter;
            bool flag = false;
            for (mapIter = tmp.begin(); mapIter != tmp.end(); mapIter++)
            {
                if (mapIter->second != 0)
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> res;
    vector<string> words;
    string str = "dddddddddddddddddddddddddddddddddddddddddddddddddd";
    words.push_back("ddd");
    words.push_back("ddd");
    words.push_back("ddd");
    words.push_back("ddd");
    words.push_back("ddd");
    words.push_back("ddd");
    words.push_back("ddd");
    res = s.findSubstring(str, words);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
