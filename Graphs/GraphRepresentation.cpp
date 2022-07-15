#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<pair<int, int> > graph[N];

void createGraph(int vertices, int edges) {
    for(int i = 0; i < edges; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1 - 1].push_back(make_pair(v2, wt));
        graph[v2 - 1].push_back(make_pair(v1, wt));
    } 
}

void printGraph(int vertices) {
    for(int i = 0; i < vertices; i++) {
        cout << i + 1 << ": ";
        for(pair<int, int> p : graph[i]) {
            cout << "(" << p.first << " " << p.second << ") ";
        } cout << endl;
    }
}

int main() {
    int vertices, edges; 
    cin >> vertices >> edges;
    createGraph(vertices, edges);
    printGraph(vertices);
}