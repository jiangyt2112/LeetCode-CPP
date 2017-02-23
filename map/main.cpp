#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> m;
    m['a'] = 2;
    m['b'] = 3;
    cout << m.size() << endl;
    cout << m['a'] << endl;
    cout << m['c'] << endl;
    map<char, int>::iterator iter = m.find('a');
    m['d']++;
    cout << m['d'] << endl;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        cout << (*iter).first << endl;
    }
    return 0;
}
