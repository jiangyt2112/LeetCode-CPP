#include <iostream>
#include <vector>
#include <functional>
#include <memory>

using namespace std;

int main()
{
    weak_ptr<int> wp;
    {
        shared_ptr<int> sp(new int(43));
        cout << sp.use_count() << endl;
        wp = sp;
        cout << wp.use_count() << endl;
    }


    // cout << sp.use_count() << endl;
    cout << wp.use_count() << endl;

    return 0;
}
