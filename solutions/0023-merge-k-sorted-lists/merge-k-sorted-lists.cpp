// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
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
    static bool cmp(pair<int,ListNode*> a, pair<int,ListNode*> b){
        return a.first > b.first;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<pair<int,ListNode*>> heap;
        ListNode* head = NULL;
        ListNode* ptr = NULL;
        for(int i = 0; i<lists.size(); i++){
            if(lists[i]){
                heap.push_back(make_pair(lists[i]->val,lists[i]));
                push_heap(heap.begin(),heap.end(),cmp);
            }
        }
        if(!heap.empty()){
            head = heap.front().second;
            ptr = heap.front().second;
            pop_heap(heap.begin(),heap.end(),cmp); heap.pop_back();
            if(head->next){
                heap.push_back(make_pair(head->next->val,head->next));
                push_heap(heap.begin(),heap.end(),cmp);
            }
        }
        while(!heap.empty()){
            ptr->next = heap.front().second;
            pop_heap(heap.begin(),heap.end(),cmp); heap.pop_back();
            ptr = ptr->next;
            if(ptr->next){
                heap.push_back(make_pair(ptr->next->val,ptr->next));
                push_heap(heap.begin(),heap.end(),cmp);
            }   
        }
        return head;
        
    }
};
