/*
    LEEDCODE# 92 (and 206)

    Given the head of a singly linked list and two integers left and right where left <= right, 
    reverse the nodes of the list from position left to position right, and return the reversed list.

    Example 1:

        Input: head = [1,2,3,4,5], left = 2, right = 4
        Output: [1,4,3,2,5]

    Example 2:

        Input: head = [5], left = 1, right = 1
        Output: [5]
 
    Constraints:

        The number of nodes in the list is n.
        1 <= n <= 500
        -500 <= Node.val <= 500
        1 <= left <= right <= n

*/

#include <iostream>

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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    
    ListNode *cur = head;
    ListNode *prev = NULL;
    ListNode *leftNext = NULL, *leftNode = NULL, *leftPrev = NULL;
    ListNode *rightNext = NULL, *rightNode = NULL, *rightPrev = NULL;
    int pos = 0;
    
    // Locate left and right position in linked list and record corresponding
    // prev, cur and next nodes.
    //
    while (cur) {
        pos++;
        if (pos == left) {
            leftNode = cur;
            leftPrev = prev;
            leftNext = cur->next;
        }
        if (pos == right) { // left and right nodes may be the same
            rightNode = cur;
            rightPrev = prev;
            rightNext = cur->next;
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    // Reverse linkedlist(left, right) -- see LEETCODE# 206
    prev = leftPrev;
    cur = leftNode;
    while (cur != rightNode) {
        ListNode *next = cur->next;
        cur->next = prev; // reverse next pointer
        prev = cur;
        cur = next;
    }
    
    // Connect right node to its prev node
    rightNode->next = prev;
    // Connect left prev node to right node
    if (leftPrev)
        leftPrev->next = rightNode;
    else 
        head = rightNode;
    // Connect left next node to right next node
    leftNode->next = rightNext;
    return head;
}

// Print a given list with heading
//
void printList(string heading, ListNode *l) {

    cout << heading << " [";
    while (l) {
        cout << l->val << ", ";
        l = l->next;
    }
    cout << "]" << endl;
}


int main() {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    ListNode *head;
    ListNode *tail;

    int i = 1;
    while (i <= 5) {
        ListNode *node = new ListNode(i);
        cur->next = node;
        cur = node;
        i++;
    }
    tail = cur;
    head = dummy.next;

    printList("Before --> ", head);
    head = reverseBetween(head, 2, 4);
    printList("After reversing nodes[2...4] --> ", head);

    // Change LL to single node LL [5] for next test case
    head->val = 5;
    head->next = NULL;

    // Should deallocate nodes after head here ... 

    printList("Before --> ", head);
    head = reverseBetween(head, 1, 1);
    printList("After reversing nodes[1...1] --> ", head);

    return 0; 
}



