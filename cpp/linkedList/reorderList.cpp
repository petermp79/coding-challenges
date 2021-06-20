/*

    LEETCODE# 143

    You are given the head of a singly linked-list. The list can be represented as:

    L0 → L1 → … → Ln - 1 → Ln
    Reorder the list to be on the following form:

    L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
    You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

    Example 1:

    Input: head = [1,2,3,4]
    Output: [1,4,2,3]

    Example 2:

    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]
 

    Constraints:

    The number of nodes in the list is in the range [1, 5 * 104].
        1 <= Node.val <= 1000

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

void reorderList(ListNode* head) {
    vector<ListNode *> nodes;
    int nodeCnt = 0;
    
    if (!head)
        return;
    
    ListNode *cur = head;
    while (cur) {
        nodeCnt++;
        //cout << cur->val << ", ";
        nodes.push_back(cur);
        cur = cur->next;
    }
    //cout << endl << "Count: " << nodeCnt << endl;
    int left = 0;
    int right = nodeCnt -1;
    for (; left < right; left++, right--) {
        nodes[left]->next = nodes[right];
        //cout << left << "," << right << endl;
        if (right == left+1)
            nodes[right]->next = NULL;  // last node
        else
            nodes[right]->next = nodes[left+1]; 
    }
    // last node should always be NULL
    if (left == right)
        nodes[left]->next = NULL;
    
    //cout << left << "," << right << endl;
    return;
}

// Print a given list with heading
//
void printList(string heading, ListNode *l) {

    cout << heading << "[";
    while (l) {
        cout << l->val << ", ";
        l = l->next;
    }
    cout << "]" << endl;
}

int main() {
    ListNode dummy(0);
    ListNode *cur = &dummy; 
    int i = 1;

    while (i <= 4) {
        ListNode *node = new ListNode(i++);
        cur->next = node;
        cur = node;         
    }
    printList("Before reordering: ", dummy.next);
    reorderList(dummy.next);
    printList("After reordering: ", dummy.next);

    cur = dummy.next;
    while (cur) {
        ListNode *next = cur->next;
        delete(cur);
        cur = next;
    }

    dummy.next = NULL;
    cur = &dummy;
    i = 1;
    while (i <= 5) {
        ListNode *node = new ListNode(i++);
        cur->next = node;
        cur = node;         
    }
    printList("Before reordering: ", dummy.next);
    reorderList(dummy.next);
    printList("After reordering: ", dummy.next);
    return 0;
}


