#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createAdjacencyList(int n, int m, vector<pair<int, int>> &edges) {
    vector<vector<int>> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i].push_back(i);
    } for(int i = 0; i < m; i++) {
        int u = edges[i].first, v = edges[i].second;
        ans[u].push_back(v);
        ans[v].push_back(u);
    } 
    // Optional on some platforms
    for(int i = 0; i < n; i++) {
        sort(ans[i].begin(), ans[i].end());
    } return ans;
}

vector<int> BFS(int n, vector<pair<int, int>> edges) {
    vector<int> bfs;
    vector<bool> status(n, false);
    int m = edges.size();
    // creating adjacency list 
    vector<vector<int>> adj = createAdjacencyList(n, m, edges);
    
    //BFS Algorithm
    queue<int> q;
    int first_v = adj[0][0];
    q.push(first_v);
    status[first_v] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        bfs.push_back(front);
        for(int i : adj[front]) {
            if(status[i] == false) {
                q.push(i);
                status[i] = true;
            }
        }
    } 
    // inserting disconnected nodes
    for(int i = 0; i < n; i++) {
        if(status[i] == false) {
            bfs.push_back(i);
        }
    } return bfs;
}

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i].first = u;
        edges[i].second = v;
    } vector<int> bfs = BFS(n, edges);
    for(int i : bfs) {
        cout << i << " ";
    }
}