#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> strs;
    for (int i = 0; i < 10; i++)
    {
        string str = "aa";
        strs.push_back(str + (char)(i + '0'));
    }
    for (int i = 0; i < 10; i++)
    {
        cout << strs[i] << endl;
    }
    /*
    for (int i = 0; i < 10; i++)
    {
        vector<string>::iterator iter;
        iter = strs.begin();
        strs.erase(iter + i);
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            cout << strs[i] << " " ;
        }
        cout << endl;
    }*/
    vector<string>::iterator iter;
    for (iter = strs.begin(); iter < strs.end(); iter++)
    {
        strs.erase(iter);
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            cout << strs[i] << " " ;
        }
        cout << endl;
    }
    return 0;
}
