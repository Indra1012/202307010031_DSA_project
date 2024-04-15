
//social network analysis using BFS traversal

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph node
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Structure to represent an adjacency list graph
typedef struct Graph {
  int numVertices;
  Node* head[MAX_VERTICES]; // Array of head nodes for adjacency lists
} Graph;

// Function to create a new graph node
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to create a graph with numVertices vertices
Graph* createGraph(int numVertices) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = numVertices;

  // Create an adjacency list for each vertex
  for (int i = 0; i < numVertices; i++) {
    graph->head[i] = NULL;
  }

  return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int source, int destination) {
  // Add an edge from source to destination
  Node* newNode = createNode(destination);
  newNode->next = graph->head[source];
  graph->head[source] = newNode;

  // Since graph is undirected, add an edge from destination to source also
  newNode = createNode(source);
  newNode->next = graph->head[destination];
  graph->head[destination] = newNode;
}

// Function to print the adjacency list representation of a graph
void printGraph(Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; ++v) {
    printf("\n Adjacency list of vertex %d\n head ", v);
    Node* temp = graph->head[v];
    while (temp) {
      printf(" -> %d", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

// Function to perform Breadth-First Search traversal from a given vertex
void BFS(Graph* graph, int startVertex) {
  int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices

  // Create a queue for BFS
  Node* queue[MAX_VERTICES];
  int front = -1;
  int rear = -1;

  // Mark the current node as visited and enqueue it
  visited[startVertex] = 1;
  queue[++rear] = graph->head[startVertex];

  // BFS loop
  while (front != rear) {
    // Dequeue a vertex and print it
    Node* temp = queue[++front];
    printf("%d ", temp->data);

    // Get all adjacent vertices of the dequeued vertex
    while (temp) {
      if (!visited[temp->data]) {
        visited[temp->data] = 1;
        queue[++rear] = graph->head[temp->data];
      }
      temp = temp->next;
    }
  }
}

int main() {
  int numVertices = 6;
  Graph* graph = createGraph(numVertices);

  // Add edges for a social network (replace these with actual connections)
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);

  printf("Adjacency List Representation of Graph\n");
  printGraph(graph);

  printf("\nBreadth First Search Traversal (starting from vertex 0)\n");
  BFS(graph, 0);

  return 0;
}
