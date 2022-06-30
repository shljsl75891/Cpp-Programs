#include <iostream>
using namespace std;

class Graph {
	struct Node {
		int vertex;
		Node *next;
		Node(int vertex) {
			this->vertex = vertex;
			next = NULL;
		}
	}; Node **ptr;
	int vertices;
public:
	Graph(int vertices) {
		this->vertices = vertices;
		ptr = new Node*[vertices];
		for (int i = 0; i < vertices; i++) {
			ptr[i] = NULL;
		}
	}
	void connectVertices() {
		for (int i = 0; i < vertices; i++) {
			// number of adjacent nodes
			int n; cin >> n;
			// inputting adjacent nodes
			while (n--) {
				int data; cin >> data;
				Node *newNode = new Node(data);
				newNode->next = ptr[i];
				ptr[i] = newNode;
			}
			Node *newNode = new Node(i + 1);
			newNode->next = ptr[i];
			ptr[i] = newNode;
		}
	}
	void printGraph() {
		for (int i = 0; i < vertices; i++) {
			Node *t = ptr[i];
			cout << t->vertex << ": ";
			t = t->next;
			while (t != NULL) {
				cout << t->vertex << " ";
				t = t->next;
			}
			cout << '\n';
		}
	}
	~Graph() {
		for (int i = 0; i < vertices; i++) {
			while (ptr[i] != NULL) {
				Node *t = ptr[i];
				ptr[i] = ptr[i]->next;
				delete t;
			}
		} delete[] ptr;
	}
};

int main() {
	Graph G(5);
	G.connectVertices();
	G.printGraph();
}