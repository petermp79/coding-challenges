/*

    LEETCODE# 1123

    Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

    Recall that:

    The node of a binary tree is a leaf if and only if it has no children

    The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of 
    its children is d + 1.

    The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that 
    every node in S is in the subtree with root A.

    Note: This question is the same as 865: 
            https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

    Example 1:

    Input: root = [3,5,1,6,2,0,8,null,null,7,4]
    Output: [2,7,4]
    Explanation: We return the node with value 2 since 7 and 4 are deepest leaves.

    Example 2:

    Input: root = [1]
    Output: [1]
    Explanation: The root is the deepest node in the tree, and it's the lca of itself.

    Example 3:

    Input: root = [0,1,3,null,2]
    Output: [2]
    Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
 

    Constraints:

    The number of nodes in the tree will be in the range [1, 1000].
        0 <= Node.val <= 1000
        The values of the nodes in the tree are unique.


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

int deepest;

pair<int, TreeNode *> findLCADeepestLeaves(TreeNode* root) {
    if (root == NULL) 
        return {0, root};
    
    //cout << root->val << ".";
    
    // postorder traversal
    auto l = findLCADeepestLeaves(root->left);
    auto r = findLCADeepestLeaves(root->right);
    
    //cout << endl << l.first << "." << r.first << endl;
    
    // if left = right subtrees have the same depth, root is LCA 
    if (l.first == r.first) 
        return {l.first+1, root};
    // if left subtree is deeper, return left node is LCA
    else if (l.first > r.first)
        return {l.first+1, l.second};
    else    // else, return right node is LCA
        return {r.first+1, r.second};
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    int depth = 0;
    
    return findLCADeepestLeaves(root).second;
}

// Traverse a BST BFS and print every node
//
void printBSTbfs(TreeNode *root, bool printNULL) {
    deque<TreeNode *> queue;

    queue.push_back(root);

    while(!queue.empty()) {
        TreeNode *node = queue.front();
        queue.pop_front();
        if (node == NULL) {
            if (printNULL)
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
    printBSTbfs(root, true);
    cout << "]" << endl;
    TreeNode *lca = lcaDeepestLeaves(root);
    cout << "LCA with deepest leaves: [";
    printBSTbfs(lca, false);
    cout << "]" << endl;

    TreeNode *root1 = new TreeNode(1);
    cout << "Tree: [";
    printBSTbfs(root1, true);
    cout << "]" << endl;
    lca = lcaDeepestLeaves(root1);
    cout << "LCA with deepest leaves: [";
    printBSTbfs(lca, false);
    cout << "]" << endl;

    TreeNode *root2 = new TreeNode(0);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(2);
    cout << "Tree: [";
    printBSTbfs(root2, true);
    cout << "]" << endl;
    lca = lcaDeepestLeaves(root2);
    cout << "LCA with deepest leaves: [";
    printBSTbfs(lca, false);
    cout << "]" << endl;
    return 0;
}



