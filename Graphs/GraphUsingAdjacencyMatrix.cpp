#include <iostream>
using namespace std;

class Graph {
    int v_no, e_no;
    int **ptr;
public:
    Graph(int vertices, int edges) {
        ptr = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            ptr[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                ptr[i][j] = 0;
            }
        } v_no = vertices;
        e_no = edges;
    }
    void connectVertices() {
        for (int i = 1; i <= e_no; i++) {
            int u, v;
            cin >> u >> v;
            ptr[u - 1][v - 1] = 1;
            ptr[v - 1][u - 1] = 1;
        }
    }
    void displayGraph() {
        cout << "Total number of vertices: " << v_no << '\n';
        cout << "Total number of edges: " << e_no << '\n';
        cout << "\n  Graph\n";
        for (int i = 0; i < v_no; i++) {
            for (int j = 0; j < v_no; j++) {
                cout << ptr[i][j] << " ";
            } cout << endl;
        }
    }
    ~Graph() {
        for (int i = 0; i < v_no; i++) {
            delete[] ptr[i];
        } delete[] ptr;
    }
};

int main() {
    freopen("Debug.txt", "w", stderr);
    Graph G(5, 5);
    G.connectVertices();
    G.displayGraph();
}