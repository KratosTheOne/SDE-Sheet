#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge(Node* a, Node* b)
{
    if(a == NULL) return b;
    if(b == NULL) return a;

    Node* temp = new Node(0);
    Node* res = temp;

    while(a && b)
    {
        if(a -> data < b -> data)
        {
            temp -> child = a;
            temp = temp -> child;
            a = a -> child;
            temp -> next = NULL;
        }
        else
        {
            temp -> child = b;
            temp = temp -> child;
            b = b -> child;
            temp -> next = NULL;
        }
    }

    if(a) temp -> child = a;
    else temp -> child = b;

    return res -> child;
}

Node* flattenLinkedList(Node* head)
{
	if(!head || !head -> next)
        return head;

    head -> next = flattenLinkedList(head -> next);

    head = merge(head, head -> next);

    return head;
}
