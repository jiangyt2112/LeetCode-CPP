#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
public:
    TrieNode(): zero(nullptr), one(nullptr), end_zero(false), end_one(false) {}
public:
    TrieNode* zero;
    TrieNode* one;
    bool end_zero;
    bool end_one;
};


class Trie
{
public:
    Trie(): root(nullptr) {}
    int push(unsigned int n)
    {
        TrieNode** trav = &root;
        unsigned int mask = 1 << 31;
        for (int i = 0; i < 32; ++i)
        {
            if (*trav == nullptr)
            {
                *trav = new TrieNode();
            }
            if (n & mask)
            {
                if (i == 31)
                {
                    (*trav)->end_one = true;
                    //cout << "bbb" << endl;
                }
                else
                {
                    trav = &((*trav)->one);
                }
            }
            else
            {
                if (i == 31)
                {
                    (*trav)->end_zero = true;
                    //cout << "bbb" << endl;
                }
                else
                {
                    trav = &((*trav)->zero);
                }
            }
            mask >>= 1;
        }
        mask = 1 << 31;
        trav = &root;
        int ret = 0;
        for (int i = 0 ; i < 32; ++i)
        {

            if (n & mask)
            {
                if (i == 31)
                {
                    if (!(*trav)->end_zero)
                    {
                        ret |= mask;
                    }
                }
                else
                {
                    if ((*trav)->zero != nullptr)
                    {
                        trav = &((*trav)->zero);
                    }
                    else
                    {
                        trav = &((*trav)->one);
                        ret |= mask;
                    }
                }

            }
            else
            {
                if (i == 31)
                {
                    if ((*trav)->end_one)
                    {
                        ret |= mask;
                        //cout << "aaa" << endl;
                    }
                }
                else
                {
                    if ((*trav)->one != nullptr)
                    {
                        trav = &((*trav)->one);
                        ret |= mask;
                    }
                    else
                    {
                        trav = &((*trav)->zero);
                    }
                }

            }
            mask >>= 1;
        }
        //cout << ret << endl;
        return ret ^ n;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // ×ÖµäÊ÷ TrieÊ÷
        Trie t;
        int ret = 0;
        int n = nums.size();
        for (int i = 0 ; i < n; ++i)
        {
            int tmp = t.push(nums[i]);
            //cout << tmp << endl;
            ret = max(ret, tmp);
        }
        return ret;
    }
};



int main()
{
    vector<int> nums = {4};
    Solution s;
    cout << s.findMaximumXOR(nums) << endl;
    return 0;
}
