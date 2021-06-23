/*

    LEETCODE# 199

    Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of 
    the nodes you can see ordered from top to bottom.

 

    Example 1:


    Input: root = [1,2,3,null,5,null,4]
    Output: [1,3,4]

    Example 2:

    Input: root = [1,null,3]
    Output: [1,3]

    Example 3:

    Input: root = []
    Output: []
 

    Constraints:

    The number of nodes in the tree is in the range [0, 100].
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


// Level order traversal: https://www.geeksforgeeks.org/level-order-tree-traversal
// Always traverse right side first to record the depth of right side
// Then, record the left side if and only if its depth is > max right side depth
//
vector<int> rightSideView2(TreeNode* root, int level, int &maxLevel, vector<int> &result) {
    if (root == NULL)
        return result;
    
    if (level > maxLevel) {                 // if depth is > right side depth, record
        //cout << "[" << level << "." << maxLevel << "]" << endl;
        result.push_back(root->val);
        maxLevel = level;
    }
    //cout << level << "." << maxLevel << endl;
    level++;
    
    rightSideView2(root->right, level, maxLevel, result);   // right side view first
   
    rightSideView2(root->left, level, maxLevel, result);    // then left side view if no right side

    return result;
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result{};
    int maxLevel = 0;
    
    return rightSideView2(root, 1, maxLevel, result);
}

// Print values in an array
//
void printArray(string heading, vector<int> array, int len) {
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

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);    

    printBSTbfs("Tree: ", root);
    vector<int> result = rightSideView(root);
    printArray("Output: ", result, result.size());
}



