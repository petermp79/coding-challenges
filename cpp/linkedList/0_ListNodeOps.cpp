
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

// Create a linked list of items from a given array of items 
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


