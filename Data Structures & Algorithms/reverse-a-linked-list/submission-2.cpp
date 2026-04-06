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
    ListNode* reverseList(ListNode* head) {
        // curr will house which node we're currently at 
        ListNode* curr = head;

        // prev node will initially contain nullptr since when reversing we need a new "end"/nullptr.
        ListNode* prev = nullptr;

        // while curr is not nullptr
        while(curr){
            // temp points to the next node after curr
            ListNode *temp = curr->next;
            // curr's next points "behind", this is what reverses!
            curr->next = prev;
            // both below are setting up for next while iteration
            prev = curr;
            curr = temp;
        }

        // returning prev after we reversed the linked list
        return prev;
        


    }
};
