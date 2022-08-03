#include <bits/stdc++.h>
/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1 -> data > l2 -> data) swap(l1, l2);

    Node<int> *res = l1;

    while(l1 && l2)
    {
        Node<int> *temp = NULL;

        while(l1 && l1 -> data <= l2 -> data)
        {
            temp = l1;
            l1 = l1 -> next;
        }

        temp -> next = l2;
        swap(l1, l2);
    }

    return res;

    /*
    Node<int> *dummy, *dd;
    dummy = new Node<int>(-1);
    dd = dummy;

    while(first && second)
    {
        if(first -> data < second -> data)
        {
            dd -> next = first;
            first = first -> next;
        }
        else
        {
            dd -> next = second;
            second = second -> next;
        }
        dd = dd -> next;
    }
    if(first) dd -> next = first;
    if(second) dd -> next = second;

    return dummy -> next;
    */
}

