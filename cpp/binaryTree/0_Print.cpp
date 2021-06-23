// Various support functions ...
// Copy and paste to your driver coding test files to save time.
//
// TODO: make a lib out of these functions and others
//


// Print a list of sub arrays
//
void printSubsets(string heading, vector<vector<int>> subsets) {

    cout << heading << "[";
    for (auto subset : subsets) {
        cout << "[";
        for (auto x : subset) {
            cout << x << ",";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

// Print a matrix
//
void printMatrix(string heading, vector<vector<char>> grid) {

    string startspaces(heading.length()+4, ' ');
    string endspaces(heading.length(), ' ');


    cout << heading << "[" << endl;
    for (auto row : grid) {
        cout << startspaces << "[";
        for (auto x : row) {
            cout << x << ",";
        }
        cout << "]," << endl;
    }
    cout << endspaces << "]" << endl;
}

// Print values in an array
//
void printArray(string heading, vector<int> array, int len=0) {
    if (len == 0)
        len = array.size();

    cout << heading << "[";
    for (int i = 0; i < len; i++) {
        cout << array[i] << ",";
    }
    cout << "]" << endl;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// How to build a tree as defined by the above structure
//
int buildBSTSample() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
}

// Traverse a BST DFS and print every node
//
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


