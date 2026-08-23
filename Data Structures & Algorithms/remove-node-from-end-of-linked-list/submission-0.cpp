class Solution {
public:

    ListNode* reverse_ll(ListNode* head) {
        if(!head) return head;

        ListNode* prev = NULL;
        ListNode* current = head;

        while(current != NULL)
        {
            ListNode* front = current->next;
            current->next = prev;
            prev = current;
            current = front;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        head = reverse_ll(head);

        ListNode* ptr = head;
        ListNode* prev = NULL;

        while(n != 1)
        {
            prev = ptr;
            ptr = ptr->next;
            n--;
        }

        // deleting first node of reversed list
        if(prev == NULL)
        {
            head = ptr->next;
        }
        else
        {
            prev->next = ptr->next;
        }

        head = reverse_ll(head);

        return head;
    }
};