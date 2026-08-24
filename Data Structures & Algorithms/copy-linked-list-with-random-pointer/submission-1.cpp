/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head) return NULL;

        map<Node*, Node*> mp;

        Node* ptr = head;

        // Create copies
        while(ptr)
        {
            mp[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }

        // Connect next and random pointers
        ptr = head;

        while(ptr)
        {
            mp[ptr]->next = ptr->next ? mp[ptr->next] : NULL;
            mp[ptr]->random = ptr->random ? mp[ptr->random] : NULL;

            ptr = ptr->next;
        }

        return mp[head];
    }
};