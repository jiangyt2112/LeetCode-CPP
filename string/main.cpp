#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 成员类型
    // 成员函数
    string s0;
    string s1(10, 'a');
    string s2(s1, 1, 2);
    cout << s2 << endl;
    cout << string::npos << endl;
    string s3("abcd");
    string s4("abcd", 3);
    cout << s4 << endl;
    string s5(s4.begin(), s4.end());
    string s6(s5);
    string s7 = {'a', 'b', 'c'};
    cout << s7 << endl;
    s0 = "abcd";
    s0 = s1;
    s0 = {'a', 'b', 'c'};
    s0 = 'a';
    cout << s0 << endl;
    // data c_str
    string s8;
    const char* p = s8.data();
    cout << (void*)p << endl;
    for (auto x = s0.begin(); x != s0.end(); ++x)
    {
        cout << *x << " ";
    }
    cout << endl;
    // empty size max_size reserve capacity shrink_to_fit
    cout << s0.empty() << endl;
    cout << s0.size() << endl;
    cout << s0.capacity() << endl;
    // clear
    s0.clear();
    // insert
    s0.insert(s0.begin(), 'a');
    s0.insert(s0.begin(), 10, 'a');
    s0.insert(s0.begin(), s1.begin(), s1.end());
    s0.insert(s0.begin(), {'a', 'b'});
    //s0.insert(100, 10 , 'n');
    // erase
    s0.erase(s0.begin());
    s0.erase(s0.begin(), s0.end());
    // push_back
    s0.push_back('a');
    // pop_back
    s0.pop_back();
    // append
    s0.append(1, 'a');
    // operator+=
    s0 += 'a';
    s0 += s0;
    s0 += "abc";
    s0 += {'a'};
    // substr
    cout << s0 << " " << s0.substr(0, 3) << endl;
    // copy
    char str[6];
    s0.copy(str, sizeof(str));
    str[5] = '\0';
    cout << str << endl;
    getline(cin, s0);
    cout << s0 << endl;
    return 0;
}
