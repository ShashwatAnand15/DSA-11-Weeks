https://leetcode.com/problems/delete-node-in-a-linked-list/

// Steps involved:
// 1) Find out the next node of the pointer to the node that we have.
// 2) Copy the data from the next node to the node to be deleted.
// 3) Fix the link and delete the next node

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
    void deleteNode(ListNode* node) {
        // if(node->next == NULL) delete node;   // if the tail node is to be deleted
        struct ListNode *temp = node->next;      // can also simply use ListNode *temp = node->next;
        node->val = temp->val;    // you can either copy or swap(node->val, temp->val) as you wish coz no effect
        node->next = temp->next; 
        delete temp;              // A good practice to free the memory
    }
};
 
// Since it is guaranteed that the node to be deleted is not the last node
// (we have used method 3 from deletion.cpp file)
 