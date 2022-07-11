#include <vector>
#include <map>
#include "BinaryTree.h"
using namespace std;

vector<int> verticalOrderTraversal(BinaryTreeNode *root) {
    vector<int> ans;
    if(root == NULL) {
        return ans;
    } map<int, vector<int>> nodes;
    queue<pair<BinaryTreeNode*, int>> pending;
    pending.push(make_pair(root, 0));
    while(!pending.empty()) {
        BinaryTreeNode *popped = pending.front().first;
        int ho_dis = pending.front().second;
        nodes[ho_dis].push_back(popped->data);
        pending.pop();
        if(popped->left) {
            pending.push(make_pair(popped->left, ho_dis - 1));
        } if(popped->right) {
            pending.push(make_pair(popped->right, ho_dis + 1));
        }
    } for(pair<int, vector<int>> it : nodes) {
        for(int j : it.second) {
            ans.push_back(j);
        }
    } return ans;
}

int main() {
    BinaryTreeNode *root = takeInput(NULL);
    vector<int> ans = verticalOrderTraversal(root);
    for(int i : ans) {
        cout << i << " ";
    }
}