#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    Solution() /* ���캯������ʼ���ַ���Ϊ1 */
    {
        m_strCur = "1";
    }

    string countAndSay(int n) {

        for (int i = 1; i < n; i++)
        {
            sayStr();
        }
        return m_strCur;
    }

    void sayStr() /* �����������ַ�������ǰ�ַ����� */
    {
        string strTmp = "";
        int len = m_strCur.length();
        char ch = m_strCur[0];
        int i = 0;
        int nNum = 0;
        while (i < len)
        {
            if (ch != m_strCur[i])
            {
                string tmp;
                strTmp = strTmp + toString(nNum) + ch;

                ch = m_strCur[i];
                nNum = 0;
            }
            else
            {
                nNum ++;
                i++;
            }

        }
        if (nNum != 0)
        {
            string tmp;

            strTmp = strTmp + toString(nNum) + m_strCur[len - 1];

        }
        //cout << strTmp << endl;
        m_strCur = strTmp;
    }
    // C++11����ֱ��ʹ�� to_string
    string toString(int n) /* ʹ���������������ʱ��ǳ��� */
    {
        stringstream stream;
        stream << n;
        return stream.str();
    }

private:
    string m_strCur;
};

int main()
{
    Solution s;
    cout << s.countAndSay(5) << endl;
    return 0;
}
