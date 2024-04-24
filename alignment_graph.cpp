#include <iostream>
#include <list>
#include <vector>

class Graph {
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency lists

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // To add an edge to the graph
    void printGraph(); // To print the adjacency list representation of the graph
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::printGraph() {
    for (int v = 0; v < V; ++v) {
        std::cout << "Adjacency list of vertex " << v << "\n head ";
        for (auto x : adj[v])
            std::cout << "-> " << x;
        std::cout << std::endl;
    }
}

int main() {
    Graph g(5); // 5 vertices numbered from 0 to 4
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
