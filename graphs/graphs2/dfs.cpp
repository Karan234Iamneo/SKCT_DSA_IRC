#include <iostream>
#include <vector>
using namespace std;

class Traversal {
public:
    // DFS function
    static void dfs(int src, const vector<vector<int>>& adj, vector<bool>& vis) {
        vis[src] = true;  // Mark the current node as visited
        cout << src << " ";  // Print the current node

        // Recur for all the vertices adjacent to this vertex
        for (int v : adj[src]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }
};

int main() {
    int t;  // Number of test cases
    cin >> t;  // Read the number of test cases

    while (t-- > 0) {
        int nov, edg;  // Number of vertices and edges
        cin >> nov >> edg;  // Read number of vertices and edges

        // Create an adjacency list for the graph
        vector<vector<int>> adj(nov);
        
        // Read edges and build the adjacency list
        for (int i = 0; i < edg; i++) {
            int u, v;  // Endpoints of the edge
            cin >> u >> v;  // Read the edge endpoints
            adj[u].push_back(v);  // Add edge u-v
            adj[v].push_back(u);  // Add edge v-u (for undirected graph)
        }

        // Create a visited array to track visited nodes
        vector<bool> vis(nov, false);
        
        // Call DFS starting from vertex 0
        Traversal::dfs(0, adj, vis);
        
        cout << endl;  // New line for the next test case output
    }

    return 0;  // End of program
}
