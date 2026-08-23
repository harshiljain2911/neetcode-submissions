class Solution {
public:

    ListNode* reverse_ll(ListNode* head) {
        if(!head) return head;

        ListNode *prev = NULL;
        ListNode *current = head;

        while(current != NULL)
        {
            ListNode *front = current->next;
            current->next = prev;
            prev = current;
            current = front;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if(!head || !head->next) return;

        ListNode *ptr1 = head;
        ListNode *ptr2;
        ListNode *slow = head;
        ListNode *fast = head;

        // Find middle
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ptr2 = reverse_ll(slow->next);

        // Split the two halves
        slow->next = NULL;

        // Merge alternately
        while(ptr1 && ptr2)
        {
            ListNode *temp1 = ptr1->next;
            ListNode *temp2 = ptr2->next;

            ptr1->next = ptr2;
            ptr2->next = temp1;

            ptr1 = temp1;
            ptr2 = temp2;
        }
    }
};