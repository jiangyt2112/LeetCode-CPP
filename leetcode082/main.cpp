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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = NULL;
        ListNode* trav = head;
        ListNode* myhead = NULL;
        while (trav != NULL)
        {
            ListNode* tmp = trav -> next;
            bool flag = false;
            while (tmp != NULL and tmp -> val == trav -> val)
            {
                // cout << tmp -> val << " " << trav ->val << endl;
                tmp = tmp -> next;
                flag = true;
            }
            // cout << flag << endl;

            if (!flag)
            {
                ListNode* n = new ListNode(trav -> val);

                if (ptr == NULL)
                {
                    ptr = n;
                    myhead = ptr;
                }
                else
                {
                    ptr -> next = n;
                    ptr = n;
                }
            }
            trav = tmp;
        }
        /*while (head != NULL)
        {
            ListNode* tmp = head;
            delete tmp;
            head = head -> next;
        }*/
        return myhead;
    }
};

int main()
{
    Solution s;
    ListNode* head;
    ListNode n1(1), n2(1), n3(1), n4(1);
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    ListNode* myhead = s.deleteDuplicates(head);
    while (myhead != NULL)
    {
        cout << myhead -> val << " ";
        myhead = myhead -> next;
    }
    cout << endl;
    return 0;
}
