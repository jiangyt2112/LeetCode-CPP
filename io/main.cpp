#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <iomanip>

using namespace std;

int main()
{
    // istream is;
    ios::app;
    ios::hex;
    // good eof bad fail
    cout << cout.good() << cout.bad() << cout.fail() << endl;
    // put
    cout.put(1);
    // failbit
    cout << cout.failbit;
    // write
    cout.write("abcdef", 3);
    // tellp seekp 查询和设置输出buf的位置
    cout << cout.tellp() << endl;
    cout << 10;
    cout << cout.tellp() << endl;
    // flush
    cout << "aaaaaaaaaa";
    // Sleep(10000);
    cout << "bbbbbbbbbbbbbb";
    cout.flush();
    cout << endl;
    // rdstate setstate clear
    cout << cout.rdstate() << endl;
    // cout.setstate(ios_base::eofbit);
    cout << ios_base::goodbit << ios_base::badbit << ios_base::failbit << ios_base::eofbit << endl;
    // fill 设置填充字符
    cout << setw(10) << 10 << endl;
    cout.fill('x');
    cout << setw(10) << 10 << endl;
    cout << cout.fill() << endl;
    // rdbuf tie
    ostringstream os;
    os << "abcd" << endl;
    cout << os.str() << endl;
    // get
    char ch = cin.get();
    cin.get(ch);
    // cin.get()
    cout << cin.peek() << endl;
    // getline()
    return 0;
}
