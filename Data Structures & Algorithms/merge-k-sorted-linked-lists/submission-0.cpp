class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode dummy;
        ListNode* ptr = &dummy;

        while (l1 && l2) {

            if (l1->val <= l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            }
            else {
                ptr->next = l2;
                l2 = l2->next;
            }

            ptr = ptr->next;
        }

        // Attach remaining part
        if (l1)
            ptr->next = l1;
        else
            ptr->next = l2;

        return dummy.next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty())
            return NULL;

        while (lists.size() > 1) {

            vector<ListNode*> newLists;

            // Merge lists in pairs
            for (int i = 0; i < lists.size(); i += 2) {

                if (i + 1 < lists.size()) {
                    ListNode* merged =
                        mergeTwoLists(lists[i], lists[i + 1]);

                    newLists.push_back(merged);
                }
                else {
                    // Odd list remains as it is
                    newLists.push_back(lists[i]);
                }
            }

            lists = newLists;
        }

        return lists[0];
    }
};