#include <iostream>
#include <iterator>
#include <vector>
#include <array>

using namespace std;

int main()
{
    // advance distance next prev
    vector<int> v = {1, 2, 3, 4};
    vector<int>::iterator iter = v.begin();
    advance(iter, 1);
    cout << *iter << endl;
    advance(iter, -1);
    cout << *iter << endl;
    cout << distance(v.begin(), v.end()) << endl;
    iter = next(iter, 2);
    cout << *iter << endl;
    iter = next(iter, -1);
    cout << *iter << endl;
    iter = prev(iter);
    cout << *iter << endl;
    // reverse_iterator
    vector<int>::reverse_iterator riter = v.rbegin();
    cout << *riter << endl;
    cout << riter[0] << endl;
    // back_insert_iterator back_inserter front_insert_iterator front_inserter
    // insert_iterator inserter
    back_insert_iterator<vector<int>> viter(v);
    *viter = 10;
    cout << v.back() << endl;
    viter = back_inserter(v);
    // istream_iterator ostream_iterator istreambuf_iterator ostreambuf_iterator
    // istream_iterator<int> iiter(cin);
    // cout << *iiter << endl;
    // ++iiter;
    // cout << *iiter << endl;
    ostream_iterator<int> citer(cout, " ");
    *citer = 10;
    *citer = 20;
    return 0;
}
