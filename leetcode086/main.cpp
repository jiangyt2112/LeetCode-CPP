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
    ListNode* partition(ListNode* head, int x) {
        ListNode* greatHead = NULL;
        ListNode* smallHead = NULL;
        ListNode* greatTail = NULL;
        ListNode* smallTail = NULL;

        ListNode* trav = head;
        if (head == NULL)
        {
            return NULL;
        }
        while (trav != NULL)
        {
            ListNode* tmp = new ListNode(trav -> val);
            if (trav -> val < x)
            {
                if (smallHead == NULL)
                {
                    smallHead = tmp;
                    smallTail = tmp;
                }
                else
                {
                    smallTail -> next = tmp;
                    smallTail = tmp;
                }
            }
            else
            {
                if (greatHead == NULL)
                {
                    greatHead = tmp;
                    greatTail = tmp;
                }
                else
                {
                    greatTail -> next = tmp;
                    greatTail = tmp;
                }
            }
            trav = trav -> next;
        }
        if (smallHead == NULL)
        {
            return greatHead;
        }
        smallTail -> next = greatHead;
        return smallHead;
    }
};

int main()
{
    ListNode n1(2), n2(3), n3(1), n4(4);
    ListNode* head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    Solution s;
    ListNode* myhead;
    myhead = s.partition(head, 0);
    while (myhead != NULL)
    {
        cout << myhead -> val << " ";
        myhead = myhead -> next;
    }
    cout << endl;
    return 0;
}
