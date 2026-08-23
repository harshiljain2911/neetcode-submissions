class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy;
        ListNode* ptr3 = &dummy;

        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                ptr3->next = list1;
                list1 = list1->next;
            }
            else
            {
                ptr3->next = list2;
                list2 = list2->next;
            }

            ptr3 = ptr3->next;
        }

        if(list1)
            ptr3->next = list1;
        else
            ptr3->next = list2;

        return dummy.next;
    }
};