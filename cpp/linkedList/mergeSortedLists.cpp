/*
    LEETCODE# 21

    Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing 
    together the nodes of the first two lists.

 

    Example 1:

        Input: l1 = [1,2,4], l2 = [1,3,4]
        Output: [1,1,2,3,4,4]

    Example 2:

        Input: l1 = [], l2 = []
        Output: []

    Example 3:

        Input: l1 = [], l2 = [0]
        Output: [0]

    Constraints:

        The number of nodes in both lists is in the range [0, 50].
                -100 <= Node.val <= 100
                Both l1 and l2 are sorted in non-decreasing order.

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

// Create a list of items 
//
ListNode *createList(vector<int> items) {
    ListNode dummy;
    ListNode *list = &dummy;
    
    for (auto i : items) {
       list->next = new ListNode(i);
       list = list->next; 
    }
    return dummy.next;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *result = NULL;
    ListNode *cur = NULL;
    ListNode *tmp = NULL;

    if (!l1)
        return l2;
    if (!l2)
        return l1;
    
    // Create new list started with dummy node
    ListNode dummy(INT_MIN);
    
    cur = &dummy;
    
    // Traverse through l1 and l2 while doing comparison and select next node 
    // to append to new list
    //
    // For k sorted lists, at each node, find the node with min val to insert to dummy list until
    // all lists exhausted but one. Assume the head node of the lists are stored in a vector,
    // at each iteration head node is replaced with the next one in the list until it is null
    // (end of list).
    //
    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;
        }
        else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    result = dummy.next;

    return result;
}

int main() {
    ListNode list1(INT_MIN);
    ListNode list2(INT_MIN);

    ListNode *l1 = &list1;
    ListNode *l2 = &list2;

    int i = 0;
    // Create list 1
    while (i < 20) {
        if (i % 2 == 1) {
            // Odd list
            l1->next = new ListNode(i);
            l1 = l1->next;
        }
        else {
            // Even list
            l2->next = new ListNode(i);
            l2 = l2->next;
        }
        i++;
    }

    printList("List1: ", list1.next);
    printList("List2: ", list2.next);

    ListNode *result = mergeTwoLists(list1.next, list2.next);

    printList("Merged: ", result);

}

