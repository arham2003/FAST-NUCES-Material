#include <iostream>

class Task {
public:
    int priority;
    int taskId;

    Task(int priority, int taskId) : priority(priority), taskId(taskId) {}
};

class PriorityQueue {
private:
    Task* heap;
    int capacity;
    int size;

    void heapify(int i);

public:
    PriorityQueue(int capacity);
    ~PriorityQueue();

    void insert(Task task);
    Task extractMax();
    void buildMaxHeap();
    bool isEmpty();
};

PriorityQueue::PriorityQueue(int capacity) {
    this->capacity = capacity;
    this->heap = new Task[capacity];
    this->size = 0;
}

PriorityQueue::~PriorityQueue() {
    delete[] heap;
}

void PriorityQueue::insert(Task task) {
    if (size == capacity) {
        std::cout << "Priority queue is full. Cannot insert more tasks." << std::endl;
        return;
    }

    size++;
    int i = size - 1;
    heap[i] = task;

    while (i != 0 && heap[(i - 1) / 2].priority < heap[i].priority) {
        std::swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Task PriorityQueue::extractMax() {
    if (size <= 0) {
        std::cerr << "Priority queue is empty. Cannot extract task." << std::endl;
        return Task(-1, -1);
    }

    if (size == 1) {
        size--;
        return heap[0];
    }

    Task root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(0);

    return root;
}

void PriorityQueue::buildMaxHeap() {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

void PriorityQueue::heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].priority > heap[largest].priority) {
        largest = left;
    }

    if (right < size && heap[right].priority > heap[largest].priority) {
        largest = right;
    }

    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

bool PriorityQueue::isEmpty() {
    return size == 0;
}

int main() {
    const int numTasks = 10;
    PriorityQueue priorityQueue(numTasks);

    // Insert tasks with random priorities
    for (int i = 0; i < numTasks; i++) {
        int priority = rand() % 10 + 1;  // Random priority between 1 and 10
        priorityQueue.insert(Task(priority, i));
    }

    std::cout << "Tasks before deletion:" << std::endl;
    while (!priorityQueue.isEmpty()) {
        Task task = priorityQueue.extractMax();
        std::cout << "Task ID: " << task.taskId << " Priority: " << task.priority << std::endl;
    }

    return 0;
}

