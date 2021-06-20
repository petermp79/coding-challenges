/*
  Given the head of a singly linked list, reverse the list, and return the reversed list.

  Solution:

    Use 3 pointers: prev, cur, next to traverse through the list and reverse the pointers.

*/

#include <iostream>
#include <vector>

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

Node *reverseList(Node* head){
    // your code here
    Node *cur = head;
    Node *prev = NULL;

    while (cur) {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

void printList(Node *head) {
    Node *cur = head;
    while (cur) {
        cout << cur->data << ",";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    vector<int> list = {5, 3, 6, 4, 7 };
    Node *prev = NULL;
    Node *cur = NULL;
    Node *head = NULL;

    // Construct the linked list 
    for (int i : list) {
        cur = newNode(i);        
        if (prev)
            prev->next = cur; // sub-sequence node
        else
            head = cur;       // first node
        prev = cur;
    }
    printList(head);

    head = reverseList(head);
    printList(head);
}

