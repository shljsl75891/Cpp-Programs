#include <bits/stdc++.h>
using namespace std;

void DFS(int vertex, vector<vector<int>> &adjList, vector<bool> &visited) {
    visited[vertex] = true;
    cout << vertex << " ";
    for(int child : adjList[vertex]) {
        if(visited[child] == false) {
            DFS(child, adjList, visited);
        }
    }
}

int main() {
    int V, E; cin >> V >> E;
    vector<vector<int>> adjList(V + 1);
    vector<bool> visited(V + 1, false);
    for(int i = 1; i <= V; i++) {
        adjList[i].push_back(i);
    } for(int j = 0; j < E; j++) {
        int u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    } for(int i = 1; i <= V; i++) {
        if(visited[i] == false) {
            DFS(i, adjList, visited);
        }
    }
}