#include <iostream>
#include <limits>

using namespace std;

const int NumVertices = 6;
const int MaxValue = numeric_limits<int>::max();

int findMinDistIndex(int dist[], bool visited[]) {
    int minKey = MaxValue;
    int minIndex = -1;

    for (int v = 0; v < NumVertices; ++v) {
        if (!visited[v] && dist[v] < minKey) {
            minKey = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printShortestPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printShortestPath(parent, parent[j]);
    cout << j << " ";
}

void printResult(int dist[], int parent[], int source, int destination) {
    cout << "Shortest Path from " << source << " to " << destination << " with distance " << dist[destination] << " is: " << endl;
    printShortestPath(parent, destination);
    cout << endl;
}

void findShortestPath(int graph[NumVertices][NumVertices], int source, int destination) {
    int dist[NumVertices];
    bool visited[NumVertices];
    int parent[NumVertices];

    for (int i = 0; i < NumVertices; ++i) {
        dist[i] = MaxValue;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[source] = 0;

    for (int count = 0; count < NumVertices - 1; ++count) {
        int u = findMinDistIndex(dist, visited);
        visited[u] = true;

        for (int v = 0; v < NumVertices; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != MaxValue) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    parent[v] = u;
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    printResult(dist, parent, source, destination);
}

int main() {
    int weightGraph[NumVertices][NumVertices] = {
        {0, 1, 0, 5, 0, 0},
        {0, 0, 2, 2, 1, 0},
        {0, 0, 0, 0, 3, 1},
        {0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0}
    };

    int srcNode = 0;
    int destNode = 5;

    findShortestPath(weightGraph, srcNode, destNode);

    return 0;
}

