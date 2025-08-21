#include<iostream>

using namespace std;

class SimpleQueue {
private:
    static const int MAX_SIZE = 1000; // Set a maximum size for the queue
    int arr[MAX_SIZE];
    int front, rear;

public:
    SimpleQueue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int removedValue = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        return removedValue;
    }
};

class IslandExplorer {
public:
    int countIslands(int map[50][50], int numRows, int numCols) {
        int islandCount = 0;

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (map[i][j] == 1) {
                    exploreIsland(map, i, j, numRows, numCols);
                    islandCount += 1;
                }
            }
        }
        return islandCount;
    }

    void exploreIsland(int map[50][50], int x, int y, int numRows, int numCols) {
        SimpleQueue islandQueue;
        islandQueue.enqueue(x * numCols + y);

        while (!islandQueue.isEmpty()) {
            int currentCell = islandQueue.dequeue();
            int currentX = currentCell / numCols;
            int currentY = currentCell % numCols;

            if (currentX < 0 || currentX >= numRows || currentY < 0 || currentY >= numCols || map[currentX][currentY] != 1)
                continue;

            map[currentX][currentY] = 2; // Marking the island as visited

            // Adding adjacent cells to the queue
            islandQueue.enqueue((currentX + 1) * numCols + currentY);
            islandQueue.enqueue(currentX * numCols + currentY + 1);
            islandQueue.enqueue((currentX - 1) * numCols + currentY);
            islandQueue.enqueue(currentX * numCols + currentY - 1);
            islandQueue.enqueue((currentX + 1) * numCols + currentY + 1);
            islandQueue.enqueue((currentX - 1) * numCols + currentY - 1);
            islandQueue.enqueue((currentX - 1) * numCols + currentY + 1);
            islandQueue.enqueue((currentX + 1) * numCols + currentY - 1);
        }
    }
};

int main() {
    int landMap[50][50] = {{0, 1}, {1, 0}, {1, 1}, {1, 0}};
    int numRows = 4;
    int numCols = 2;

    IslandExplorer islandExplorer;

    int numberOfIslands = islandExplorer.countIslands(landMap, numRows, numCols);

    cout << "Number of Islands: " << numberOfIslands << endl;

    return 0;
}

