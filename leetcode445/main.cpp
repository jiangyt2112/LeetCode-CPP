#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr || l2 == nullptr)
        {
            return nullptr;
        }
        ListNode* ret = nullptr;
        int len1 = 0;
        int len2 = 0;
        ListNode* tmp = l1;
        while (tmp != nullptr)
        {
            ++len1;
            tmp = tmp->next;
        }
        tmp = l2;
        while (tmp != nullptr)
        {
            ++len2;
            tmp = tmp->next;
        }
        if (len1 < len2)
        {
            swap(l1, l2);
            swap(len1, len2);
        }
        ListNode* trav1 = l1;
        ListNode* trav2 = l2;
        for (int i = 0; i < len1 - len2; ++i)
        {
            if (ret == nullptr)
            {
                ret = new ListNode(trav1->val);
            }
            else
            {
                ListNode* tmp = new ListNode(trav1->val);
                tmp->next = ret;
                ret = tmp;
            }
            trav1 = trav1->next;
        }
        int carry = 0;
        while (trav1 != nullptr && trav2 != nullptr)
        {
            int v = trav1->val + trav2->val + carry;
            if (v >= 10)
            {
                carry = 1;
                v %= 10;
            }
            else
            {
                carry = 0;
            }
            ListNode* tmp = new ListNode(v);
            if (ret == nullptr)
            {
                ret = tmp;
            }
            else
            {
                tmp->next = ret;
                ret = tmp;
            }
            if (carry)
            {
                ListNode* trav = ret;
                while (carry)
                {
                    if (trav->next == nullptr)
                    {
                        trav->next = new ListNode(1);
                        carry = 0;
                    }
                    else
                    {
                        int v = trav->next->val;
                        v += 1;
                        if (v == 10)
                        {
                            trav->next->val = 0;
                        }
                        else
                        {
                            trav->next->val = v;
                            carry = 0;
                        }
                    }
                    trav = trav->next;
                }
            }
            trav1 = trav1->next;
            trav2 = trav2->next;
        }
        tmp = ret;
        ret = nullptr;
        while (tmp != nullptr)
        {
            if (ret == nullptr)
            {
                ret = tmp;
                tmp = tmp->next;
                ret->next = nullptr;
            }
            else
            {
                ListNode* t = tmp;
                tmp = tmp->next;
                t->next = ret;
                ret = t;
            }
        }
        return ret;
    }
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
