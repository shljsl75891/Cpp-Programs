#include <iostream>
#include <vector>
#include <queue>
using namespace std;


template <typename type>
class Tree{
    struct TreeNode {
        type data;
        vector<TreeNode*> children;
        TreeNode(type data) {
            this->data = data;
        }
    };
    TreeNode *root;
protected:
    TreeNode* Input(TreeNode *temp) {
        if(temp == NULL) {
            cout << "Enter the data: ";
            int data; cin >> data;
            temp = new TreeNode(data);
        } cout << "Enter the number of children of " << temp->data << ": ";
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            cout << i + 1 << " child's data: ";
            int data; cin >> data;
            TreeNode *child = new TreeNode(data);
            temp->children.push_back(child);
        } for(int i = 0; i < n; i++) {
            temp->children[i] = Input(temp->children[i]);
        } return temp;
    }

    // Pre-Order Printing 
    void Preorder(TreeNode *temp) {
        int size = temp->children.size();
        cout << temp->data << " ";
        for(int i = 0; i < size; i++) {
            Preorder(temp->children[i]);
        }
    }

    //Post-Order Printing
    void PostOrder(TreeNode *temp) {
        int size = temp->children.size();
        for(int i = 0; i < size; i++) {
            PostOrder(temp->children[i]);
        } cout << temp->data << " ";
    }
    int countNodes(TreeNode *temp) {
        int result = 1;
        if(temp == NULL) {
            return 0;
        } int size = temp->children.size(); 
        for(int i = 0; i < size; i++) {
            result += countNodes(temp->children[i]);
        } return result;
    }
    int calculateHeight(TreeNode *temp) {
        int height = 0;
        if(temp == NULL) {
            return 0;
        } int size = temp->children.size(); 
        for(int i = 0; i < size; i++) {
            height = max(height, calculateHeight(temp->children[i]));
        } return height + 1;
    }
    void depth(TreeNode *temp, int d) {
        if(d == 0) {
            cout << temp->data << " ";
            return;
        } int size = temp->children.size(); 
        for(int i = 0; i < size; i++) {
            depth(temp->children[i], d - 1);
        }
    }
    void countLeaves(TreeNode *temp, int &count) {
        int size = temp->children.size();
        if(size == 0) {
            cout << temp->data << " ";
            count++; return;
        } for(int i = 0; i < size; i++) {
            countLeaves(temp->children[i], count);
        }
    }
    void delete(TreeNode* t) {
        int size = t->children.size();
        for(int i = 0; i < size; i++) {
            delete(t->children[i]);
        } delete t;
    }
public:
    Tree() {
        root = NULL;
    }
    void takeInput() {
        root = Input(root);
    }
    void takeInputLevelWise() {
        cout << "Enter the data: ";
        type rootData; cin >> rootData;
        root = new TreeNode(rootData);
        queue<TreeNode*> pendingNodes; 
        pendingNodes.push(root);
        while(!pendingNodes.empty()) {
            TreeNode *poppedNode = pendingNodes.front(); 
            pendingNodes.pop();
            cout << "Enter the number of children of " << poppedNode->data << ": ";
            int nChild; cin >> nChild;
            for(int i = 0; i < nChild; i++) {
                cout << "Enter the data of " << i + 1 << "th children: ";
                type childData; cin >> childData;
                TreeNode *child = new TreeNode(childData);
                poppedNode->children.push_back(child);
                pendingNodes.push(poppedNode->children[i]);
            }
         }
    }
    void preOrderDisplay() {
        Preorder(root);
    }

    void postOrderDisplay() {
        PostOrder(root);
    }

    // LevelWise printing
    void display() {
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()) {
            TreeNode *poppedNode = pendingNodes.front(); 
            pendingNodes.pop();
            int size = poppedNode->children.size();
            cout << poppedNode->data << ":";
            for(int i = 0; i < size; i++) {
                cout << poppedNode->children[i]->data << " ";
                pendingNodes.push(poppedNode->children[i]);
            }
            cout << endl;
        }
    }
    int count() {
        if(root == NULL) {
            return 1;
        } return countNodes(root);
    }
    int height() {
        if(root == NULL) {
            return 1;
        } return calculateHeight(root);
    }
    void depth_display(int d) {
        if(root == NULL) {
            return;
        } depth(root, d);
    }
    void countLeafNodes(int &count) {
        if(root == NULL) {
            return;
        } countLeaves(root, count);
    }
    ~Tree() {
        delete(root);
    }
};

int main() {
    Tree <int>gTree;
    gTree.takeInputLevelWise();
    cout << "Tree: \n";
    gTree.display();
    cout << "Number of Nodes in Tree: " << gTree.count();
    cout << "\nHeight of Tree: " << gTree.height();
    cout << "\nEnter the Depth: "; int d; cin >> d; 
    cout << "Nodes at depth " << d << ": "; gTree.depth_display(d);
    int count = 0; cout << "\nLeaf Nodes: "; gTree.countLeafNodes(count);
    cout << "\nNumber of leaf Nodes: " << count << '\n';
    gTree.preOrderDisplay(); cout << '\n';
    gTree.postOrderDisplay(); cout << '\n';
}

// Input Tree : 1 3 2 3 4 1 5 1 8 1 10 2 6 7 1 9 1 11 0 0 0 3 12 13 14 2 15 16 0 0 0 0 
