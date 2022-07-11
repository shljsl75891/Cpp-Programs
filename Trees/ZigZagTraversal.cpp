#include "BinaryTree.h"
#include <queue>
using namespace std;
// 3 9 7 -1 48 4 11 -1 -1 19 -1 21 32 -1 -1 99 52 1 -1 -1 -1 53 -1 -1 -1 -1 -1

vector<int> zig_zag(Node *root) {
    vector<int> result;
    queue<Node*> pending;
    if(root == NULL) return result;
    pending.push(root);
    bool left_2_right = true;
    while(!pending.empty()) {
        int size = pending.size();
        vector<int> t_ans(size);
        for(int i = 0; i < size; i++) {
            Node *popped = pending.front();
            pending.pop();
            int index = left_2_right ? i : size - i - 1;
            t_ans[index] = popped->data;
            if(popped->left != NULL) {
                pending.push(popped->left);
            } if(popped->right != NULL) {
                pending.push(popped->right);
            } 
        } left_2_right = !left_2_right; 
        for(int i : t_ans) {
            result.push_back(i);
        }
    } return result;
}

int main() {
    Node *root = NULL;
    root = takeInput(root);
    // displayLevelWise(root);
    vector<int> ans = zig_zag(root);
    for(int i : ans) {
        cout << i << " ";
    }
}