// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
//
//
//
// Example:
//
// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while(l1){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* nptr = NULL;
        while(!st1.empty() or !st2.empty() or carry){
            int sum = 0;
            if(!st1.empty()){
                sum += st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                sum+= st2.top();
                st2.pop();
            }
            sum += carry;
            ListNode* ptr = new ListNode(sum%10);
            ptr->next = nptr;
            nptr = ptr;
            carry = sum/10;
        }
        return nptr;
    }
};
