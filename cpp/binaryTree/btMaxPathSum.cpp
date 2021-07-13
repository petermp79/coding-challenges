/*

    LEETCODE# 124

    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence 
    has an edge connecting them. A node can only appear in the sequence at most once. Note that the 
    path does not need to pass through the root.

    The path sum of a path is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any path.

 

    Example 1:


    Input: root = [1,2,3]
    Output: 6
    Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
    Example 2:


    Input: root = [-10,9,20,null,null,15,7]
    Output: 42
    Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

    Constraints:

    The number of nodes in the tree is in the range [1, 3 * 104].
        -1000 <= Node.val <= 1000

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

//
// This function returns overall maximum path sum in 'result'
// And returns max path sum going through root.
//
int maxPathSum2(TreeNode* root, int &result)
{
    //Base Case
    if (root == NULL)
        return 0;
  
    // max path sum of left or right branch
    int l = maxPathSum2(root->left, result);
    int r = maxPathSum2(root->right, result);
  
    // Max path for parent call of root. This path must
    // include at-most one child of root
    int max_single = max(max(l, r) + root->val, root->val);
  
    // Max Top represents the sum when the Node under
    // consideration is the root of the maxsum path and no
    // ancestors of root are there in max sum path
    int max_top = max(max_single, l + r + root->val);
  
    result = max(result, max_top); // Store the Maximum Result.
  
    return max_single;
}

// For each node there can be four ways that the max path goes through the node:
//
//      1. Node only
//      2. Max path through Left Child + Node
//      3. Max path through Right Child + Node
//      4. Max path through Left Child + Node + Max path through Right Child
//
// The idea is to keep trace of four paths and pick up the max one in the end. 
// An important thing to note is, root of every subtree need to return maximum path sum 
// such that at most one child of root is involved. This is needed for parent function call. 
// In below code, this sum is stored in ‘max_single’ and returned by the recursive function.

int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    
    // Compute and return result
    maxPathSum2(root, result);
    return result;
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

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << "Tree: [";
    printBSTbfs(root);
    cout << "]" << endl;

    cout << "Max Path Sum: " << maxPathSum(root) << endl;

    TreeNode *root1 = new TreeNode(-10);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    cout << "Tree: [";
    printBSTbfs(root1);
    cout << "]" << endl;
    cout << "Max Path Sum: " << maxPathSum(root1) << endl;

    return 0;
}



