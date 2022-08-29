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
LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *pre = NULL, *curr = head, *nex;

    while(curr)
    {
        nex = curr -> next;
        curr -> next = pre;
        pre = curr;
        curr = nex;
    }

    return pre;
}

bool isPalindrome(LinkedListNode<int> *head) {
        if(head == NULL || head -> next == NULL)
            return true;

        LinkedListNode<int> *slow = head;
        LinkedListNode<int> *fast = head;

        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        slow -> next = reverse(slow -> next);
        slow = slow -> next;

        while(slow)
        {
            if(head -> data != slow -> data)
                return false;

            slow = slow -> next;
            head = head -> next;
        }

        return true;

}
