
/*

    Delete a node in a binary search tree 

*/


#include <iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

typedef TreeNode* Tree;

Tree getSuccessor(Tree root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Tree deleteNodeBst(Tree root, int num) {
    if (root == NULL)
        return NULL;
    else if (num > root->data)
        // deleted node on the right subtree
        root->right = deleteNodeBst(root, num);
    else if (num < root->data)
        // deleted node on the left subtree
        root->left = deleteNodeBst(root, num);
    else {
        // Found the node to delete
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else {
            // Both left & right are having subtrees
            // copy successor's data to root 
            Tree successor = getSuccessor(root->right);
            root->data = successor->data;
            // ... and delete successor node
            root->right = deleteNodeBst(root->right, successor->data);
        }
    }
    return root;
}

int main() {
}


