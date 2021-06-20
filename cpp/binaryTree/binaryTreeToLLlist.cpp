/*

   Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

   You can think of the left and right pointers as synonymous to the predecessor and successor pointers 
   in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is 
   the last element, and the successor of the last element is the first element.

   We want to do the transformation in place. After the transformation, the left pointer of the tree node 
   should point to its predecessor, and the right pointer should point to its successor. You should return 
   the pointer to the smallest element of the linked list.
*/
 
#include <iostream>

using namespace std;

/* A binary tree node has data, and left and right pointers */
struct TreeNode {
    int data;
    TreeNode* left, *right;
};
 
// A simple recursive function to convert a given Binary tree to Doubly Linked List
//
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list

TreeNode *head;
TreeNode *tail;

void inOrder(TreeNode *root)
{
    // Base case
    if (root == NULL) return;
 
    // Recursively convert left subtree
    inOrder(root->left);
 
    // Now convert this node
    if (tail == NULL)
        *head = root;
    else
    {
        root->left = tail;
        tail->right = root;
    }
    tail = root;        // tail is moving node after node to reflect the tail of LL

    // Finally convert right subtree
    inOrder(root->right);
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
TreeNode* newNode(int data)
{
    TreeNode* new_node = new TreeNode;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
 
/* Function to print nodes in a given doubly linked list */
void printList(TreeNode *head)
{
    TreeNode *tail = NULL;
    TreeNode *node = head;
    int count = 0;

    while (node!=NULL)
    {
        if (node == head) {
            if (++count == 3)   // loop 2 times to verify cyclic LL
                break;
        }
        cout << node->data << " ";
        node = node->right;
    }
    cout << endl;
}

/* Driver program to test above functions */

int main()
{
    // Let us create the tree shown in above diagram
    TreeNode *root        = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(6);
 
    // Convert to DLL
    inOrder(root);
    // Make it cyclic
    tail->right = head;
    head->left = tail;
 
    // Print the converted list
    printList(head);
 
    return 0;
}


