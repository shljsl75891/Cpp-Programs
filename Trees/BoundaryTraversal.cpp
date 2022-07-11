#include <vector>
#include "BinaryTree.h"
using namespace std;

// 3 9 7 -1 48 4 11 -1 -1 19 -1 21 32 -1 -1 99 52 1 -1 -1 -1 53 -1 -1 -1 -1 -1

void leftTraversal(BinaryTreeNode *root, vector<int> &result) {
    if(root == NULL || !(root->left) && !(root->right)) {
        return;
    } result.push_back(root->data);
    if(root->left) {
        leftTraversal(root->left, result);
    } else {
        leftTraversal(root->right, result);
    }
}

void leavesTraversal(BinaryTreeNode *root, vector<int> &result) {
    if(root == NULL) {
        return;
    } else if(!(root->left) && !(root->right)) {
        result.push_back(root->data);
        return;
    } leavesTraversal(root->left, result);
    leavesTraversal(root->right, result);
}

void rightTraversal(BinaryTreeNode *root, vector<int> &result) {
    if(root == NULL || !(root->left) && !(root->right)) {
        return;
    } if(root->right) {
        rightTraversal(root->right, result);
    } else {
        rightTraversal(root->left, result);
    } result.push_back(root->data);
}

vector<int> boundaryTraversal(BinaryTreeNode *root) {
    vector<int> result;
    if(root == NULL) {
        return result;
    } result.push_back(root->data); 
    // Left Traversal
    leftTraversal(root->left, result);
    // Leaves Traversal
    leavesTraversal(root->left, result);
    leavesTraversal(root->right, result);
    // Right Traversal
    rightTraversal(root->right, result);
    return result;
}

int main() {
    BinaryTreeNode *root = takeInput(NULL);
    vector<int> ans = boundaryTraversal(root);
    for(int i : ans) {
        cout << i << " ";
    }
}