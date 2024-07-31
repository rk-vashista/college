#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure for topological sorting
struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int value) {
    stack->items[++(stack->top)] = value;
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        return -1;
    }
    return stack->items[(stack->top)--];
}

// Function to perform DFS and push vertices into the stack
void dfs(int v, int visited[], struct Stack* stack, int graph[MAX][MAX], int V) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i, visited, stack, graph, V);
        }
    }
    push(stack, v);
}

// Function to perform topological sort
void topologicalSort(int graph[MAX][MAX], int V) {
    struct Stack stack;
    initStack(&stack);
    int visited[V];
    
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, &stack, graph, V);
        }
    }

    printf("Topological ordering of vertices: ");
    while (stack.top != -1) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(graph, V);

    return 0;
}
