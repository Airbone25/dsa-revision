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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int size = 0;
        while(temp){
            size++;
            temp = temp->next;
        }

        ListNode* d = new ListNode(-1);
        d->next = head;
        ListNode* p = d;
        ListNode* t = d->next;

        for(int i=1;i<(size-n+1);i++){
            t = t->next;
            p = p->next;
        }

        p->next = t->next;
        t->next = NULL;
        delete t;

        return d->next;

    }
};
