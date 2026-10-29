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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* d = new ListNode(-1,head);
        ListNode* groupPrev = d;

        while(true){
            ListNode* kth = getKth(groupPrev,k);
            if(!kth){
                break;
            }

            ListNode* groupNext = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;

            while(curr != groupNext){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        return d->next;

    }

    ListNode* getKth(ListNode* head, int k){
        while(head && k>0){
            head = head->next;
            k--;
        }
        return head;
    }
};
