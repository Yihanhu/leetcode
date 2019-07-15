// Sort a linked list in O(n log n) time using constant space complexity.
//
// Example 1:
//
//
// Input: 4->2->1->3
// Output: 1->2->3->4
//
//
// Example 2:
//
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        int n = 0;
        ListNode* ptr = head;
        while(ptr){
            ptr = ptr->next;
            n++;
        }
        return generate(head,n);
    }
    
    ListNode* generate(ListNode* head, int n){
        if(n == 0){return NULL;}
        if(n == 1){
            head->next = NULL;
            return head;
        }
        
        ListNode* ptr = head;
        int half = n/2;
        for(int i=0;i<half;i++){
            ptr = ptr->next;
        }
        ListNode* head1 = generate(head,half);
        ListNode* pttr = head1;
        ListNode* head2 = generate(ptr,n-half);
        if(head1->val>head2->val){
            ptr = head2;
            head2 = head2->next;
        }
        else{ptr = head1;head1 = head1->next;}
        ListNode* ret = ptr;
        while(head1 and head2){
            // cout<<ptr->val;
            if(head1->val>head2->val){
                ptr->next = head2;
                head2 = head2->next;
            }
            else{ptr->next = head1;head1 = head1->next;}
            ptr = ptr->next;
        }
        if(head1){
            ptr->next = head1;
        }
        else{ptr->next = head2;}
        ListNode* tmp = ret;
        return ret;
    }
};

