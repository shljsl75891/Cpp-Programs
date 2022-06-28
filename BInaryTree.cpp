#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTree {
	struct Node {
		T data;
		Node *left, *right;
		Node(T data) {
			this->data = data;
			left = right = NULL;
		}
	};
	Node *root;
protected:
	void inOrder(Node *t) {
		if(t!= NULL) {
			inOrder(t->left);
			cout << t->data << " ";
			inOrder(t->right);
		}
	}
	void preOrder(Node *t) {
		if(t!= NULL) {
			cout << t->data << ": ";
			preOrder(t->left);
			preOrder(t->right);
		}
	}
	void deleteTree(Node *t) {
		if(t == NULL) {
			return;
		} deleteTree(t->left);
		deleteTree(t->right);
		delete t;
	}
	void display(Node *t) {
		queue<Node*> pendingNodes;
		pendingNodes.push(t);
		while(!pendingNodes.empty()) {
			Node *poppedNode = pendingNodes.front();
			pendingNodes.pop();
			cout << poppedNode->data << ": ";
			if(poppedNode->left != NULL) {
				cout << "L " << poppedNode->left->data << ' ';
				pendingNodes.push(poppedNode->left);
			}
			if(poppedNode->right != NULL) {
				cout << "R " << poppedNode->right->data;
				pendingNodes.push(poppedNode->right);
			} cout << '\n';
		}
	}
public:
	BinaryTree() {
		root = NULL;
	}
	void takeInput() {
		if(root != NULL) {
			delete root;
		} T rootData; //cout << "Enter the root data: ";
		cin >> rootData;
		root = new Node(rootData);
		queue<Node*> pendingNodes;
		pendingNodes.push(root);
		while(!pendingNodes.empty()) {
			Node *poppedNode = pendingNodes.front();
			pendingNodes.pop();
			T data; //cout << "Enter the left data of " << poppedNode->data << ": ";
			cin >> data;
			if(data != -1) {
				poppedNode->left = new Node(data);
				pendingNodes.push(poppedNode->left);
			} //cout << "Enter the right data of " << poppedNode->data << ": ";
			cin >> data; if(data != -1) {
				poppedNode->right = new Node(data);
				pendingNodes.push(poppedNode->right);	
			}
		}
	}

	// In-Order 
	void inOrderDisplay() {
		inOrder(root);
	}

	// Pre-Order 
	void preOrderDisplay() {
		preOrder(root);
	}

	// display tree
	void displayTree() {
		display(root);
	}

	~BinaryTree() {
		deleteTree(root);
	}
};

int main() {
	BinaryTree<int> BT;
	BT.takeInput();
	BT.displayTree();
}					