#include<bits/stdc++.h>
using namespace std;

// Function to add an edge between two vertices in an undirected graph
// u: the source vertex
// v: the destination vertex
// adj[]: adjacency list to store edges for each vertex
void addEdge(vector<int> adj[], int u, int v)
{
	// Add v to u's adjacency list since it's an undirected graph
	adj[u].push_back(v);
	
	// Add u to v's adjacency list to maintain the undirected nature
	adj[v].push_back(u);
}

// Function to print the graph in adjacency list representation
// V: total number of vertices
// adj[]: adjacency list storing the graph
void printGraph(vector<int> adj[], int V)
{
	// Traverse through all vertices of the graph
	for (int v = 0; v < V; ++v)
	{
		// Print the current vertex number
		cout << v ;
		
		// Print all adjacent vertices of the current vertex v
		for (int i = 0 ; i < adj[v].size() ; i++)
		    cout << " -> " << adj[v][i];
		
		// Move to the next line after printing all adjacent vertices
		printf("\n");
	}
}

// Driver function to create and print the graph
int main()
{
	int V , a , b ;
  	// Input the number of vertices in the graph
  	cin >> V ;
  	
  	int E ; // E stores the number of edges in the graph
  	cin >> E ;
  	
  	// Declare an array of vectors to act as adjacency list of size V
  	vector<int> adj[V];
  	
  	// Loop to input each edge of the graph
  	for(int i = 0 ; i < E ; i++)
    {
      cin >> a >> b ;  // Input the two vertices that form an edge
      addEdge(adj, a, b);  // Add the edge to the graph
    }
	
	// Call function to print the graph's adjacency list representation
	printGraph(adj, V);
	
	return 0;
}
