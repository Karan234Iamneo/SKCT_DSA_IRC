#include <bits/stdc++.h>
using namespace std;

// Declare the adjacency list to store the graph
vector<int> adj[100005];  
// Array to track visited nodes
bool visited[100005] = { false };  
// Counter for the number of nodes visited during DFS
int ans = 0;  

// DFS function to traverse the graph
void dfs(int s) {
    visited[s] = true;  // Mark the current node as visited
    ans++;  // Increment the count of visited nodes

    // Explore all adjacent nodes
    for (int i = 0; i < adj[s].size(); ++i) {
        // If the adjacent node is not visited, call DFS recursively
        if (visited[adj[s][i]] == false)
            dfs(adj[s][i]);
    }
}

int main() {
    int n, e, x, y;

    // Input number of vertices (n) and edges (e)
    cin >> n >> e;  

    // Input edges and construct the adjacency list
    for (int i = 0; i < e; i++) {
        cin >> x >> y;  // Read the edge endpoints
        adj[x].push_back(y);  // Add the edge to the adjacency list
        adj[y].push_back(x);  // Add the edge in the opposite direction for undirected graph
    }

    int sd;
    cin >> sd;  // Input the starting node for DFS

    dfs(sd);  // Call DFS starting from the specified node

    // Output the number of nodes not reachable from the starting node
    cout << (n - ans);  

    return 0;  // Indicate that the program ended successfully
}
