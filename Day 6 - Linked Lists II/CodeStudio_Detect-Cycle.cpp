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

bool detectCycle(Node *head)
{
	if(head == NULL)
        return false;

    Node* slow = head;
    Node* fast = head;

    while(fast -> next != NULL && fast -> next -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) return true;
    }

    return false;
}
