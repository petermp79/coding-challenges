/*

    LEETCODE# 235

    Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the tree.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
    two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow 
    a node to be a descendant of itself).”

    Example 1:

    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    Output: 6
    Explanation: The LCA of nodes 2 and 8 is 6.

    Example 2:

    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    Output: 2
    Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according 
                to the LCA definition.

    Example 3:

    Input: root = [2,1], p = 2, q = 1
    Output: 2
 

    Constraints:

    The number of nodes in the tree is in the range [2, 105].
        -109 <= Node.val <= 109
        All Node.val are unique.
        p != q
        p and q will exist in the BST.

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

// Recursively traverse BST to locate LCA
//
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL)
        return NULL;
    
    // Check if LCA of p and q should be on the left or right subtree of root
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;    // either p or q is on the left w/ the other is on the right
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
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    cout << "Tree: [";
    printBSTbfs(root);
    cout << "]" << endl;

    cout << "LCA of 2 and 8: " << lowestCommonAncestor(root, root->left, root->right)->val << endl;
    cout << "LCA of 2 and 4: " << lowestCommonAncestor(root, root->left, root->left->right)->val << endl;

    return 0;
}


