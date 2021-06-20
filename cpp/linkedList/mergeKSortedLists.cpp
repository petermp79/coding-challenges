/*

    LEETCODE# 23

    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

    Merge all the linked-lists into one sorted linked-list and return it.

 

    Example 1:

    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
        [
            1->4->5,
            1->3->4,
            2->6
        ]
    merging them into one sorted list:
        1->1->2->3->4->4->5->6

    Example 2:

    Input: lists = []
    Output: []

    Example 3:

    Input: lists = [[]]
    Output: []
 

    Constraints:

        k == lists.length
        0 <= k <= 10^4
        0 <= lists[i].length <= 500
        -10^4 <= lists[i][j] <= 10^4
        lists[i] is sorted in ascending order.
        The sum of lists[i].length won't exceed 10^4.

*/



#include <iostream>
#include <vector>
#include <map>

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

ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    if (lists.empty())
        return NULL;
    
/* 400ms - SC O(1)

    ListNode dummy(0);
    ListNode *tail = &dummy;
    int k = lists.size();
    int minListIndex = 0;
    
    while (minListIndex >= 0) {
        int minVal = INT_MAX;
        
        minListIndex = -1;
        // determine the next node in result list
        for (int i = 0; i < k; i++) {
            ListNode *l = lists[i];
            if (l == NULL)
                continue;
            
            // determine which list has the next min value
            //minVal = min(minVal, l->val);
            if (l->val < minVal) {
                minListIndex = i;
                minVal = l->val;
            }
        }
        //cout << minListIndex << "." << minVal << endl;
        // if a list has min value, dispatch the head node to result list
        // and move the list to next node in the list until the list exhausted
        if (minListIndex >= 0) {
            ListNode *l = lists[minListIndex];
            tail->next = l;
            tail = l;
            lists[minListIndex] = l->next;
        }
    }
    return dummy.next;
*/
    
/* 20ms - SC O(N) where N total number of nodes
    
    auto cmp = [](ListNode* a, ListNode* b) {
        return a->val > b->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);
    for(ListNode* node : lists) {
        if(node != nullptr) q.push(node);
    }
    ListNode dummy;
    ListNode* cur = &dummy;
    while(!q.empty()) {
        ListNode* tmp = q.top();
        q.pop();
        cur->next = tmp;
        cur = cur->next;
        if(tmp->next != nullptr) {
            q.push(tmp->next);
        }
    }
    return dummy.next;
*/

// 20ms - SC O(NlogN) where N is total nodes
//
// Add nodes from k lists to a multimap (binary tree) for sorting
// Scan thru map to construct a new link list with sorted items from map
    
    ListNode dummy(0);
    ListNode *cur = &dummy;
    multimap<int, ListNode *> m{};
    
    // For each list, add nodes from the list to map for sorting
    for (int i = 0; i < lists.size(); i++) {
        ListNode* l = lists[i];
        while (l) {
            //cout << l->val << endl;
            m.insert(make_pair(l->val, l));  // <key=value, value=node>
            l = l->next;
        }
    }
    
    // Scan thru sorted map of nodes to add nodes to dummy list
    for (auto &x : m) {
        cur->next = x.second;
        cur = cur->next;
    }
    return dummy.next;
    
}

int main() {
    int kLists = 0;
    int nNodes = 0;

    while (1) {
        cout << "Enter number of lists (^c to quit): ";
        cin >> kLists;
        cout << "Enter total number of nodes (^c to quit): ";
        cin >> nNodes;

        if (nNodes < kLists)
            cout << "*** Number of nodes must greater than number of lists.\n" << endl;
        else
            break;
    }

    vector<vector<int>> arrays(kLists, vector<int>{});
    vector<ListNode *>  lists{};
    for (int i = 0; i < kLists; i++) {
        for (int j = 0; j < nNodes/kLists; j++) {
            arrays[i].push_back(i+(j*kLists));
            //cout << i+(j*kLists) << ",";
        }
        cout << endl;
    }
    for (int i = 0; i < kLists; i++) {
        for (auto x : arrays[i]) {
            cout << x << ", ";
        }
        cout << endl;
    }
}


