#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
        {
            return head;
        }
        ListNode* trav = head;

        ListNode* ptrM = NULL;
        ListNode* tmp = new ListNode(0);
        tmp -> next = head;
        head = tmp;
        ListNode* pre = head;
        ListNode* pre2 = head;
        int counter = 1;
        while (trav != NULL)
        {
            if (counter < m)
            {
                trav = trav -> next;
                pre = pre -> next;
                counter++;
            }
            else if (counter == m)
            {
                ptrM = trav;
                pre2 = ptrM;
                counter++;
                trav = trav -> next;
            }
            else if (counter <= n and counter > m)
            {
                ListNode* tail = trav -> next;
                pre -> next = trav;
                trav -> next = pre2;
                ptrM -> next = tail;
                pre2 = trav;
                trav = tail;
                counter++;
            }
            else
            {
                break;
            }
        }
        tmp = head;
        head = head -> next;
        delete tmp;
        return head;
    }
};

int main()
{
    ListNode n1(1), n2(2), n3(3), n4(4);
    ListNode* head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    Solution s;
    ListNode* res = s.reverseBetween(head, 1, 4);
    while (res != NULL)
    {
        cout << res -> val << " ";
        res = res -> next;
    }
    cout << endl;
    return 0;
}
