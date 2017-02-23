#include <iostream>

using namespace std;

/**/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* tmp = head;
        if (head == NULL)
        {
            return NULL;
        }
        while (tmp != NULL)
        {
            n ++;
            tmp = tmp -> next;
        }
        k = k % n;
        if (k == 0 or n == k)
        {
            return head;
        }

        int index = n - k;
        tmp = head;
        ListNode* pre;
        for (int i = 0; i < index; i++)
        {
            pre = head;
            head = head -> next;
        }
        pre -> next = NULL;
        ListNode* tmp2 = head;
        while (tmp2 -> next != NULL)
        {
            tmp2 = tmp2 -> next;
        }
        tmp2 -> next = tmp;
        return head;
    }
};

int main()
{
    Solution s;
    ListNode * head;
    ListNode n1(1), n2(2), n3(3), n4(4);
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    ListNode * res;
    res = s.rotateRight(head, 5);
    while (res != NULL)
    {
        cout << res -> val << " ";
        res = res -> next;
    }
    return 0;
}
