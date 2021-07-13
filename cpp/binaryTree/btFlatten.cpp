/*

    LEETCODE# 114

    Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to 
    the next node in the list and the left child pointer is always null.

    The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

    Example 1:

    Input: root = [1,2,5,3,4,null,6]
    Output: [1,null,2,null,3,null,4,null,5,null,6]

    Example 2:

    Input: root = []
    Output: []

    Example 3:

    Input: root = [0]
    Output: [0]
 

    Constraints:

    The number of nodes in the tree is in the range [0, 2000].
        -100 <= Node.val <= 100
 

    Follow up: Can you flatten the tree in-place (with O(1) extra space)?

*/

#include <iostream>
#include <deque>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    
void flatten(TreeNode* root) {
    
    if (root == NULL)
        return;
    
    if (!root->left && !root->right)
        return;     // leaf node
    
    // if root->left exists then we have to make it root->right
    if (root->left != NULL) {
 
        // Traverse left recursively before we change root pointers
        flatten(root->left);

        // Rearrange root pointer according to spec
        struct TreeNode* tmpRight = root->right;    // save root->right for relocation
        
        // now, make root->right points to root->left and root->left NULL
        root->right = root->left;
        root->left = NULL;
 
        // Saved root->right node now is at end of root->right chain
        struct TreeNode* t = root->right;
        while (t->right != NULL) {
            t = t->right;
        }
        t->right = tmpRight;
    }
 
    // Now, traverse root->right to do the same
    flatten(root->right);
}

// Traverse a BST BFS and print every node
//
void printBSTbfs(string heading, TreeNode *root) {
    deque<TreeNode *> queue;

    queue.push_back(root);

    cout << heading << "[";

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
    cout << "]" << endl;
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    printBSTbfs("Before: ", root);
    flatten(root);
    printBSTbfs("After: ", root);
}


