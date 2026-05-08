#include "graph.h"

Graph* create_graph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->num_vertices = vertices;
    g->cities = (City*)malloc(vertices * sizeof(City));
    for (int i = 0; i < vertices; i++) {
        g->cities[i].head = NULL;
        strcpy(g->cities[i].city_name, "");
    }
    return g;
}

void add_city(Graph* g, int index, const char* name) {
    if (index >= 0 && index < g->num_vertices) {
        strcpy(g->cities[index].city_name, name);
    }
}

void add_edge(Graph* g, int src, int dest, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->destination_vertex = dest;
    newEdge->weight = weight;
    newEdge->next = g->cities[src].head;
    g->cities[src].head = newEdge;

    newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->destination_vertex = src;
    newEdge->weight = weight;
    newEdge->next = g->cities[dest].head;
    g->cities[dest].head = newEdge;
}

void bfs_traversal(Graph* g, int start_vertex) {
    bool* visited = (bool*)malloc(g->num_vertices * sizeof(bool));
    for (int i = 0; i < g->num_vertices; i++) visited[i] = false;

    int* queue = (int*)malloc(g->num_vertices * sizeof(int));
    int front = 0, rear = 0;

    visited[start_vertex] = true;
    queue[rear++] = start_vertex;

    printf("\n--- BFS Lojistik Ag Gezinmesi (Baslangic: %s) ---\n", g->cities[start_vertex].city_name);
    while (front < rear) {
        int current = queue[front++];
        printf("Sehir: %-12s (Bellek Adresi: %p)\n", g->cities[current].city_name, (void*)&g->cities[current]);

        Edge* temp = g->cities[current].head;
        while (temp) {
            int adj_vertex = temp->destination_vertex;
            if (!visited[adj_vertex]) {
                visited[adj_vertex] = true;
                queue[rear++] = adj_vertex;
            }
            temp = temp->next;
        }
    }
    printf("--------------------------------------------------\n");
    free(visited);
    free(queue);
}
