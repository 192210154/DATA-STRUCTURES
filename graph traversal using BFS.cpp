#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Queue data structure for BFS
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

// Graph data structure
struct Graph {
    int numNodes;
    int adjMatrix[MAX_NODES][MAX_NODES];
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to enqueue an item
void enqueue(struct Queue* queue, int item) {
    if (queue->rear == MAX_NODES - 1)
        printf("Queue is full.\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = item;
    }
}

// Function to dequeue an item
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Function to perform BFS traversal
void BFS(struct Graph* graph, int startNode) {
    struct Queue* queue = createQueue();
    int visited[MAX_NODES] = {0};

    printf("BFS traversal starting from node %d:\n", startNode);

    visited[startNode] = 1;
    enqueue(queue, startNode);

    while (!isEmpty(queue)) {
        int currentNode = dequeue(queue);
        printf("%d ", currentNode);

        for (int i = 0; i < graph->numNodes; i++) {
            if (graph->adjMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    printf("\n");
}

int main() {
    struct Graph graph;
    graph.numNodes = 6;

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            graph.adjMatrix[i][j] = 0;
        }
    }

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 3, 5);
    addEdge(&graph, 4, 5);

    BFS(&graph, 0);

    return 0;
}

