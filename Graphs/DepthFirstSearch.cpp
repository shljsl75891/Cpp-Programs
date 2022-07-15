#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createAdjacencyList(int V, int E, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for(int i = 0; i < V; i++) {
        adj[i].push_back(i);
    } for(int i = 0; i < E; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    } return adj;
}

void DFS(int vertex, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component) {
    visited[vertex] = true;
    component.push_back(vertex);
    for(int child : adj[vertex]) {
        if(visited[child] == false) {
            DFS(child, adj, visited, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    vector<vector<int>> dfs, adj = createAdjacencyList(V, E, edges);
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++) {
        if(visited[i] == false) {
            vector<int> component;
            DFS(i, adj, visited, component);
            dfs.push_back(component);
        }
    } return dfs;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i].push_back(u);
        edges[i].push_back(v);
    } vector<vector<int>> ans = depthFirstSearch(n, m, edges);
    for(vector<int> i : ans) {
        for(int j : i) {
            cout << j << " ";
        } cout << endl;
    } return 0;
}