#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

       class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

Node *findMiddle(Node *head) {

    Node *tortoise = head;
    Node *hare = head;

    while(hare != NULL and hare -> next != NULL)
    {
        tortoise = tortoise -> next;
        hare = hare -> next -> next;
    }

    return tortoise;
}
