#include<iostream>
#include<climits>

using namespace std;

class DijkstraAlgorithm {
    int numNodes, numEdges;
    int* nodeDistances;

public:
    DijkstraAlgorithm(int nodes, int edges) {
        numNodes = nodes;
        numEdges = edges;
        nodeDistances = new int[nodes];
    }

    void calculateShortestPaths(int graph[50][3], int startNode) {
        cout << "Calculating Shortest Paths using Dijkstra's Algorithm..." << endl;

        for (int i = 0; i < numNodes; ++i) {
            nodeDistances[i] = INT_MAX;
        }
        nodeDistances[startNode] = 0;

        for (int iteration = 0; iteration < numNodes - 1; ++iteration) {
            for (int edgeIndex = 0; edgeIndex < numEdges; ++edgeIndex) {
                int sourceNode = graph[edgeIndex][0];
                int destinationNode = graph[edgeIndex][1];
                int edgeWeight = graph[edgeIndex][2];

                if (nodeDistances[sourceNode] != INT_MAX && nodeDistances[sourceNode] + edgeWeight < nodeDistances[destinationNode]) {
                    nodeDistances[destinationNode] = nodeDistances[sourceNode] + edgeWeight;
                }
            }
        }

        for (int edgeIndex = 0; edgeIndex < numEdges; ++edgeIndex) {
            int sourceNode = graph[edgeIndex][0];
            int destinationNode = graph[edgeIndex][1];
            int edgeWeight = graph[edgeIndex][2];

            if (nodeDistances[sourceNode] != INT_MAX && nodeDistances[sourceNode] + edgeWeight < nodeDistances[destinationNode]) {
                cout << "Graph contains negative weight cycle. Unable to find shortest paths." << endl;
                return;
            }
        }

        cout << "Shortest Distances from the Start Node (" << startNode << "):" << endl;
        for (int i = 0; i < numNodes; ++i) {
            if (nodeDistances[i] == INT_MAX) {
                cout << "Node " << i << ": Infinite" << endl;
            } else {
                cout << "Node " << i << ": " << nodeDistances[i] << endl;
            }
        }
    }
};

int main() {
    int nodes = 3;
    int edges = 4;
    int weightedGraph[50][3] = {{0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}};
    int startNode = 2;

    DijkstraAlgorithm dijkstra(nodes, edges);
    
    dijkstra.calculateShortestPaths(weightedGraph, startNode);

    return 0;
}

