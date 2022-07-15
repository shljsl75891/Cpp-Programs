#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertices, edges; 
    cin >> vertices >> edges;
    int graph1[vertices][vertices];
    vector<pair<int, int> > graph2[vertices];
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            graph1[i][j] = 0;
        } 
    }
    for(int i = 0; i < edges; i++) {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph1[v1 - 1][v2 - 1] = wt;
        graph1[v2 - 1][v1 - 1] = wt;
        graph2[v1 - 1].push_back(make_pair(v2, wt));
        graph2[v2 - 1].push_back(make_pair(v1, wt));
    } 
    cout << "Adjacency Matrix: " << endl;
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            cout << graph1[i][j] << " ";
        } cout << endl;
    }
    cout << "\nAdjacency List: " << endl;
    for(int i = 0; i < vertices; i++) {
        cout << i + 1 << ": ";
        for(pair<int, int> p : graph2[i]) {
            cout << "(" << p.first << " " << p.second << ") ";
        } cout << endl;
    }
}