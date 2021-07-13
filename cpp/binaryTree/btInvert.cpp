/*

Given the root of a binary tree, invert the tree, and return its root.

Example 1:

    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]

Example 2:

    Input: root = [2,1,3]
    Output: [2,3,1]

Example 3:

    Input: root = []
    Output: []

*/

#include <iostream>

using namespace std;

// Invert subtrees
//
void invert(TreeNode *root) {
    if (root == NULL)
        return;
    
    TreeNode *tmp;
    
    // swap left and right
    tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    
    // traverse child node to do the same
    invert(root->left);
    invert(root->right);
}

// 
//
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL)
        return root;
    
    invert(root);
    return root;
}


