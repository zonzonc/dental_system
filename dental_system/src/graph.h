#ifndef GRAPH_H
#define GRAPH_H
#include <stddef.h>
#include <stdbool.h>

typedef struct GraphEdge {
    int to;
    struct GraphEdge *next;
} GraphEdge;

typedef struct {
    GraphEdge **adj;
    size_t n;      /* number of vertices */
} Graph;

Graph *graph_create(size_t vertices);
void   graph_destroy(Graph *g);
bool   graph_add_edge(Graph *g, int u, int v); /* u->v */
void   graph_display(const Graph *g);

#endif /* GRAPH_H */
