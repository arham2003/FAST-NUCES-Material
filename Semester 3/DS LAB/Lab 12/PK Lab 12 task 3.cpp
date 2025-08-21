#include<iostream>

using namespace std;

const int NumNodes = 3;
const int InfiniteValue = 1e9;

int minIndex;

int findMinKeyValue(int key[], bool visited[]) {
    int minKey = InfiniteValue;
    minIndex = -1;

    for (int node = 0; node < NumNodes; ++node) {
        if (!visited[node] && key[node] < minKey) {
            minKey = key[node];
            minIndex = node;
        }
    }
    return minIndex;
}

int displayMinimumSpanningTree(int parent[], int graph[NumNodes][NumNodes]) {
    int totalWeight = 0;
    for (int i = 1; i < NumNodes; ++i) {
        cout << "Selected Edge: " << parent[i] << " - " << i << " with Weight: " << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << endl;
    return totalWeight;
}

void primMinimumSpanningTree(int graph[NumNodes][NumNodes]) {
    int parent[NumNodes];
    int key[NumNodes];
    bool visited[NumNodes];

    for (int i = 0; i < NumNodes; ++i) {
        key[i] = InfiniteValue;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < NumNodes - 1; ++count) {
        int u = findMinKeyValue(key, visited);
        visited[u] = true;

        for (int v = 0; v < NumNodes; ++v) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    int totalWeight = displayMinimumSpanningTree(parent, graph);
}

int main() {
    int weightGraph[NumNodes][NumNodes] = {
        {0, 1, 5},
        {4, 0, 3},
        {5, 3, 0}
    };

    cout << "Applying Prim's Algorithm to find Minimum Spanning Tree:" << endl << endl;
    primMinimumSpanningTree(weightGraph);

    return 0;
}

