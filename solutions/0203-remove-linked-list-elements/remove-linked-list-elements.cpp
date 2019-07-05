// Remove all elements from a linked list of integers that have value val.
//
// Example:
//
//
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5
//
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = NULL;
        ListNode* realhead = NULL;
        while(head){
            if(head->val == val){
                ListNode* tmp = head;
                head = head->next;
                delete tmp;
                if(pre)
                    pre->next = head;
            }
            else{
                if(!realhead)
                    realhead = head;
                pre = head;
                head = head->next;
            }
        }
        return realhead;
    }
};
