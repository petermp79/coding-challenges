/*
   Given the root of a binary tree, return the length of the diameter of the tree.

   The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
   This path may or may not pass through the root.

   The length of a path between two nodes is represented by the number of edges between them.


   Example 1:

              1
             / \
            2   3
           / \
          4   5


     Input: root = [1,2,3,4,5]
     Output: 3

   Explanation: 3is the length of the path [4,2,1,3] or [5,2,1,3].

   Example 2:
     Input: root = [1,2]
     Output: 1
*/

#include <iostream>

using namespace std;
 
/* Tree node structure used in the program */
struct TreeNode {
    int data;
    TreeNode* left, *right;
};


// TC O(n) SC O(1)
//
// The diameter of a tree is the number of nodes on the longest path 
// between two leaves in the tree. 
//
int getHeight(TreeNode *root, int& height) {
    int left, right;
    
    if (root == NULL)
        return 0;

    // Postorder traversal
   
    left = getHeight(root->left, height);
    right = getHeight(root->right, height); 
    
    // the longest path of 2 subtrees of root
    height = max(height, left + right); 
    
    // height of left and right subtree
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int height = 0;
    
    getHeight(root, height);
    
    return height;
}


struct TreeNode* newNode(int data)
{
    struct TreeNode* node = new TreeNode;
    node->data = data;
    node->left = node->right = NULL;
 
    return (node);
}
 
// Driver code
int main()
{
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    printf("Diameter is %d\n", diameterOfBinaryTree(root));
 
    return 0;
}




