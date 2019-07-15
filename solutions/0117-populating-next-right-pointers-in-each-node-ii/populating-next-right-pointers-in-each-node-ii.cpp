// Given a binary tree
//
//
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
//
//
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
//  
//
// Example:
//
//
//
//
// Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
//
// Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}
//
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
//
//
//  
//
// Note:
//
//
// 	You may only use constant extra space.
// 	Recursive approach is fine, implicit stack space does not count as extra space for this problem.
//


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> Q;
        if(!root)
            return root;
        Q.push(make_pair(root,0));
        while(!Q.empty()){
            Node* ptr = Q.front().first;
            int level = Q.front().second;
            Q.pop();
            if(!Q.empty() and Q.front().second == level){
                ptr->next = Q.front().first;
            }
            if(ptr->left)
                Q.push(make_pair(ptr->left,level+1));
            if(ptr->right)
                Q.push(make_pair(ptr->right,level+1));
        }
        return root;
    }
};
