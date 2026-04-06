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
        
        // 1) Move first node n nodes forwards
        ListNode *first = head;

        while(n > 0){
            first = first->next;
            n--;
        }

        ListNode dummy(0);
        ListNode *res = &dummy;
        // 2) Add second node at head
        ListNode *second = head;
        // 3) Move first and second forward while first != nullptr;
        while(first != nullptr){
            res->next = second;
            res = res->next;
            first = first->next;
            second = second->next;
        }

        // At this point first will be right before the node that needs to be deleted, thus we can make second->next = first.
        second = second->next;
        res->next = second;
 

        return dummy.next; 


        




    }
};
