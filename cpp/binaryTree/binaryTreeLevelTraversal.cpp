/*

    LEETCODE# 102

    Given the root of a binary tree, return the level order traversal of its nodes' values. 
    (i.e., from left to right, level by level).

 

    Example 1:
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]

    Example 2:
    Input: root = [1]
    Output: [[1]]

    Example 3:
    Input: root = []
    Output: []
 

    Constraints:

        The number of nodes in the tree is in the range [0, 2000].
        -1000 <= Node.val <= 1000



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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    deque<pair<TreeNode *, int>> queue;
    vector<vector<int>> result(1000, vector<int>{});
    int level = 0;
    queue.push_back(make_pair(root, level));
    
    //cout << "start" << endl;

    while (!queue.empty()) {
        auto elem = queue.front();
        queue.pop_front();
        //cout << "Level " << elem.second << endl;
        TreeNode *node = elem.first;
        level = elem.second;
        if (node == NULL) {
            //cout << "node=NULL" << endl;
            continue;
        }
        else {
            //cout << node->val << "." << level << endl;
            result[level].push_back(node->val);
            queue.push_back(make_pair(node->left, level+1));
            queue.push_back(make_pair(node->right, level+1));
        }
    }
    result.resize(level);
    /*
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << endl;
        }
    }*/

    return result;
}

// Print a list of sub arrays
//
void printSubsets(string heading, vector<vector<int>> subsets) {

    cout << heading <<"[";
    for (auto subset : subsets) {
        cout << "[";
        for (auto x : subset) {
            cout << x << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

// Traverse a BST BFS and print every node
//
void printBSTbfs(string heading, TreeNode *root) {
    deque<TreeNode *> queue;

    cout << heading << "[";;
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
    cout << "]" << endl;
}


int main() {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    printBSTbfs("Tree: ", root);
    vector<vector<int>> result = levelOrder(root);
    printSubsets("Result: ", result);

    root->val = 1;
    root->left->val = 2;
    root->right->val = 3;
    root->left->left = root->right->left;
    root->right->left = NULL;
    root->left->left->val = 4;
    root->right->right = new TreeNode(5);

    printBSTbfs("Tree: ", root);
    result = levelOrder(root);
    printSubsets("Result: ", result);

    return 0;
}


