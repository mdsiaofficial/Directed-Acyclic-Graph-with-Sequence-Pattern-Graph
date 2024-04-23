#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Representing a vertex in the graph
struct Vertex {
    char label;
    vector<Vertex*> neighbors;
};

// Representing the graph
struct Graph {
    vector<Vertex*> vertices;
    Vertex* start;
    Vertex* end;
};

// Function to create a new vertex
Vertex* createVertex(char label) {
    Vertex* v = new Vertex();
    v->label = label;
    return v;
}

// Function to add an edge between two vertices
void addEdge(Vertex* from, Vertex* to, char edgeLabel) {
    from->neighbors.push_back(to);
}

// Function to traverse the graph according to the pattern
void traverseGraph(Graph* graph, string pattern) {
    Vertex* current = graph->start;
    string path = "";
    for (char c : pattern) {
        bool found = false;
        for (Vertex* neighbor : current->neighbors) {
            if (neighbor->label == c) {
                current = neighbor;
                path += c;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Pattern not found in the graph." << endl;
            return;
        }
    }
    cout << "Traversing path: " << path << endl;
}

int main() {
    // Create the graph
    Graph graph;
    graph.start = createVertex('S');
    Vertex* v0 = createVertex('0');
    Vertex* v1 = createVertex('1');
    Vertex* v2 = createVertex('2');
    Vertex* v3 = createVertex('3');
    graph.end = createVertex('E');
    graph.vertices = {v0, v1, v2, v3};

    addEdge(graph.start, v0, 'a');
    addEdge(v0, v1, 'b');
    addEdge(v1, v3, 'c');
    addEdge(v3, v2, 'd');
    addEdge(v2, graph.end, 'e');

    // Get the pattern from the user
    string pattern;
    cout << "Enter a pattern: ";
    cin >> pattern;

    // Traverse the graph according to the pattern
    traverseGraph(&graph, pattern);

    return 0;
}