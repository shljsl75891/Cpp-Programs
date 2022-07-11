#include <iostream>
#include <queue>
using namespace std;
// Input: 56 14 65 11 45 61 88 13 34 52 76 82 100 -1

template<class T> 
class BinarySearchTree {
	struct Node {
		T data;
		Node *left, *right;
		Node(T data) {
			this->data = data;
			left = right = NULL;
		}
	}; Node *root;
protected: 
	void inOrder(Node *t) {
		if(t == NULL) { 
			return; 
		} inOrder(t->left);
		cout << t->data << " ";
		inOrder(t->right);
	}
	void preOrder(Node *t) {
		if(t == NULL) { 
			return; 
		} cout << t->data << " ";
		preOrder(t->left);
		preOrder(t->right);
	}
	void postOrder(Node* t) {
		if(t == NULL) { 
			return; 
		} postOrder(t->left);
		postOrder(t->right);
		cout << t->data << " ";
	}
	void display(Node *t) {
		queue<Node*> pendingNodes;
		pendingNodes.push(t);
		while(!pendingNodes.empty()) {
			Node *poppedNode = pendingNodes.front();
			pendingNodes.pop();
			cout << "   " << poppedNode->data << ": ";
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
	void deleteTree(Node *t) {
		if(t == NULL) {
			return;
		} deleteTree(t->left);
		deleteTree(t->right);
		delete t;
	}
public:
	BinarySearchTree() {
		root = NULL;
	}
	void takeInput() {
		while(true) {
			T data; cin >> data;
			if(data == -1) {
				break;
			} else {
				insertData(data);
			}
		}
	}
	void insertData(int data) {
		Node *newNode = new Node(data);
		Node *temp = root;
		if(root == NULL) {
			root = newNode;
			return;
		} while(true) {
			if(data == temp->data) {
				delete newNode;
				return;
			} else if(data < temp->data) {
				if(temp->left == NULL) {
					temp->left = newNode;
					break;
				} temp = temp->left;
			} else {
				if(temp->right == NULL) {
					temp->right = newNode;
					break;
				} temp = temp->right; 
			}
		
		}
	}
	void deleteNode(int data) {
		Node *ptr = root, *parentPtr = NULL;
		while(ptr != NULL) {
			if(data == ptr->data) {
				break;
			} else if(data < ptr->data) {
				parentPtr = ptr;
				ptr = ptr->left;
			} else {
				parentPtr = ptr;
				ptr = ptr->right;
			}
		} if(ptr == NULL) {
			cout << "target not found";
			return;
		} else {
			if(ptr->left == NULL && ptr->right == NULL) {
				if(ptr == parentPtr->left) {
					parentPtr->left = NULL;
				} else {
					parentPtr->right = NULL;
				} delete ptr;
			} else if(ptr->right == NULL) {
				if(ptr == parentPtr->left) {
					parentPtr->left = ptr->left;
				} else {
					parentPtr->right = ptr->left;
				} delete ptr;
			} else if(ptr->left == NULL) {
				if(ptr == parentPtr->left) {
					parentPtr->left = ptr->right;
				} else {
					parentPtr->right = ptr->right;
				} delete ptr;
			} else {
				Node *t = ptr->right;
				if(t->left == NULL) {
					ptr->data = t->data;
					ptr->right = t->right;
					delete t;
				} else {
					Node *parentT = ptr;
					while(t->left != NULL) {
						parentT = t;
						t = t->left;
					} ptr->data = t->data; 
					parentT->left = t->right;
					delete t;
				}
			}
		}
	}

	void displayTree() {
		display(root);
	}

	// inOrder 
	void inOrderDisplay() {
		inOrder(root);
	}

	//PreOrder
	void preOrderDisplay() {
		preOrder(root);
	}

	//Post Order
	void postOrderDisplay() {
		postOrder(root);
	}
	~BinarySearchTree() {
		deleteTree(root);
	}
};

int main() {
	BinarySearchTree <int>BST;
	BST.takeInput();
	cout << "\"Level Wise Printing:\"\n";
	BST.displayTree();
	cout << "\"InOrder\": "; BST.inOrderDisplay();
	cout << "\n\"PreOrder\": "; BST.preOrderDisplay();
	cout << "\n\"PostOrder:\""; BST.postOrderDisplay();
}