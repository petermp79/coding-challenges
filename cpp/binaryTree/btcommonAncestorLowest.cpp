/*

    LEETCODE# 236

    Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
    two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow 
    a node to be a descendant of itself).”

 

    Example 1:

    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
    Explanation: The LCA of nodes 5 and 1 is 3.

    Example 2:

    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    Output: 5
    Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to 
                the LCA definition.
    
    Example 3:

    Input: root = [1,2], p = 1, q = 2
    Output: 1

Constraints:

    The number of nodes in the tree is in the range [2, 105].
        -109 <= Node.val <= 109
        All Node.val are unique.
        p != q
        p and q will exist in the tree.

*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//
// Use inorder traversal to find the nodes
// Keep record of the path leading to the nodes
//
bool findPath(TreeNode *root, TreeNode *k, vector<TreeNode *> &path) {
    if (root == NULL) {
        return false;
    }
    
    // cout << "push: " << root->val << endl;
    // Recrod this node in path
    path.push_back(root);
    
    // inorder traversal
    if (root == k)     
        return true;    // found it 
    
    // check if k is in the left branch?
    if (findPath(root->left, k, path))    // visit left
        return true;
    
    // check if k is in the right branch?
    if (findPath(root->right, k, path))  // visit right
        return true;
    
    // k is not present in this (sub)tree, remove it from path
    // cout << "pop: " << root->val << endl;
    path.pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode *> path1, path2;
 
    // Find paths from root to n1 and root to n2. If either n1 or n2
    // is not present, return -1
    if ( !findPath(root, p, path1) || !findPath(root, q, path2)) {
        return NULL;
    }
  
    int len = min(path1.size(), path2.size());
    int i;
    for (i = 0; i < len; i++) {
        //cout << path1[i]->val << " " << path2[i]->val << endl;
        if (path1[i] != path2[i]) {
            break;
        }
    }
    return path1[i-1];  // return node above two distinct nodes
}

// Traverse a BST BFS and print every node
//
void printBSTbfs(TreeNode *root) {
    deque<TreeNode *> queue;

    queue.push_back(root);

    while(!queue.empty()) {
        TreeNode *node = queue.front();
        queue.pop_front();
        if (node == NULL) {
            cout << "null,";
            continue;
        }
        cout << node->val << ",";
        queue.push_back(node->left);
        queue.push_back(node->right);
    }
}

int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    cout << "Tree: [";
    printBSTbfs(root);
    cout << "]" << endl;

    cout << "LCA of 5 and 1: " << lowestCommonAncestor(root, root->left, root->right)->val << endl;
    cout << "LCA of 5 and 4: " << lowestCommonAncestor(root, root->left, root->left->right->right)->val << endl;

    return 0;
}


