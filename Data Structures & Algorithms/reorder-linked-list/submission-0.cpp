/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* reverse_ll(ListNode* head) {
        if(!head) return head;

        ListNode *prev = NULL;
        ListNode *current = head;

        while(current!=NULL)
        {
            ListNode *front = current->next;
            current->next = prev;
            prev = current;
            current = front;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        
        ListNode *ptr1 = head;
        ListNode *ptr2;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ptr2 = reverse_ll(slow->next);
        slow->next = NULL;

        while(ptr1 && ptr2)
        {
            ListNode *temp1 = ptr1->next;
            ListNode *temp2 = ptr2->next;

            ptr2->next = temp1;
            ptr1->next = ptr2;

            ptr1 = temp1;
            ptr2 = temp2;
        }



    }
};
