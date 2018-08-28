#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr)
        {
            return head;
        }
        Node* trav = head;
        while (trav != nullptr)
        {
            if (trav->child != nullptr)
            {
                Node* flat_root = flatten(trav->child);
                Node* next = trav->next;
                trav->next = flat_root;
                flat_root->prev = trav;
                Node* flat_tail = flat_root;
                while (flat_tail->next != nullptr)
                {
                    flat_tail = flat_tail->next;
                }
                flat_tail->next = next;
                if (next != nullptr)
                {
                    next->prev = flat_tail;
                }
                trav->child = nullptr;
                trav = next;
            }
            else
            {
                trav = trav->next;
            }
        }
        return head;
    }
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
