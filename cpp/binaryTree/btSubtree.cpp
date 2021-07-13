/*

Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T 
is a tree S consisting of a node in T and all of its descendants in T. 

The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node 
is called a proper subtree.

The idea is based on the fact that inorder and preorder/postorder uniquely identify a binary tree. 
Tree S is a subtree of T if both inorder and preorder traversals of S arew substrings of inorder and 
preorder traversals of T respectively.

Following are detailed steps.

1) Find inorder and preorder traversals of T, store them in two auxiliary arrays inT[] and preT[].
2) Find inorder and preorder traversals of S, store them in two auxiliary arrays inS[] and preS[].
3) If inS[] is a subarray of inT[] and preS[] is a subarray preT[], then S is a subtree of T. Else not.

We can also use postorder traversal in place of preorder in the above algorithm.

*/


#include <cstring>
#include <iostream>

using namespace std;
#define MAX 100
 
// Structure of a tree node
struct Node {
    char key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST node
Node* newNode(char item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to store inorder traversal of tree rooted
// with root in an array arr[]. Note that i is passed as reference
void storeInorder(Node* root, char arr[], int& i)
{
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    storeInorder(root->left, arr, i);
    arr[i++] = root->key;
    storeInorder(root->right, arr, i);
}
 
// A utility function to store preorder traversal of tree rooted
// with root in an array arr[]. Note that i is passed as reference
void storePreOrder(Node* root, char arr[], int& i)
{
    if (root == NULL) {
        arr[i++] = '$';
        return;
    }
    arr[i++] = root->key;
    storePreOrder(root->left, arr, i);
    storePreOrder(root->right, arr, i);
}
 
/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(Node* T, Node* S)
{
    /* base cases */
    if (S == NULL)
        return true;
    if (T == NULL)
        return false;
 
    // Store Inorder traversals of T and S in inT[0..m-1]
    // and inS[0..n-1] respectively
    int m = 0, n = 0;
    char inT[MAX], inS[MAX];
    storeInorder(T, inT, m);
    storeInorder(S, inS, n);
    inT[m] = '\0', inS[n] = '\0';
 
    // If inS[] is not a substring of inT[], return false
    if (strstr(inT, inS) == NULL)
        return false;
 
    // Store Preorder traversals of T and S in preT[0..m-1]
    // and preS[0..n-1] respectively
    m = 0, n = 0;
    char preT[MAX], preS[MAX];
    storePreOrder(T, preT, m);
    storePreOrder(S, preS, n);
    preT[m] = '\0', preS[n] = '\0';
 
    // If preS[] is not a substring of preT[], return false
    // Else return true
    return (strstr(preT, preS) != NULL);
}
 
// Driver program to test above function
int main()
{
    Node* T = newNode('a');
    T->left = newNode('b');
    T->right = newNode('d');
    T->left->left = newNode('c');
    T->right->right = newNode('e');
 
    Node* S = newNode('a');
    S->left = newNode('b');
    S->left->left = newNode('c');
    S->right = newNode('d');
 
    if (isSubtree(T, S))
        cout << "Yes: S is a subtree of T" << endl;
    else
        cout << "No: S is NOT a subtree of T" << endl;
 
    return 0;
}



