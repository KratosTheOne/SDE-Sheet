#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    if(head == NULL || k == 0)
        return head;

    LinkedListNode<int> *start = new LinkedListNode<int>(-1);
    start -> next = head;
    LinkedListNode<int> *slow = start;
    LinkedListNode<int> *fast = start;

    for(int i = 1; i <= k; i++)
        fast = fast -> next;

    while(fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next;
    }

    slow -> next = slow -> next -> next;

    return start -> next;
}
