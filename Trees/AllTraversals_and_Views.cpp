#include <queue>
#include <map>
#include "BinaryTree.h"
#include <vector>
using namespace std;

vector<int> zig_zag(Node *root) {
    vector<int> ans;
    if(root == NULL) {
        return ans;
    } queue<Node*> q;
    q.push(root);
    bool left_2_right = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> temp(size);
        for(int i = 0; i < size; i++) {
            Node *popped = q.front();
            q.pop();
            int index = left_2_right ? i : size - i - 1;
            temp[index] = popped->data;
            if(popped->left) {
                q.push(popped->left);
            } if(popped->right) {
                q.push(popped->right);
            }
        } for(int i : temp) {
            ans.push_back(i);
        } left_2_right = !left_2_right;
    } return ans;
}

void left(Node *root, vector<int> &ans) {
    if(root == NULL || root->left == NULL && root->right == NULL) {
        return;
    } ans.push_back(root->data);
    if(root->left) {
        left(root->left, ans);
    } else {
        left(root->right, ans);
    }
}

void leaves(Node *root, vector<int> &ans) {
    if(root == NULL) {
        return;
    } if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
    } leaves(root->left, ans);
    leaves(root->right, ans);
}

void right(Node *root, vector<int> &ans) {
    if(root == NULL || root->left == NULL && root->right == NULL) {
        return;
    } if(root->right) {
        right(root->right, ans);
    } else {
        right(root->left, ans);
    } ans.push_back(root->data);
}

vector<int> boundary(Node *root) {
    vector<int> ans;
    if(root == NULL) {
        return ans;
    } ans.push_back(root->data);
    left(root->left, ans);
    leaves(root->left, ans); leaves(root->right, ans);
    right(root->right, ans);
    return ans;
}

vector<int> vertical(Node *root) {
    vector<int> ans;
    if(root == NULL) {
        return ans;
    } map<int, vector<int>> m;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    while(q.empty() == false) {
        pair<Node*, int> p = q.front();
        q.pop(); m[p.second].push_back(p.first->data);
        if(p.first->left) {
            q.push(make_pair(p.first->left, p.second - 1));
        } if(p.first->right) {
            q.push(make_pair(p.first->right, p.second + 1));
        }
    } for(pair<int, vector<int>> i : m) {
        for(int j : i.second) {
            ans.push_back(j);
        }
    } return ans;
}

vector<int> topView(Node *root) {
    vector<int> result;
    map<int, int> nodes;
    queue<pair<int, Node*>> pending;
    pending.push(make_pair(0, root));
    while(pending.size() != 0) {
        pair<int, Node*> p = pending.front();
        pending.pop(); 
        if(nodes.find(p.first) == nodes.end()) {
            nodes.insert(make_pair(p.first, p.second->data));
        } if(p.second->left) {
            pending.push(make_pair(p.first - 1, p.second->left));
        } if(p.second->right) {
            pending.push(make_pair(p.first + 1, p.second->right));
        }
    } for(pair<int, int> i : nodes) {
        result.push_back(i.second);
    } return result;
}

vector <int> bottomView(Node *root) {
    vector<int> result;
    map<int, int> nodes;
    queue<pair<int, Node*>> pending;
    pending.push(make_pair(0, root));
    while(pending.size() != 0) {
        pair<int, Node*> p = pending.front();
        pending.pop(); 
        nodes[p.first] = p.second->data;
        if(p.second->left) {
            pending.push(make_pair(p.first - 1, p.second->left));
        } if(p.second->right) {
            pending.push(make_pair(p.first + 1, p.second->right));
        }
    } for(pair<int, int> i : nodes) {
        result.push_back(i.second);
    } return result;
}

// Easier code using recursion
vector<int> rightView(Node *root) {
        /*
        if(root == NULL) {
            return;
        } if(lvl == ans.size()) {
            ans.push_back(root->data);
        } solve(root->right, ans, lvl + 1);
        solve(root->left, ans, lvl + 1);
        */
       vector<int> ans;
       if(root == NULL) {
           return ans;
       } queue<pair<int, Node*>> pending;
       map<int, int> nodes;
       pending.push(make_pair(0, root));
       while(pending.size() != 0) {
           pair<int, Node*> p = pending.front();
           pending.pop();
           nodes[p.first] = p.second->data;
           if(p.second->left) {
               pending.push(make_pair(p.first + 1, p.second->left));
           } if(p.second->right) {
               pending.push(make_pair(p.first + 1, p.second->right));
           }
       } for(pair<int, int> i : nodes) {
           ans.push_back(i.second);
       } return ans;
    }

vector<int> leftView(Node *root) {
    /*
        if(root == NULL) {
            return;
        } if(lvl == ans.size()) {
            ans.push_back(root->data);
        } solve(root->left, ans, lvl + 1);
        solve(root->right, ans, lvl + 1);
        */
    vector<int> ans;
    if(root == NULL) {
       return ans;
    } queue<pair<int, Node*>> pending;
    map<int, int> nodes;
    pending.push(make_pair(0, root));
    while(pending.size() != 0) {
       pair<int, Node*> p = pending.front();
       pending.pop();
       if(nodes.find(p.first) == nodes.end()) {
            nodes[p.first] = p.second->data;       
       } if(p.second->left) {
           pending.push(make_pair(p.first + 1, p.second->left));
       } if(p.second->right) {
           pending.push(make_pair(p.first + 1, p.second->right));
       }
    } for(pair<int, int> i : nodes) {
       ans.push_back(i.second);
    } return ans;
}

vector<int> diagonal(Node *root) {
   vector<int> ans;
    if(root == NULL) {
        return ans;
    } queue<Node*> q;
    q.push(root);
    while(q.size()) {
        Node *popped = q.front();
        q.pop();
        while(popped != NULL) {
            ans.push_back(popped->data);
            if(popped->left != NULL) {
                q.push(popped->left);
            } popped = popped->right;
        }
    } return ans;
}

int main() {
    Node *root = takeInput(NULL);
    // cout << "For Tree: \n";
    // displayTree(root);
    cout << "Zig-Zag Traversal: \n";
    for(int i : zig_zag(root)) {
        cout << i << " ";
    } cout << "\nBoundary Traversal: \n";
    for(int i : boundary(root)) {
        cout << i << " ";
    } cout << "\nVertical Traversal: \n";
    for(int i : vertical(root)) {
        cout << i << " ";
    } cout << "\nTop view: \n";
    for(int i : topView(root)) {
        cout << i << " ";
    } cout << "\nBottom view: \n";
    for(int i : bottomView(root)) {
        cout << i << " ";
    } cout << "\nRight view: \n"; 
    for(int i : rightView(root)) {
        cout << i << " ";
    } cout << "\nLeft view: \n"; 
    for(int i : leftView(root)) {
        cout << i << " ";
    } cout << "\nDiagnol Traversal: \n";
    for(int i : diagonal(root)) {
        cout << i << " ";
    }
}