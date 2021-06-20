/* C++ program to print level
    order traversal using STL */
//#include <bits/stdc++.h>
#include <iostream>
#include <deque>

using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Iterative method to find height of Binary Tree
void printLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL)  return;
 
    // Create an empty queue for level order traversal
    deque<Node *> q;
 
    // Enqueue Root and initialize height
    q.push_back(root);
 
    while (q.empty() == false)
    {
        // Get front of queue node
        Node *node = q.front();

        // print this node
        cout << node->data << " ";

        // when done, remove it from top of queue
        q.pop_front();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push_back(node->left);
 
        /* Enqueue right child */
        if (node->right != NULL)
            q.push_back(node->right);

        // repeat until queue is empty
    }
    cout << endl;
}
 
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}



