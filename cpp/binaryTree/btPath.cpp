/*

    LEETCODE# 257

    Given the root of a binary tree, return all root-to-leaf paths in any order.

    A leaf is a node with no children.


    Example 1:


    Input: root = [1,2,3,null,5]
    Output: ["1->2->5","1->3"]

    Example 2:

    Input: root = [1]
    Output: ["1"]
 

    Constraints:

        The number of nodes in the tree is in the range [1, 100].
        -100 <= Node.val <= 100

*/

#include <iostream>
#include <vector>

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
// Pre-order traveral: root->left->right
// Traverse left to leaf node --> record path
// Traverse right to leaf node --> record path
//
void binaryTreePaths2(TreeNode *root, string path, vector<string> &result) {
    if (path.length() == 0)
        path += to_string(root->val);           // first in chain, node itself
    else
        path += "->" + to_string(root->val);    // next in chain, prefix with arrow
    
    // is this root a leaf node?
    if (root->left == NULL && root->right == NULL) {
        // Got to the leaf node, save the path
        result.push_back(path);
    } 
    // traverse left (dont pass null subtree as we dont check for it)
    if (root->left)
        binaryTreePaths2(root->left, path, result);
    // traverse right
    if (root->right)
        binaryTreePaths2(root->right, path, result);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    string path;
    
    if (root == NULL)
        return result;
    
    binaryTreePaths2(root, path, result);
    return result;
}

// Print values in an array of string
//
void printStringArray(string heading, vector<string> array, int len=0) {
    if (len == 0)
        len = array.size();

    cout << heading << "[";
    for (int i = 0; i < len; i++) {
        cout << array[i] << ",";
    }
    cout << "]" << endl;
}


// Traverse a BST BFS and print every node
//
#include <deque>

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
    vector<string> result{};

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    printBSTbfs("Input: ", root);
    result = binaryTreePaths(root);
    printStringArray("Output: ", result); 

    return 0;
}



