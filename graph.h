#ifndef GRAPH_H
#define GRAPH_H

#include "types.h"

typedef struct Edge {
    int destination_vertex;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    char city_name[MAX_CITY_NAME];
    Edge* head;
} City;

typedef struct {
    int num_vertices;
    City* cities;
} Graph;

Graph* create_graph(int vertices);
void add_city(Graph* g, int index, const char* name);
void add_edge(Graph* g, int src, int dest, int weight);
void bfs_traversal(Graph* g, int start_vertex);

#endif
