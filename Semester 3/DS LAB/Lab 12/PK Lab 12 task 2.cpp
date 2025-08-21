#include<iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        this->value = val;
        this->next = NULL;
    }
};

class GraphList {
private:
    int totalNodes;
    Node** nodes;

public:
    GraphList(int totalNodes) {
        this->totalNodes = totalNodes;

        nodes = new Node*[totalNodes];
        for (int i = 0; i < totalNodes; ++i) {
            nodes[i] = NULL;
        }
    }

    void addConnection(int start, int end) {
        Node* newNode = new Node(end);
        newNode->next = nodes[start];
        nodes[start] = newNode;

        newNode = new Node(start);
        newNode->next = nodes[end];
        nodes[end] = newNode;
    }

    void displayGraph() {
        for (int i = 0; i < totalNodes; ++i) {
            cout << "Node " << i << ": ";
            Node* current = nodes[i];
            while (current != NULL) {
                cout << current->value << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int totalNodes = 5;
    int totalConnections = 7;

    int connections[][2] = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};

    GraphList graph(totalNodes);

    for (int i = 0; i < totalConnections; ++i) {
        graph.addConnection(connections[i][0], connections[i][1]);
    }

    cout << "Displaying the Graph:" << endl;
    graph.displayGraph();

    return 0;
}

