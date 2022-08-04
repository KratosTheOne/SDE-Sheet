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

Node *getListAfterReverseOperation(Node *head, int n, int b[]){

    Node *dummy = new Node(0);
    dummy -> next = head;

    Node *curr = dummy, *nex = dummy, *pre = dummy;
    int count = 0;

    while(curr -> next != NULL)
    {
        curr = curr -> next;
        count++;
    }

    int j = 0;
    while(count > 0 && j < n)
    {
        curr = pre -> next;
        nex = curr -> next;

        int x = (b[j] <= count) ? b[j] : count;

        if(x == 0)
        {
            j++;
            continue;
        }

        for(int i = 1; i < x; i++)
        {
            curr -> next = nex -> next;
            nex -> next = pre -> next;
            pre -> next = nex;
            nex = curr -> next;
        }

        pre = curr;
        count -= b[j];
        j++;
    }

    return dummy -> next;
}
