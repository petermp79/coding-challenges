/*
    This problem was asked by Google.

    Given a linked list, sort it in O(n log n) time and constant space.
    
    For example, the linked list 4 -> 1 -> -3 -> 99 should become -3 -> 1 -> 4 -> 99.
*/
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
    ListNode* sortList(ListNode* head) {
        ListNode *current;
        
        if (head == NULL)
            return head;
        
        current = head;
        while (current) {
            ListNode *index = current->next;

            // Scan through remaining linked list
            while (index) {
                if (current->val > index->val) {
                    // Swap val of index with that of current 
                    int tmp = current->val;
                    current->val = index->val;
                    index->val = tmp;
                }
                index = index->next;
            }

            // Repeat with next node atfer current
            current = current->next;
        }
        return head;
    }
};


