#include <iostream>
#include <string>

using namespace std;
enum STATE
{
    START, /* Start */
    T, /* True */
    NUM, /* number */
    DOT, /* dot */
    F, /* false */
    SIGN, /* sign */
    EXP, /* exp */
    INT /* whole num is int */
};
class Solution {
public:
    bool isNumber(string s) {
        // 词法自动机
        // 考虑空格
        int n = s.size();
        int start;
        int end;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                start = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                end = i;
                break;
            }
        }
        string str(s.begin() + start, s.begin() + end + 1);

        s = str;
        n = s.size();
        // cout << s << endl;
        int index = 0;
        STATE state = START;
        while (true)
        {
            switch (state)
            {
            case START:
                if (index == n)
                {
                    state = F;
                }
                else if (s[index] == '+' or s[index] == '-')
                {
                    state = SIGN;
                    index++;
                }
                else if (s[index] >= '0' and s[index] <= '9')
                {
                    state = NUM;
                    index++;
                }
                else if (s[index] == '.')
                {
                    index++;
                    if (index == n)
                    {
                        state = F;
                    }
                    else if (s[index] >= '0' and s[index] <= '9')
                    {
                        state = DOT;
                        index++;
                    }
                    else
                    {
                        state = F;
                    }
                }
                else
                {
                    state = F;
                }
                break;
            case SIGN:
                if (index == n)
                {
                    state = F;
                }
                else if (s[index] >= '0' and s[index] <= '9')
                {
                    state = NUM;
                    index++;
                }
                else if (s[index] == '.')
                {
                    index++;
                    if (index == n)
                    {
                        state = F;
                    }
                    else if (s[index]<= '9' and s[index] >= '0')
                    {
                        index++;
                        state = DOT;
                    }
                    else
                    {
                        state = F;
                    }
                }
                else
                {
                    state = F;
                }
                break;
            case NUM:
                if (index == n)
                {
                    state = T;
                }
                else if (s[index] >= '0' and s[index] <= '9')
                {
                    state = NUM;
                    index++;
                }
                else if (s[index] == '.')
                {
                    state = DOT;
                    index++;
                }
                else if (s[index] == 'e' or s[index] == 'E')
                {
                    state = EXP;
                    index++;
                }
                else
                {
                    state = F;
                }
                break;
            case DOT:
                if (index == n)
                {
                    state = T;
                }
                else if (s[index] >= '0' and s[index] <= '9')
                {
                    state = DOT;
                    index++;
                }
                else if (s[index] == 'e' or s[index] == 'E')
                {
                    state = EXP;
                    index++;
                }
                else
                {
                    state = F;
                }
                break;
            case EXP:
                if (index == n)
                {
                    state = F;
                }
                else if (s[index] >= '0' and s[index] <= '9')
                {
                    state = INT;
                    index++;
                }
                else if (s[index] == '+' or s[index] == '-')
                {
                    // state = INT;
                    index++;
                    if (index == n)
                    {
                        state = F;
                    }
                    else if (s[index] >= '0' and s[index] <= '9')
                    {
                        state = INT;
                        index++;
                    }
                    else
                    {
                        state = F;
                    }
                }
                else
                {
                    state = F;
                }
                break;
            case INT:
                if (index == n)
                {
                    state = T;
                }
                else if (s[index] >= '0' and s[index] <= '9')
                {
                    state = INT;
                    index++;
                }
                else
                {
                    state = F;
                }
                break;
            case F:
                return false;
                break;
            case T:
                return true;
                break;
            }
        }
    }
};


int main()
{
    double a =   -000152345E-1   ;
    cout << a << endl;
    Solution s;
    string str = "-.5 ";
    cout << s.isNumber(str) << endl;
    return 0;
}
