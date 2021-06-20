/*
    LEETCODE# 2

    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order, and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

    Example 1:

    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.

    Example 2:

    Input: l1 = [0], l2 = [0]
    Output: [0]

    Example 3:

    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]
 

    Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.

*/
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct LinkedList{
    Node* head;
};

Node* newNode(int data, Node* next = NULL){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = next;
    return node;
}

LinkedList newLinkedList(Node* head = NULL){
    LinkedList linkedList;
    linkedList.head = head;
    return linkedList;
}

LinkedList addTwoLinkedLists(LinkedList list1, LinkedList list2){
    // your code here
    LinkedList result = newLinkedList(NULL);
    Node *node1 = list1.head;
    Node *node2 = list2.head;
    Node *node3 = result.head;
    
    int carry;
    
    if (node1 == NULL && node2 == NULL) return result;
    if (node1 == NULL) return list2;
    if (node2 == NULL) return list1;
    
    while (node1 || node2 || carry) {
        int n1 = node1 ? node1->data : 0;
        int n2 = node2 ? node2->data : 0;
        int sum = n1 + n2 + carry;
        int n3 = sum / 10;
        carry = sum % 10;
        //cout << n3 << "." << carry << endl;
        Node *nNode = newNode(n3, NULL);
        if (result.head == NULL) {  // head
            result.head = nNode;
            node3 = nNode;
        }
        else {
            node3->next = nNode;
            node3 = nNode;
        }
        node1 = node1 ? node1->next : NULL;
        node2 = node2 ? node2->next : NULL;
    }
    return result;
}

int main() {
    // Construct list1 and list2

    // call addTwoLinkedList

}


