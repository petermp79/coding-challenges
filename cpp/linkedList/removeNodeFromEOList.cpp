/*

    LEETCODE# 19

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

    Example 1:

        Input: head = [1,2,3,4,5], n = 2
        Output: [1,2,3,5]

    Example 2:

        Input: head = [1], n = 1
        Output: []

    Example 3:

        Input: head = [1,2], n = 1
        Output: [1]
 

    Constraints:

        The number of nodes in the list is sz.
            1 <= sz <= 30
            0 <= Node.val <= 100
            1 <= n <= sz

    
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeNthFromEnd(ListNode* &head, int n) {
    
// TC = O(n) SC = O(n) 
// One pass - store traversed nodes in vector, node to delete is l-n.

    vector<ListNode *> nodes;
    ListNode *cur = head, *node;
    
    while (cur) {       // one pass - copy all nodes to a vector (array)
        nodes.push_back(cur);
        cur = cur->next;
    }
    
    // figure out what node to delete
    int i = nodes.size() - n;       // node to delete
    //cout << "Node to delete = " << nodes[i]->val << endl;
    
    // delete the node from linked list by linking prev node to node->next
    if (i > 0) {
        node = nodes[i-1];
        if (i < nodes.size()-1)
            node->next = nodes[i+1];
        else
            node->next = NULL;
    } 
    else if (i < 0) {   // invalid n, list length is less than n
        return head;
    }
    else { // i == 0    // remove head node, advance head to next node
        head = nodes[i]->next;
    }

/* 4ms - TC = O(2N) SC = O(1) (2 pass, no copy)
        ListNode* crr = head;
        int m = 0;
        int count;

        // Pass 1 - Determine the list length 
        while(crr) {  // 1st pass
            m++;
            crr = crr->next;
        }

        // Determine the orderth of to-be-deleted node from head of list
        count = m - n;
        if(m == 1) {
            return nullptr;
        }

        // Pass 2 - Traverse the list again to the node to delete
        crr = head;
        if(m == n) {
            return crr->next;
        }

        while(count-- > 1) {  // 2nd pass
            crr = crr->next;
        }
        crr->next = crr->next->next;
*/
    return head;
}

// Print a given list with heading
//
void printList(string heading, ListNode *l) {

    cout << heading;
    while (l) {
        cout << l->val << ", ";
        l = l->next;
    }
    cout << endl;
}

int main() {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    ListNode *head;
    ListNode *tail;

    int i = 1;
    while (i <= 10) {
        ListNode *node = new ListNode(i);
        cur->next = node;
        cur = node;
        i++;
    } 
    tail = cur;
    head = dummy.next;

    printList("Original List: ", head);
    removeNthFromEnd(head, 4);
    printList("4th node from tail removed: ", head);
    removeNthFromEnd(head, 7);
    printList("7th node from tail removed: ", head);
    removeNthFromEnd(head, 1);
    printList("1th node from tail removed: ", head);
    removeNthFromEnd(head, 7);
    printList("7th node from tail removed: ", head);
}


