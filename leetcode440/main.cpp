#include <iostream>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        // 生成算法会超时
        // 典型的Trie树
        // Trie树二分查找

        return find_k(0, n, k);
    }
// private:
    int find_k(int pre, int n, int k)
    {
        //cout << pre << endl;
        if (k == 0)
        {
            return pre;
        }
        if (pre > n)
        {
            return 0;
        }
        int sum_ = 0;
        for (int i = 0; i <= 9; ++i)
        {
            int tmp = sum(pre * 10 + i, n);
            cout << tmp << " " << pre * 10 + i << endl;
            sum_ += tmp;
            if (sum_ >= k)
            {
                return find_k(pre * 10 + i, n, k - sum_ + tmp - 1);
            }
        }
        return -1;
    }
//private:
    int sum(int pre, int n)
    {
        if (pre == 0)
        {
            return 0;
        }
        if (pre > n)
        {
            return 0;
        }
        int ret = 1;
        int base = 1;
        int tmp = pre;
        while (pre <= n)
        {
            pre *= 10;
            pre += 9;
            base *= 10;
            if (pre <= n)
            {
                ret += base;
            }
        }
        tmp /= 10;
        while (tmp != 0)
        {
            base *= 10;
            tmp /= 10;
        }

        ret += n % base + 1;
        return ret;
    }
};



int main()
{
    Solution s;
    cout << s.sum(10, 13) << endl;
    return 0;
}
