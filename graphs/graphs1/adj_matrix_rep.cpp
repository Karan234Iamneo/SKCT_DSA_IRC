#include <iostream>
using namespace std;

class Graph {
   private:
    // 2D array (adjacency matrix) to store the graph
    int** adjMatrix;  
    int numVertices;  // Number of vertices in the graph

   public:
    // Constructor to initialize the adjacency matrix with zeros
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = 0;  // Initialize all values to 0
        }
    }

    // Function to add an edge to the graph
    // i: starting vertex, j: ending vertex, k: weight of the edge
    void addEdge(int i, int j, int k) {
        adjMatrix[i][j] = k;  // Add the edge with the weight k
    }

    // Function to print the adjacency matrix representation of the graph
    void toString() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";  // Print the matrix row by row
            cout << "\n";
        }
    }

    // Destructor to free the dynamically allocated memory
    ~Graph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];  // Delete each row
        delete[] adjMatrix;  // Delete the array of pointers
    }
};

int main() {
    int v, e, a, b, c;
    
    // Input the number of vertices
    cin >> v;
    Graph g(v);  // Create a graph with v vertices
    
    // Input the number of edges
    cin >> e;
    
    string x;
    cin >> x;  // Input whether the graph is directed or undirected
    
    // Loop to add all edges to the graph
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;  // Input the edge (from vertex a to vertex b with weight c)
        
        if (x == "yes") {
            // If the graph is directed, only add one directed edge
            g.addEdge(a - 1, b - 1, c);  // Note: a-1, b-1 to convert to 0-based indexing
        } else {
            // If the graph is undirected, add edges in both directions
            g.addEdge(a - 1, b - 1, c);
            g.addEdge(b - 1, a - 1, c);
        }
    }
    
    // Output the adjacency matrix representation of the graph
    g.toString();
}
