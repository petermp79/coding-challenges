/*
    LEETCODE# 98

    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
 

    Example 1:

    Input: root = [2,1,3]
    Output: true

    Example 2:

    Input: root = [5,1,4,null,null,3,6]
    Output: false
    Explanation: The root node's value is 5 but its right child's value is 4.
 

    Constraints:
        The number of nodes in the tree is in the range [1, 104].
        -231 <= Node.val <= 231 - 1


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

bool isValidBST2(TreeNode *root, long min, long max) {
    
    if (root == NULL)
        return true;
    
    //cout << "isValidateBST2: " << root->val << "." << min << "." << max << endl;
    
    if (root->val <= min || root->val >= max) {
        //cout << "false: " << root->val << "." << min << "." << max << endl;
        return false;   // invalid node value
    }
    return isValidBST2(root->left, min, (long)root->val) && 
                isValidBST2(root->right, (long)root->val, max);
}


bool isValidBST(TreeNode* root) {
    return isValidBST2(root, (long)INT_MIN-1, (long)INT_MAX+1);
}

void printBSTdfs(TreeNode *root) {
    if (root == NULL) {
        cout << "null,";
        return;
    }
    // inorder traversal
    cout << root->val << ",";
    printBSTdfs(root->left);
    printBSTdfs(root->right);
}

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

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    cout << "[";
    printBSTbfs(root);
    cout << "]";
 
    cout << " --> " << (isValidBST(root) ? "Yes" : "No") << endl;

    root->val = 4;
    root->right->val = 5;
    cout << "[";
    printBSTbfs(root);
    cout << "]";
    cout << " --> " << (isValidBST(root) ? "Yes" : "No") << endl;

    delete(root->right->left);
    root->right->left = NULL;
    cout << "[";
    printBSTbfs(root);
    cout << "]";
    cout << " --> " << (isValidBST(root) ? "Yes" : "No") << endl;

    // should delete old tree here ...

    root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << "[";
    printBSTbfs(root);
    cout << "]";
    cout << " --> " << (isValidBST(root) ? "Yes" : "No") << endl;

    return 0;
}

